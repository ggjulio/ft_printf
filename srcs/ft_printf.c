/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:57:19 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/01 18:54:20 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	parse(va_list *args, t_manager *p)
{
	const char		*conv = "cspdiuxXnfgeo%";
	const t_handler	jmp_table[14] = {conv_c,
									conv_s,
									conv_p,
									conv_d,
									conv_i,
									conv_u,
									conv_x_lowcase,
									conv_x_upcase,
									conv_n,
									conv_f,
									conv_g,
									conv_e,
									conv_o,
									conv_mod};
	int				i;

	i = -1;
	while (conv[++i])
		if (conv[i] == p->specifier)
			jmp_table[i](args, p);
}

int			ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		i;
	char		*str;
	t_manager	p;

	str = (char *)format;
	ft_memset(&p, 0, sizeof(t_manager));
	p.fd = 1;
	i = -1;
	va_start(args, format);
	while (format[++i])
		if (format[i] == '%')
		{
			write_buffer(&p, str, format + i++ - str);
			i += read_flags(&p, &args, format + i);
			if (!p.specifier)
				break ;
			parse(&args, &p);
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
	va_list		args;
	size_t		i;
	char		*str;
	t_manager	p;

	str = (char *)format;
	ft_memset(&p, 0, sizeof(t_manager));
	p.fd = fd;
	i = -1;
	va_start(args, format);
	while (format[++i])
		if (format[i] == '%')
		{
			write_buffer(&p, str, format + i++ - str);
			i += read_flags(&p, &args, format + i);
			if (!p.specifier)
				break ;
			parse(&args, &p);
			str = (char *)format + i + 1;
		}
	write_buffer(&p, str, format + i - str);
	if (p.buffer_idx)
		write(p.fd, p.buffer, p.buffer_idx);
	va_end(args);
	return (p.len);
}
