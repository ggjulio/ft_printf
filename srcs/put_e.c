/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_e.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:30:53 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/28 21:35:37 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_exponent(long double n)
{
	int e;

	if (!n)
		return (0);
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

static int	update_n(long double *n, int e)
{
	int i;

	i = e;
	if (i > 0)
		while (i-- != 0)
			*n /= 10;
	else
		while (i++ != 0)
			*n *= 10;
	if ((int64_t)*n > 9)
	{
		e = (e < 0 ? e + 1 : e - 1);
		*n /= 10;
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
	int		e;
	int		nb_char;

	p->precision = (GET(F_DOT) ? p->precision : 6);
	is_neg = (n < 0 ? 1 : 0);
	n = (n < 0 ? -n : n);
	e = get_exponent(n);
	n = ft_round(n, p->precision + (e < 0 || is_neg ? -e : e));
	e = update_n(&n, e);
	if (p->specifier == 'g')
		p->precision = trailing_zero(n - (int)n, p->precision);
	nb_char = p->precision + 6 + (GET(F_PLUS) ? 1 : 0);
	if ((GET(F_SPACE) && !(is_neg || GET(F_PLUS))) && (p->width-- || 1))
		write_buffer(p, " ", 1);
	if (!GET(F_DASH))
		put_double_width(p, nb_char);
	if (is_neg || GET(F_PLUS))
		write_buffer(p, (is_neg ? "-" : "+"), 1);
	put_double_zero(p, nb_char);
	put_double(n, p);
	show_exp(e, p);
	if (GET(F_DASH))
		put_double_width(p, nb_char);
}
