/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:10:29 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/02 12:10:43 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_vdprintf(int fd, const char *format, va_list ap)
{
	va_list		args;
	size_t		i;
	char		*str;
	t_manager	p;

	str = (char *)format;
	ft_memset(&p, 0, sizeof(t_manager));
	p.fd = fd;
	i = -1;
	va_copy(args, ap);
	while (format[++i])
		if (format[i] == '%')
		{
			write_buffer(&p, str, format + i++ - str);
			i += read_flags(&p, args, format + i);
			if (!p.specifier)
				break ;
			parse(args, &p);
			str = (char *)format + i + 1;
		}
	write_buffer(&p, str, format + i - str);
	if (p.buffer_idx)
		write(p.fd, p.buffer, p.buffer_idx);
	va_end(args);
	return (p.len);
}

int			ft_dprintf(int fd, const char *format, ...)
{
	int		len;
	va_list	args;

	va_start(args, format);
	len = ft_vdprintf(fd, format, args);
	va_end(args);
	return (len);
}
