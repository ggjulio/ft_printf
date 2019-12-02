/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:53:52 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/30 14:49:57 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		get_nb_char(int64_t exp, char is_neg, t_manager *p)
{
	size_t nb_char;

	nb_char = (is_neg || F_PLUS & p->flags);
	if (p->precision > 0 || F_HASH & p->flags)
		nb_char++;
	while ((exp /= 10))
		nb_char++;
	nb_char++;
	nb_char += p->precision;
	return (nb_char);
}

static long double	ft_round(long double n, size_t precision)
{
	long double rnd;

	rnd = 0.5;
	while (precision-- > 0)
		rnd /= 10;
	return (n + rnd);
}

void				put_f(long double n, t_manager *p)
{
	char	is_neg;
	int		nb_char;

	if (p->specifier != 'g')
		p->precision = (F_DOT & p->flags ? p->precision : 6);
	is_neg = (n < 0 ? 1 : 0);
	n = (n < 0 ? -n : n);
	n = ft_round(n, p->precision);
	if (p->specifier == 'g')
		p->precision = trailing_zero(n - (int)n, p->precision);
	nb_char = get_nb_char(n - (int64_t)n, is_neg, p);
	if ((F_SPACE & p->flags && !(is_neg || F_PLUS & p->flags)))
	{
		write_buffer(p, " ", 1);
		p->width--;
	}
	if (F_DASH & ~p->flags)
		put_double_width(p, nb_char);
	if (is_neg || F_PLUS & p->flags)
		write_buffer(p, (is_neg ? "-" : "+"), 1);
	put_double_zero(p, nb_char);
	put_double(n, p);
	if (F_DASH & p->flags)
		put_double_width(p, nb_char);
}
