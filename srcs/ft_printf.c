/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:57:19 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/20 15:59:38 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		debug_flags(t_manager *p)
{
	printf("|#|#|#|#|#|#|#|#|#|#|# FLAGS #|#|#|#|#|#|#|#|#|#|#|#|\n");
	printf("test  : %u || ", !(F_DASH & p->flags));
	printf("DASH  : %d || ", F_DASH & p->flags);
	printf("ZERO  : %d || ", F_ZERO & p->flags);
	printf("DOT   : %d || ", F_DOT & p->flags);
	printf("STAR  : %d || ", F_STAR & p->flags);
	printf("PLUS  : %d\n", F_PLUS & p->flags);
	printf("L     : %d || ", F_LL & p->flags);
	printf("LL    : %d || ", F_LL & p->flags);
	printf("H     : %d || ", F_H & p->flags);
	printf("HH    : %d\n", F_HH & p->flags);
	printf("-----------------------\n");
	printf("width : %d || ", p->width);
	printf("precision : %d\n", p->precision);
	printf("|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|\n");
}

static void	parse(va_list *args, t_manager *p)
{
	const char		*conv = "cspdiuxXnfge%";
	const handler	jmp_table[13] = {conv_c,
									conv_s,
									conv_p,
									conv_d,
									conv_i,
									conv_u,
									conv_x_lowcase,
									conv_x_upcase,
									conv_n,
									NULL,
									NULL,
									NULL,
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
//			debug_flags(&p);
			if (!p.specifier)
				break ;
			parse(&args, &p);
			str = (char *)format + i + 1;
		}
	write_buffer(&p, str, format + i - str);
	if (p.buffer_idx)
		write(1, p.buffer, p.buffer_idx);
	va_end(args);
	return (p.len);
}
