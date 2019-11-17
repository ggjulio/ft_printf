/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:42:57 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/17 19:13:45 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_mod(va_list *args, t_manager *p)
{
	char c;

	(void)args;
	c = (GET(F_ZERO) ? '0' : ' ');
	if (!GET(F_DASH))
		while (--p->width > 0)
			write_buffer(p, &c, 1);
	write_buffer(p, "%", 1);
	if (GET(F_DASH))
		while (--p->width > 0)
			write_buffer(p, " ", 1);
}
