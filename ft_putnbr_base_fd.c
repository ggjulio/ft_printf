/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:42:57 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/15 19:30:43 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_width(t_manager *p, int n)
{
	char c = (((F_ZERO | F_DOT) & p->flags) ? '0' : ' ');
	
	while (n-- > 0)
	{
		write_buffer(p, &c, 1);
//		p->width--;
	}
}

/*
static void	ft_u(unsigned long long n, unsigned int *base, t_manager *p, int idx)
{
	char c;

	if (n >= *base)
		ft_u(n / *base, base, p, idx + 1);
	else if (p->width != 0)
	{
		if (!(F_DASH & p->flags))
			put_width(p, p->width - idx);
		else
			p->width = p->width - idx;
	}
	c = n % *base + '0';
	if (c > '9')
		c += (p->specifier == 'X' ? 7 : 39);
	write_buffer(p, &c, 1);
}

int			ft_putnbr_base_fd(long long n, unsigned int base, t_manager *p)
{
	if (n < 0 && p->specifier != 'p')
	{
		write_buffer(p, "-", 1);
		p->width--;
		ft_u(-n, &base, p, 1);
	}
	else
		ft_u(n, &base, p, 1);
	if ((F_DASH & p->flags))
		put_width(p, p->width);
	return (-1000); // to do
}
*/

#define MAX_DIGIT_LL 21

int			ft_putnbr_base_fd(long long n, unsigned int base, t_manager *p)
{
	unsigned long long n_u;
	short	idx_buffer;
	char	buffer[MAX_DIGIT_LL];
	char	c;

	idx_buffer = MAX_DIGIT_LL;
	n_u = (n < 0 ? -n : n);
	while (n_u)
	{
		c = n_u % base + '0';
		if (c > '9')
			c += (p->specifier == 'X' ? 7 : 39);
		buffer[--idx_buffer] = c;
		n_u /= base;
	}
	if (n < 0 || (F_PLUS & p->flags))
		buffer[--idx_buffer] = (n < 0 ? '-' : '+');
	if (((F_DOT | F_ZERO)  & p->flags))
		put_width(p, p->width - (MAX_DIGIT_LL - idx_buffer));
	write_buffer(p, buffer + idx_buffer, MAX_DIGIT_LL - idx_buffer);
	if ((F_DASH & p->flags) & !(F_DOT & p->flags))
		put_width(p, p->width - (MAX_DIGIT_LL  - idx_buffer));
	return (-1000); // to do
}
