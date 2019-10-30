/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:57:19 by juligonz          #+#    #+#             */
/*   Updated: 2019/10/30 19:22:20 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_putstr(char const *s)
{
	int	len;

	write(1, s, (len = ft_strlen(s)));
	return (len);
}
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	size_t	len;

	va_start(args, format);
	i = -1;
	len = 0;
	while (format[++i])
	{
		if (format[i] != '%')
		{
			ft_putchar(format[i]);
			len++;
		}
		else if (format[++i] == 's')  
		{
			len += ft_putstr(va_arg(args, char*));
		}
		printf("|||%zu|||", i);
	}
	va_end(args);
	return (i);
}
