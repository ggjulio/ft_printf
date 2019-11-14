/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:57:19 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/14 14:52:26 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
static int	is_flag(char flag, )
{

}
*/

 
static int read_flags(short *flags, const char *format)
{
//	const char *conv = "cspdiuxXnfge%";
//	const char c_flags[12][3]  = {"-", "0", ".", "*", "l", "ll", "h","hh", "'", "#", " ", "+"};
	size_t i;

	*flags = 0;
	i = -1;
	while (1)
	{
		if (format[i] == '-')
			*flags = ~(*flags & F_DASH);
		else if (format[i] == '+')
			*flags |= F_PLUS; 
		else if (format[i] == '0')
			*flags |= F_ZERO; 
		else if (format[i] == '.')
			*flags |= F_DOT;  
		else if (format[i] == '*')
			*flags |= F_STAR; 
		else
			return (i);
		i++;
	}
}

static int parse(const char c, va_list *args, t_manager p)
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
		if (conv[i] == c)
			return (jmp_table[i](args, p));
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		len;
	char	*str;
	short	flags; //
	char	specifier; //
	t_manager p;
	
	(void)flags;
	va_start(args, format);
	i = -1;
	len = 0;
	str = (char *)format;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i += read_flags(&flags, format);
			len += ft_putstr_range(str, format + i);
			specifier = format[i++];
			len += parse(specifier, &args, p);
			str = (char *)format + i;
		}
	}
	if (str != format + i)
			len += ft_putstr_range(str, format + i++);
	va_end(args);
	return (len);
}
