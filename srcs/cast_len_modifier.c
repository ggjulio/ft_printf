/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_len_modifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:52:15 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/18 16:52:34 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	cast_d_i(t_manager *p, va_list *args)
{
	if (GET(F_HH))
		return ((signed char)va_arg(*args, int));
	if (GET(F_H))
		return ((short)va_arg(*args, long long));
	if (GET(F_L))
		return (va_arg(*args, long));
	if (GET(F_LL))
		return (va_arg(*args, long long));
	return (va_arg(*args, int));
}

long long	cast_u_x_x(t_manager *p, va_list *args)
{
	if (GET(F_HH))
		return ((unsigned char)va_arg(*args, unsigned int));
	if (GET(F_H))
		return ((unsigned short)va_arg(*args, unsigned long long));
	if (GET(F_L))
		return (va_arg(*args, long));
	if (GET(F_LL))
		return (va_arg(*args, long long));
	return (va_arg(*args, unsigned int));
}

