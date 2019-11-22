/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:53:52 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/22 19:04:58 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


#include <stdio.h>

static char		get_last_d(double mantis, int precision)
{
	char d;

	while (precision--)
	{
		mantis *=10;
		d = (int)mantis;
		mantis -= (int)mantis;
	}
	return (d);
}

static double		get_dprecision(int64_t exp, double mantis, t_manager *p)
{
	char d;
	int precision;
	double res;

	precision = (GET(F_DOT) ? p->precision : 6);
	p->precision = precision;
	if ((GET(F_DOT) && p->precision == 0) || !precision)
		return (0.0);
	d = get_last_d(mantis, precision);
	if (d < 5)
		return (0.0);
	res = 0.1;

	if (d == 5)
	{
		while (--precision)
			res /= 10;
		return (exp % 2 == 0 ? res : 0.0);
	}	
	while (--precision)
		res /= 10;
	return (res);
}

void		put_exp(int64_t exp, t_manager *p)
{
	char c;

	c = exp % 10 + '0';
	if (exp >= 10)
		put_exp(exp / 10, p);
	write_buffer(p, &c, 1);
}

void		put_mantis(double mantis, int precision,  t_manager *p)
{
	char c;

	mantis *= 10;
	c = (int)mantis +'0';
	write_buffer (p, &c, 1);
	if (precision > 1)
		put_mantis(mantis - (int)mantis, --precision, p);

}

void		put_double(double n, t_manager *p)
{
	short	is_neg;
	int64_t exp;
	double	mantis;
	double	dprec;

	is_neg = 0;
	if (n < 0)
	{
		is_neg = 1;
		n = -n;
	}
//	n += dprec;
	exp = (int64_t)n;
	mantis = n - exp;
	dprec =  get_dprecision(exp, mantis, p);
	if (is_neg)
		write_buffer(p, "-", 1);
	put_exp(exp, p);
	if (GET(F_DOT) && p->precision == 0)
		;
	else
	{
		write_buffer(p, ".", 1);
		put_mantis(mantis + dprec, p->precision, p);
//		put_mantis(mantis, p->precision, p);
	}
//	while ()
		
//	if (GET(F_DASH))
//		put_width(p, nb_digit, (is_neg || GET(F_PLUS)));
}
