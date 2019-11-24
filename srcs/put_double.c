/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:53:52 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/24 19:21:01 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void put_width(t_manager *p, int nb_char)
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

static void put_zero(t_manager *p, int nb_char)
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

void           put_exp(int64_t exp, t_manager *p)
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

double		ft_round(double n, size_t precision)
{
    double  rnd;

    rnd = 0.5;
    while (precision-- > 0)
        rnd /= 10;
    return (n + rnd);
}

size_t		get_nb_char(int64_t exp, char is_neg, t_manager *p)
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

void		write_double(double n, t_manager *p)
{
	put_exp((int64_t)n, p);
	if (p->precision > 0 || GET(F_HASH))
		write_buffer(p, ".", 1);
	if (p->precision > 0)
		put_mantis(n - (int64_t)n, p->precision, p);
}

void		put_double(double n, t_manager *p)
{
	char	is_neg;
	int		nb_char;

	p->precision = (GET(F_DOT) ? p->precision : 6);
	is_neg = (n < 0 ? 1 : 0);
	n = (n < 0 ? -n : n);
	n = ft_round(n, p->precision);
	nb_char = get_nb_char(n - (int64_t)n, is_neg, p);
	if (!GET(F_DASH))
		put_width(p, nb_char);
	if ((GET(F_SPACE) && !(is_neg || GET(F_PLUS))) && (p->width-- || 1))
		write_buffer(p, " ", 1);
	if (is_neg || GET(F_PLUS))
		write_buffer(p, (is_neg ? "-" : "+"), 1);
	put_zero(p, nb_char);
	write_double(n, p);
	if (GET(F_DASH))
		put_width(p, nb_char);
}
