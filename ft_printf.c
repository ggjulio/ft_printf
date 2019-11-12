/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:57:19 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/12 14:01:30 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
static long long	flags(short flags, char *format)
{
	int i;

	i = -1;
	while (++i )
		
}
*/

static int parse(const char c, va_list *args, int fd)
{
	const char *conv = "cspdiuxXnfge%";
	handler jmp_table[113] ={conv_c, 
							 ft_putstr_fd, 
							 conv_p, 
							 conv_d, 
							 conv_i,
							 conv_u,
							 conv_x,
							 conv_X,
							 NULL,
							 NULL,
							 NULL,
							 NULL,
							 conv_mod}; // define in const ? 
	int i;

	i = -1;
	while (conv[++i])
		if (conv[i] == c)
			return (jmp_table[i](args, fd));
	return (0);
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
//			flags(&flags, format);
			len += ft_putstr_range(str, format + i++);
			len += parse(format[i++], &args, 1);
			str = (char *)format + i;
		}
	}
	if (str != format + i)
			len += ft_putstr_range(str, format + i++);
	va_end(args);
	return (len);
}
