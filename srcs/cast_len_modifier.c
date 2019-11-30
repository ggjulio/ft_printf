/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_len_modifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:52:15 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/30 15:30:46 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int64_t		cast_signed(t_manager *p, va_list *args)
{
	if (F_HH & p->flags)
		return ((char)va_arg(*args, int));
	if (F_H & p->flags)
		return ((short)va_arg(*args, int));
	if (F_L & p->flags)
		return (va_arg(*args, long));
	if (F_LL & p->flags)
		return (va_arg(*args, long long));
	return (va_arg(*args, int));
}

uint64_t	cast_unsigned(t_manager *p, va_list *args)
{
	if (F_HH & p->flags)
		return ((unsigned char)va_arg(*args, unsigned int));
	if (F_H & p->flags)
		return ((unsigned short)va_arg(*args, unsigned int));
	if (F_L & p->flags)
		return (va_arg(*args, unsigned long));
	if (F_LL & p->flags)
		return (va_arg(*args, unsigned long long));
	return (va_arg(*args, unsigned int));
}

void		*cast_ptr(t_manager *p, va_list *args)
{
	if (F_HH & p->flags)
		return ((char *)va_arg(*args, int *));
	if (F_H & p->flags)
		return ((short *)va_arg(*args, int *));
	if (F_L & p->flags)
		return (va_arg(*args, long *));
	if (F_LL & p->flags)
		return (va_arg(*args, long long *));
	return (va_arg(*args, int *));
}
