/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:09:27 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/20 16:32:33 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_width(t_manager *p, int nb_char, int show_sign)
{
	int	i;

	i = p->width - show_sign;
	while (i > p->precision && i > nb_char)
	{
		write_buffer(p, " ", 1);
		i--;
	}
}

static void	put_precision(t_manager *p, int nb_char, int show_sign)
{
	int i;

	if (GET(F_ZERO) && !GET(F_DOT))
	{
		i = p->width - show_sign;
		p->width = (p->width < 0 ? -(p->width) : p->width);
	}
	else
		i = p->precision;
	while (i > nb_char)
	{
		write_buffer(p, "0", 1);
		i--;
	}
}

void		ft_putu_d_i(unsigned long long n, t_manager *p, int *is_neg, int *nb_digit)
{
	char	c;
	int		idx;

	(*nb_digit)++;
	idx = *nb_digit;
	c = n % 10 + '0';
	if (n < 10)
	{
		if ((GET(F_SPACE) && !(*is_neg || GET(F_PLUS))) && (p->width-- || 1))
			write_buffer(p, " ", 1);
		if (c == '0' && *nb_digit == 1 && GET(F_DOT) && p->precision == 0)
			(*nb_digit) = 0;
		if (!GET(F_DASH) && (!GET(F_ZERO) || GET(F_DOT)))
			put_width(p, *nb_digit, (*is_neg || GET(F_PLUS)));
		if (*is_neg || GET(F_PLUS))
			write_buffer(p, (*is_neg ? "-" : "+"), 1);
		put_precision(p, *nb_digit, (*is_neg || GET(F_PLUS)));
		if (*nb_digit != 0 || !GET(F_DOT) || p->precision != 0)
			write_buffer(p, &c, 1);
		return ;
	}
	ft_putu_d_i(n / 10, p, is_neg, nb_digit);
	if (GET(F_APOSTROPHE) && idx % 3 == 0)
		write_buffer(p, "^", 1);
	write_buffer(p, &c, 1);
}

void		ft_put_d_i(long long n, t_manager *p)
{
	int is_neg;
	int nb_digit;

	is_neg = 0;
	nb_digit = 0;
	if (n < 0)
	{
		is_neg = 1;
		ft_putu_d_i(-n, p, &is_neg, &nb_digit);
	}
	else
		ft_putu_d_i(n, p, &is_neg, &nb_digit);
	if (GET(F_DASH))
		put_width(p, nb_digit, (is_neg || GET(F_PLUS)));
}

void		ft_put_u(unsigned long long n, t_manager *p)
{
	int is_neg;
	int nb_digit;

	is_neg = 0;
	nb_digit = 0;
	ft_putu_d_i(n, p, &is_neg, &nb_digit);
	if (GET(F_DASH))
		put_width(p, nb_digit, (is_neg || GET(F_PLUS)));
}
