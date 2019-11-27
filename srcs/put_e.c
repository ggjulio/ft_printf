/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_e.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:30:53 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/27 14:57:37 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_e(double n)
{
	int e;

	e = 0;
	while (n >= 10)
	{
		e++;
		n /= 10;
	}
	while ((int64_t)n == 0)
	{
		e--;
		n *= 10;
	}
	return (e);
}

static void	show_exp(int e, t_manager *p)
{
	char	s[2];

	write_buffer(p, "e", 1);
	write_buffer(p, (e < 0 ? "-" : "+"), 1);
	e = (e < 0 ? -e : e);
	s[0] = (e / 10) % 10 + '0';
	s[1] = e % 10 + '0';
	write_buffer(p, s, 2);
}

void		put_e(long double n, t_manager *p)
{
	char	is_neg;
	int		i;
	int		e;

	p->precision = (GET(F_DOT) ? p->precision : 6);
	is_neg = (n < 0 ? 1 : 0);
	n = (n < 0 ? -n : n);
	e = get_e(n);
	n = ft_round(n, p->precision + (e < 0 ? -e : e));
	if (is_neg || GET(F_PLUS))
		write_buffer(p, (is_neg ? "-" : "+"), 1);
	i = e;
	if (i > 0)
		while (i-- != 0)
			n /= 10;
	else
		while (i++ != 0)
			n *= 10;
	put_double(n, p);
	show_exp(e, p);
}
