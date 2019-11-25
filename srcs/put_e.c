/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_e.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:30:53 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/25 17:09:54 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_width(t_manager *p, int nb_char)
{
	int	i;

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

static size_t		get_nb_char(int64_t exp, char is_neg, t_manager *p)
{
	size_t nb_char;

	nb_char = (is_neg || GET(F_PLUS));
	if (p->precision > 0 || GET(F_HASH))
		nb_char++;
	while ((exp /= 10))
		nb_char++;
	nb_char++;
	nb_char += p->precision;
	return (nb_char);
}

int			get_e(double n)
{
	int e;

	e = 0;
	while (n >= 10)
	{
		e++;
		n /= 10;
	}
	return (e);
}

void		put_e(double n, t_manager *p)
{
	char	is_neg;
//	int		nb_char;
	int		e;


	(void)put_zero;
	(void)put_width;
	(void)get_nb_char;
	
	p->precision = (GET(F_DOT) ? p->precision : 6);
	is_neg = (n < 0 ? 1 : 0);
	n = (n < 0 ? -n : n);
	n = ft_round(n, p->precision);
	e = get_e(n);
//	nb_char = get_nb_char(n - (int64_t)n, is_neg, p);
//	if (!GET(F_DASH))
//		put_width(p, nb_char);
//	if ((GET(F_SPACE) && !(is_neg || GET(F_PLUS))) && (p->width-- || 1))
//		write_buffer(p, " ", 1);
	if (is_neg || GET(F_PLUS))
		write_buffer(p, (is_neg ? "-" : "+"), 1);
//	put_zero(p, nb_char);
	while (e-- != 0)
		n /= 10;
	put_double(n, p);


//	if (GET(F_DASH))
//		put_width(p, nb_char);
}
