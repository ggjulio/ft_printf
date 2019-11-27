/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_e.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:30:53 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/27 16:30:47 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_width(t_manager *p, int nb_char)
{
	int i;

	if (GET(F_ZERO))
		return ;
	i = p->width;
	while (i > nb_char)
	{
		write_buffer(p, " ", 1);
		i--;
	}
}

static void	put_zero(t_manager *p, int nb_char)
{
	int i;

	if (!GET(F_ZERO))
		return ;
	i = p->width;
	while (i > nb_char)
	{
		write_buffer(p, "0", 1);
		i--;
	}
}

static int	get_e(long double n)
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

static void	update_n(long double *n, int e)
{
	if (e > 0)
		while (e-- != 0)
			*n /= 10;
	else
		while (e++ != 0)
			*n *= 10;
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
	e = get_e(n);
	n = ft_round(n, p->precision + (e < 0 || is_neg ? -e : e));
	update_n(&n, e);
	nb_char = p->precision + 6 + (GET(F_PLUS) ? 1 : 0);
	if ((GET(F_SPACE) && !(is_neg || GET(F_PLUS))) && (p->width-- || 1))
		write_buffer(p, " ", 1);
	if (!GET(F_DASH))
		put_width(p, nb_char);
	if (is_neg || GET(F_PLUS))
		write_buffer(p, (is_neg ? "-" : "+"), 1);
	put_zero(p, nb_char);
	put_double(n, p);
	show_exp(e, p);
	if (GET(F_DASH))
		put_width(p, nb_char);
}
