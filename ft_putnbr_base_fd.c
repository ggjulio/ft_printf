/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:42:57 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/14 14:44:02 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_u(unsigned long long n, unsigned int *base, t_manager p)
{
	char c;

	if (n >= *base)
		ft_u(n / *base, base, p);
	c = n % *base + '0';
	if (c > '9')
	{
		if (p->specifier == 'X')
			c += 7;
		else if (p->specifier == 'x')
			c += 39;
	}
	write(p->fd, &c, 1);
}

int			ft_putnbr_base_fd(long long n, unsigned int base, t_manager p)
{
	if (n < 0)
	{
		write(fd, "-", 1);
		ft_u(-n, &base, p);
	}
	else
		ft_u(n, &base, p);
	return (-1000);
}
