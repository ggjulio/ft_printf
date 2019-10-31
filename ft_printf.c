/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:57:19 by juligonz          #+#    #+#             */
/*   Updated: 2019/10/31 16:55:29 by juligonz         ###   ########.fr       */
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

static int	ft_putchar_fd(unsigned char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

static	int	ft_putstr_range(char const *s_begin, char const *s_end)
{
	int	n;

	n = s_end - s_begin;
	write(1, s_begin, n);
	return (n);
}
static	int			ft_putstr(char const *s)
{
	int     len;

	write(1, s, (len = ft_strlen(s)));
	return (len);
	// modify to return ssize_t from write
}

#include <stdio.h>
//cspdiuxX

/*
static long long	modifier(long long)
{

}*/

static void	ft_putnbru_base_fd(unsigned long long n, unsigned int *base, int *fd)
{
	char c;

	if (n >= *base)
		ft_putnbru_base_fd(n / *base, base, fd);
	c = n % *base + '0';
	if (c > '9')
		c += 39;
	ft_putchar_fd(c, *fd);
}

int		ft_putnbr_base_fd(long long n, unsigned int base, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbru_base_fd(-n, &base, &fd);
	}
	else
		ft_putnbru_base_fd(n, &base, &fd);
	return (-1000); // TODO return len
}

static int	parse(const char c, va_list *args)
{
	if (c == 'c')
		return (ft_putchar_fd(va_arg(*args, int), 1));
	if (c == 's')
		return (ft_putstr(va_arg(*args, char*)));
	if (c == 'p')
	{
		ft_putstr("0x");		
		return (ft_putnbr_base_fd(va_arg(*args, long long), 16, 1) + 2);
	}
	if (c == 'd')
		return (ft_putnbr_base_fd(va_arg(*args, long long), 10, 1));
	if (c == 'i')
		return (0);
	if (c == 'u')
		return (0);
	if (c == 'x')
		return (0);
	if (c == 'X')
		return (0);
	if (c == '%')
		return (ft_putchar_fd('%',1));
	return (0);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int		len;
	char	*str;
	char	flags;

	(void)flags;
	va_start(args, format);
	i = -1;
	len = 0;
	str = (char *)format;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			//flags call
			len += ft_putstr_range(str, format + i++);
			len += parse(format[i++], &args);
			str = (char *)format + i;
		}
	}
	if (str != format + i)
			len += ft_putstr_range(str, format + i++);
	va_end(args);
	return (len);
}
