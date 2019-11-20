/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:15:12 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/20 19:12:00 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_s(va_list *args, t_manager *p)
{
	char	*s;
	int		len;

	s = va_arg(*args, char*);
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	len = (GET(F_DOT) && p->precision < len  && p->precision >= 0 ? p->precision : len);
	p->width -= len;
	if (!GET(F_DASH))
		while (p->width-- > 0)
			write_buffer(p, " ", 1);
	write_buffer(p, s, len);
	if (GET(F_DASH))
		while (p->width-- > 0)
			write_buffer(p, " ", 1);
}
