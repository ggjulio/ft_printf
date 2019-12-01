/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:15:58 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/01 19:03:15 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		put_width(t_manager *p, int nb_char)
{
	int	i;

	i = p->width;
	while (i > p->precision && i > nb_char)
	{
		write_buffer(p, " ", 1);
		i--;
	}
}

static void		put_ptr(unsigned long long n, t_manager *p, int *nb_digit)
{
	char c;

	(*nb_digit)++;
	c = n % 16 + '0';
	if (c > '9')
		c += 39;
	if (n >= 16)
		put_ptr(n / 16, p, nb_digit);
	else
	{
		if (c == '0' && *nb_digit == 1 && (F_DOT & p->flags)
			&& p->precision == 0)
			*nb_digit = 0;
		p->width -= 2;
		if (F_DASH & ~p->flags)
			put_width(p, *nb_digit);
		write_buffer(p, "0x", 2);
		if (*nb_digit)
			write_buffer(p, &c, 1);
		return ;
	}
	write_buffer(p, &c, 1);
}

void			conv_p(va_list args, t_manager *p)
{
	int nb_digit;

	nb_digit = 0;
	put_ptr(va_arg(args, unsigned long), p, &nb_digit);
	if (F_DASH & p->flags)
		put_width(p, nb_digit);
}
