/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_len_modifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:52:15 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/04 21:06:31 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <inttypes.h>

int64_t		cast_signed(t_manager *p, va_list args)
{
	if (F_HH & p->flags)
		return ((char)va_arg(args, int));
	if (F_H & p->flags)
		return ((short)va_arg(args, int));
	if (F_L & p->flags)
		return (va_arg(args, long));
	if (F_LL & p->flags)
		return (va_arg(args, long long));
	if (F_J & p->flags)
		return (va_arg(args, intmax_t));
	return (va_arg(args, int));
}

uint64_t	cast_unsigned(t_manager *p, va_list args)
{
	if (F_HH & p->flags)
		return ((unsigned char)va_arg(args, unsigned int));
	if (F_H & p->flags)
		return ((unsigned short)va_arg(args, unsigned int));
	if (F_L & p->flags)
		return (va_arg(args, unsigned long));
	if (F_LL & p->flags)
		return (va_arg(args, unsigned long long));
	if (F_J & p->flags)
		return (va_arg(args, uintmax_t));
	return (va_arg(args, unsigned int));
}

void		*cast_ptr(t_manager *p, va_list args)
{
	if (F_HH & p->flags)
		return ((char *)va_arg(args, int *));
	if (F_H & p->flags)
		return ((short *)va_arg(args, int *));
	if (F_L & p->flags)
		return (va_arg(args, long *));
	if (F_LL & p->flags)
		return (va_arg(args, long long *));
	return (va_arg(args, int *));
}

wint_t		cast_c(t_manager *p, va_list args)
{
	if (F_L & p->flags)
		return (va_arg(args, wint_t));
	return (va_arg(args, int));
}

wchar_t		*cast_s(t_manager *p, va_list args)
{
	if (F_L & p->flags)
		return (va_arg(args, wchar_t *));
	return ((wchar_t *)va_arg(args, char *));
}

