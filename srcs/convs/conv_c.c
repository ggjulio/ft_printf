/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:14:57 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/12 12:00:24 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int b(int c_uni)
{
	int count_b;

	count_b = 0;
	while (c_uni)
	{
		c_uni = c_uni >> 1;
		count_b++;
	}
	return (count_b);
}

int	a(int bits_amount)
{
	if (bits_amount <= 7)
		return (1);
	else if (bits_amount > 7 && bits_amount <= 11)
		return (2);
	else if (bits_amount > 11 && bits_amount <= 16)
		return (3);
	else if (bits_amount > 16)
		return (4);
	else
		return (0);
}

void		conv_c(va_list args, t_manager *p)
{
	int 	c;

	c = va_arg(args, int);
	if (F_DASH & ~p->flags)
		while (--p->width > 0)
			write_buffer(p, " ", 1);
	if (c > 255) 
		p->is_error = 1;
	if (F_FLOAT_L & p->flags)
	write_buffer(p, &c, a(b(c)));
	if (F_DASH & p->flags)
		while (--p->width > 0)
			write_buffer(p, " ", 1);
}
