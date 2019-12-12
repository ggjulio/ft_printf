/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:14:57 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/12 14:19:08 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_bits(int wc)
{
	int n;

	n = 0;
	while (wc)
	{
		wc = wc >> 1;
		n++;
	}
	return (n);
}

int	get_size_octet(uint16_t nb_bits)
{
	if (nb_bits <= 7)
		return (1);
	if (nb_bits <= 11)
		return (2);
	if (nb_bits <= 16)
		return (3);
	return (4);
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
	write_buffer(p, &c, get_size_octet(count_bits(c)));
	if (F_DASH & p->flags)
		while (--p->width > 0)
			write_buffer(p, " ", 1);
}
