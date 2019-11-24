/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_oct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:26:02 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/24 18:52:25 by juligonz         ###   ########.fr       */
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

static void		put_precision(t_manager *p, int nb_char, char c)
{
	int	i;

	if (GET(F_ZERO) && !GET(F_DOT))
		i = p->width;
	else
		i = (GET(F_HASH) && c != '0' ? p->precision - 1 : p->precision);
	while (i > nb_char)
	{
		write_buffer(p, "0", 1);
		i--;
	}
}

void			put_uoct(uint64_t n, t_manager *p, int *nb_digit)
{
	char c;

	(*nb_digit)++;
	c = n % 8 + '0';
	if (n >= 8)
		put_uoct(n / 8, p, nb_digit);
	else
	{
		if (c == '0' && *nb_digit == 1 && GET(F_DOT) && p->precision == 0)
			(*nb_digit) = 0;
		if (GET(F_HASH) && c != '0')
			p->width -= 1;
		if (!GET(F_DASH) && (!GET(F_ZERO) || GET(F_DOT)))
			put_width(p, *nb_digit);
		if (GET(F_HASH) && c != '0')
			write_buffer(p, "0", 1);
		put_precision(p, *nb_digit, c);
		if (*nb_digit != 0 || !GET(F_DOT) || p->precision != 0)
			write_buffer(p, &c, 1);
		return ;
	}
	write_buffer(p, &c, 1);
}

void			put_oct(int64_t n, t_manager *p)
{
	int nb_digit;

	nb_digit = 0;
	put_uoct(n, p, &nb_digit);
	if (GET(F_DASH))
		put_width(p, nb_digit);
}
