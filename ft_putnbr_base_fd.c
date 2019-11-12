/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:42:57 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/12 13:48:21 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_u(unsigned long long n, unsigned int *base, int *fd, int *upcase)
{
	char c;

	if (n >= *base)
		ft_u(n / *base, base, fd, upcase);
	c = n % *base + '0';
	if (c > '9')
		c += 39;
	if (*upcase)
		c -= 32;
	write(*fd, &c, 1);
}

int			ft_putnbr_base_fd(long long n, unsigned int base, int fd, int upcase)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		ft_u(-n, &base, &fd, &upcase);
	}
	else
		ft_u(n, &base, &fd, &upcase);
	return (-1000);
	// TODO return len
}

int			conv_p(va_list *args, int fd)
{
	write(fd, "0x", 2);
	return (ft_putnbr_base_fd(va_arg(*args, long long), 16, fd, 0) + 2);
}

int			conv_d(va_list *args, int fd)
{
	return (ft_putnbr_base_fd(va_arg(*args, long long), 10, fd, 0));
}

int			conv_i(va_list *args, int fd)
{
	return (ft_putnbr_base_fd(va_arg(*args, long long), 10, fd, 0));
}

