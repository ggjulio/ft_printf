/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:14:57 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/17 19:14:59 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_c(va_list *args, t_manager *p)
{
	char c;

	c = va_arg(*args, int);
	if (!GET(F_DASH))
		while (--p->width > 0)
			write_buffer(p, " ", 1);
	write_buffer(p, &c, 1);
	if (GET(F_DASH))
		while (--p->width > 0)
			write_buffer(p, " ", 1);
}
