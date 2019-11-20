/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_len_modifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:52:15 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/20 12:59:32 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	cast_signed(t_manager *p, va_list *args)
{
	if (GET(F_HH))
		return ((char)va_arg(*args, int));
	if (GET(F_H))
		return ((short)va_arg(*args, long long));
	if (GET(F_L))
		return (va_arg(*args, long));
	if (GET(F_LL))
		return (va_arg(*args, long long));
	return (va_arg(*args, int));
}

unsigned long long	cast_unsigned(t_manager *p, va_list *args)
{
	if (GET(F_HH))
		return ((unsigned char)va_arg(*args, unsigned int));
	if (GET(F_H))
		return ((unsigned short)va_arg(*args, unsigned long long));
	if (GET(F_L))
		return (va_arg(*args, unsigned long));
	if (GET(F_LL))
		return (va_arg(*args, unsigned long long));
	return (va_arg(*args, unsigned int));
}
/*
long long	cast_n(t_manager *p, va_list *args)
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
*/
