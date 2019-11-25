/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:53:52 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/25 17:07:05 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_exp(int64_t exp, t_manager *p)
{
	char c;

	c = exp % 10 + '0';
	if (exp >= 10)
		put_exp(exp / 10, p);
	write_buffer(p, &c, 1);
}

void		put_mantis(double mantis, int precision, t_manager *p)
{
	char c;

	mantis *= 10;
	c = (int)mantis + '0';
	write_buffer(p, &c, 1);
	if (precision > 1)
		put_mantis(mantis - (int)mantis, --precision, p);
}

double		ft_round(double n, size_t precision)
{
	double	rnd;

	rnd = 0.5;
	while (precision-- > 0)
		rnd /= 10;
	return (n + rnd);
}

void		put_double(double n, t_manager *p)
{
	put_exp((int64_t)n, p);
	if (p->precision > 0 || GET(F_HASH))
		write_buffer(p, ".", 1);
	if (p->precision > 0)
		put_mantis(n - (int64_t)n, p->precision, p);
}
