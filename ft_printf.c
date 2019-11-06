/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:57:19 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/06 18:26:28 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

static int parse(const char c, va_list *args)
{
	
	while ( )
}

static long long	flags(short flags, char *format)
{
	const char *convs = "cspdiux%Xnfge";
	int i;

	i = 0;
	while ()
	{

	}
	
}


int			ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		len;
	char	*str;
	short	flags;

	(void)flags;
	va_start(args, format);
	i = -1;
	len = 0;
	str = (char *)format;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			flags(&flags, format);
			len += ft_putstr_range(str, format + i++);
			len += parse(format[i++], &args);
			str = (char *)format + i;
		}
	}
	if (str != format + i)
			len += ft_putstr_range(str, format + i++);
	va_end(args);
	return (len);
}
