/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:57:19 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/15 14:59:10 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static int read_flags(t_manager *p, const char *format)
{
//	const char *conv = "cspdiuxXnfge%";
//	const char c_flags[12][3]  = {"-", "0", ".", "*", "l", "ll", "h","hh", "'", "#", " ", "+"};
//	const char c_flags[12][3]  = {   ,    ,    ,    , "l", "ll", "h","hh", "'", "#", " ",     };
	size_t i;

	p->flags = 0;
	p->width = 0;
	i = 0;
	while (1)
	{
		if (format[i] == '-')
			p->flags ^= F_DASH;
		else if (format[i] == '+')
			p->flags |= F_PLUS; 
		else if (format[i] == '0')
			p->flags |= F_ZERO; 
		else if (format[i] >= '1' && format[i] <= '9')
			p->width = (p->width * 10) + format[i] - '0';
		else if (format[i] == '.')
			p->flags |= F_DOT;  
		else if (format[i] == '*')
			p->flags |= F_STAR; 
		else
		{
			p->specifier = format[i++];
			return (i);
		}
		i++;
	}
}

static int parse(va_list *args, t_manager *p)
{
	const char *conv = "cspdiuxXnfge%";
	const handler jmp_table[13] ={conv_c, 
								  conv_s, 
								  conv_p, 
								  conv_d, 
								  conv_i,
								  conv_u,
								  conv_x_lowcase,
								  conv_x_upcase,
								  NULL,
								  NULL,
								  NULL,
								  NULL,
								  conv_mod}; 
	int i;

	i = -1;
	while (conv[++i])
		if (conv[i] == p->specifier)
			return (jmp_table[i](args, p));
	return (0);
}

void		write_buffer(t_manager *p, char *s, size_t n)
{
	int i;

	i = 0;
	while (n--)
	{
		if (p->buffer_idx== BUFFER_SIZE)
		{
			write(p->fd, p->buffer, BUFFER_SIZE);
			p->buffer_idx = 0;			
		}
		p->buffer[p->buffer_idx++] = s[i++];
	}
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		len;
	char	*str;
	short	flags;
	t_manager p;
	
	(void)flags;
	va_start(args, format);
	i = -1;
	len = 0;
	str = (char *)format;
	p.fd = 1;
	p.buffer_idx = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			write_buffer(&p, str, format + i - str);
			i++;
			i += read_flags(&p, format + i);
			if (F_STAR & p.flags)
				p.width = va_arg(args, int);
			len += parse(&args, &p);
			str = (char *)format + i;
		}
	}
	write_buffer(&p, str, format + i - str);
	if (p.buffer_idx != 0) // debug
		write(1, p.buffer, p.buffer_idx);

	va_end(args);
	return (len);
}
