/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:29:54 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/02 15:06:57 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_vsprintf(char *dst, const char *format, va_list ap)
{
	size_t		i;
	char		*str;
	t_manager	p;

	str = (char *)format;
	ft_memset(&p, 0, sizeof(t_manager));
	p.sprintf_dst = dst;
	i = -1;
	while (format[++i])
		if (format[i] == '%')
		{
			write_buffer(&p, str, format + i++ - str);
			i += read_flags(&p, ap, format + i);
			if (!p.specifier)
				break ;
			parse(ap, &p);
			str = (char *)format + i + 1;
		}
	write_buffer(&p, str, format + i - str);
	if (p.buffer_idx)
		ft_strncpy(p.sprintf_dst + p.sprintf_dst_idx,
				p.buffer, p.buffer_idx - 1);
	return (p.len);
}

int			ft_sprintf(char *str, const char *format, ...)
{
	int		len;
	va_list	args;

	va_start(args, format);
	len = ft_vsprintf(str, format, args);
	va_end(args);
	return (len);
}
