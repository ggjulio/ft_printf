/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:59:07 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/22 16:04:44 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	read_flags_norm(t_manager *p, const char *format, size_t *i)
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

int			read_flags(t_manager *p, va_list *args, const char *format)
{
	size_t i;

	p->flags = 0;
	p->width = 0;
	p->precision = 0;
	i = 0;
	while (1)
	{
		read_flags_norm(p, format, &i);
		if (format[i] == '-' && ++i)
		{
			p->flags |= F_DASH;
			p->flags &= ~(F_ZERO);
		}
		else if (format[i] == '+' && ++i)
			p->flags |= F_PLUS;
		else if (format[i] == ' ' && ++i)
			p->flags |= F_SPACE;
		else if (format[i] == '0' && !GET(F_DASH) && ++i)
			p->flags |= F_ZERO;
		else if (format[i] == '#' && ++i)
			p->flags |= F_HASH;
		else if (format[i] == '\'' && ++i)
			p->flags |= F_APOSTROPHE;
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
			if ((p->width = va_arg(*args, size_t)) < 0)
			{
				p->flags |= F_DASH;
				p->width = -(p->width);
				p->flags &= ~(F_ZERO);
			}
			p->flags |= F_STAR;
		}
		else if (format[i] == 'L') //remove after
			i++;
		else
		{
			p->specifier = format[i];
			return (i);
		}
	}
}
