/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:57:19 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/16 19:36:53 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

#include <stdio.h>

void debug_flags(t_manager *p)
{
	printf("|#|#|#|#|#|#|#|#|#|#|# FLAGS #|#|#|#|#|#|#|#|#|#|#|#|\n");
	printf("test  : %u || ", !(F_DASH & p->flags));
	printf("DASH  : %d || ", F_DASH & p->flags);
	printf("ZERO  : %d || ", F_ZERO & p->flags);
	printf("DOT   : %d || ", F_DOT  & p->flags);
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

static void read_len_specifier(t_manager *p, const char *format, size_t *i)
{
	if (format[*i] == 'l' && ++(*i))
	{
		p->flags |= (format[*i] == 'l' ? F_LL : F_L);
		if (F_LL & p->flags)
			(*i)++;
	}
	else if (format[*i] == 'h' && ++(*i))
	{
		p->flags |= (format[*i] == 'h' ? F_HH : F_H);
		if (F_HH & p->flags)
			(*i)++;
	}
}

static int read_flags(t_manager *p, va_list *args, const char *format)
{
//	const char c_flags[12][3]  = {"-", "0", ".", "*", "l", "ll", "h","hh", "'", "#", " ", "+"};
//	const char c_flags[12][3]  = {   ,    ,    ,    , "l", "ll", "h","hh", "'", "#",    ,     };
	size_t i;

	p->flags = 0;
	p->width = 0;
	p->precision = 0;
	p->specifier = 0;
	i = 0;
	while (!p->specifier)
	{
		read_len_specifier(p, format, &i);
		if (format[i] == '-' && ++i)
			p->flags |= F_DASH;
		else if (format[i] == '+' && ++i)
			p->flags |= F_PLUS; 
		else if (format[i] == ' ' && ++i)
			p->flags |= F_SPACE; 
		else if (format[i] == '0' && ++i)
			p->flags |= F_ZERO; 
		else if (is_digit(format[i]))
			while (is_digit(format[i]))
				p->width = (p->width * 10) + format[i++] - '0';
		else if (format[i] == '.' && ++i)
		{
			p->flags |= F_DOT;  
			if (format[i] == '*' && ++i)
				p->precision = va_arg(*args, int);
			else 
				while (is_digit(format[i]))
					p->precision = (p->precision * 10) + format[i++] - '0';
		}
		else if (format[i] == '*' && ++i)
		{
			if ((p->width = va_arg(*args, int)) < 0)
			{
				p->flags |= F_DASH;
				p->width = -(p->width);
			}
			p->flags |= F_STAR;
		}
		else
			p->specifier = format[i++];
	}
	return (i);
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
		if (p->buffer_idx == BUFFER_SIZE)
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
			i += read_flags(&p, &args, format + i);
//			debug_flags(&p);
			len += parse(&args, &p);
			str = (char *)format + i;
			if (!format[i])
				break;
		}
	}
	write_buffer(&p, str, format + i - str);
	if (p.buffer_idx)
		write(1, p.buffer, p.buffer_idx);
	va_end(args);
	return (len);
}
