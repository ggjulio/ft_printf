/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:00:49 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/22 13:06:23 by juligonz         ###   ########.fr       */
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

static void		put_precision(t_manager *p, int nb_char)
{
	int	i;

	if (GET(F_ZERO) && !GET(F_DOT))
		i = p->width;
	else
		i = p->precision;
	while (i > nb_char)
	{
		write_buffer(p, "0", 1);
		i--;
	}
}

void			ft_putu_x_x(uint64_t n, t_manager *p, int *nb_digit)
{
	char c;

	(*nb_digit)++;
	c = n % 16 + '0';
	if (c > '9')
		c += (p->specifier == 'X' ? 7 : 39);
	if (n >= 16)
		ft_putu_x_x(n / 16, p, nb_digit);
	else
	{
		if (c == '0' && *nb_digit == 1 && GET(F_DOT) && p->precision == 0)
			(*nb_digit) = 0;
		if (GET(F_HASH) && *nb_digit > 0 && c != '0')
			p->width -= 2;
		if (!GET(F_DASH) && (!GET(F_ZERO) || GET(F_DOT)))
			put_width(p, *nb_digit);
		if ((GET(F_HASH) && *nb_digit > 0 && c != '0'))
			write_buffer(p, (p->specifier == 'X' ? "0X" : "0x"), 2);
		put_precision(p, *nb_digit);
		if (*nb_digit != 0 || !GET(F_DOT) || p->precision != 0)
			write_buffer(p, &c, 1);
		return ;
	}
	write_buffer(p, &c, 1);
}

void			ft_put_x_x(int64_t n, t_manager *p)
{
	int nb_digit;

	nb_digit = 0;
	ft_putu_x_x(n, p, &nb_digit);
	if (GET(F_DASH))
		put_width(p, nb_digit);
}
