/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:53:52 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/28 18:29:16 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	get_nb_char(int64_t exp, char is_neg, t_manager *p)
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

static int      trailing_zero(long double mantis, int precision)
{
    int     i;
    int     new_precision;
    char    c;

    i = precision;
    new_precision = 0;
    while (i--)
    {
        mantis -= (int)mantis;
        mantis *= 10;
        c = (int)mantis;
        if (c)
            new_precision = precision - i;
    }
    return (new_precision);
}

static int exp_format(long double n, int precision)
{
	while (precision--)
	{
		if ((int)n)
			return (0);
		n *= 10;
	}
	return (1);
}

void			put_g(long double n, t_manager *p)
{
	char	is_neg;
	int		nb_char;

	p->precision = (GET(F_DOT) ? p->precision : 6);
	p->precision = (p->precision > 0 ? p->precision - 1 : 0);
	if (exp_format(n, p->precision))
	{
		put_e(n, p);
		return ;
	}
	is_neg = (n < 0 ? 1 : 0);
	n = (n < 0 ? -n : n);
	n = ft_round(n, p->precision);
	nb_char = get_nb_char(n - (int64_t)n, is_neg, p);
    p->precision = trailing_zero(n - (int)n, p->precision);
	if ((GET(F_SPACE) && !(is_neg || GET(F_PLUS))) && (p->width-- || 1))
		write_buffer(p, " ", 1);
	if (!GET(F_DASH))
		put_double_width(p, nb_char);
	if (is_neg || GET(F_PLUS))
		write_buffer(p, (is_neg ? "-" : "+"), 1);
	put_double_zero(p, nb_char);
	put_double(n, p);
	if (GET(F_DASH))
		put_double_width(p, nb_char);
}
