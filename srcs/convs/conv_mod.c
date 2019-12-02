/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_mod.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:42:57 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/02 16:09:07 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_mod(va_list args, t_manager *p)
{
	char c;

	(void)args;
	c = (F_ZERO & p->flags ? '0' : ' ');
	if (F_DASH & ~p->flags)
		while (--p->width > 0)
			write_buffer(p, &c, 1);
	write_buffer(p, "%", 1);
	if (F_DASH & p->flags)
		while (--p->width > 0)
			write_buffer(p, " ", 1);
}
