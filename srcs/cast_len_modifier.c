/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_len_modifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:52:15 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/23 22:53:50 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int64_t			cast_signed(t_manager *p, va_list *args)
{
	if (GET(F_HH))
		return ((char)va_arg(*args, int));
	if (GET(F_H))
		return ((short)va_arg(*args, int));
	if (GET(F_L))
		return (va_arg(*args, long));
	if (GET(F_LL))
		return (va_arg(*args, long long));
	return (va_arg(*args, int));
}

uint64_t	cast_unsigned(t_manager *p, va_list *args)
{
	if (GET(F_HH))
		return ((unsigned char)va_arg(*args, unsigned int));
	if (GET(F_H))
		return ((unsigned short)va_arg(*args, unsigned int));
	if (GET(F_L))
		return (va_arg(*args, unsigned long));
	if (GET(F_LL))
		return (va_arg(*args, unsigned long long));
	return (va_arg(*args, unsigned int));
}

void				*cast_ptr(t_manager *p, va_list *args)
{
	if (GET(F_HH))
		return ((char *)va_arg(*args, int *));
	if (GET(F_H))
		return ((short *)va_arg(*args, int *));
	if (GET(F_L))
		return (va_arg(*args, long *));
	if (GET(F_LL))
		return (va_arg(*args, long long *));
	return (va_arg(*args, int *));
}
