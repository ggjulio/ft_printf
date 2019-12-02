/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:57:19 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/02 16:04:53 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_vprintf(const char *format, va_list ap)
{
	size_t		i;
	char		*str;
	t_manager	p;

	str = (char *)format;
	ft_memset(&p, 0, sizeof(t_manager));
	p.fd = 1;
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
		write(p.fd, p.buffer, p.buffer_idx);
	return (p.len);
}

int			ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = ft_vprintf(format, ap);
	va_end(ap);
	return (len);
}
