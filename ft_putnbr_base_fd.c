/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:42:57 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/12 16:44:55 by juligonz         ###   ########.fr       */
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
	{
		if (*upcase)
			c += 7;
		else
			c += 39;
	}
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
