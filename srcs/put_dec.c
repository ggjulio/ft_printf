/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_dec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 15:09:27 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/30 14:28:14 by juligonz         ###   ########.fr       */
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

	if (F_ZERO & p->flags && F_DOT & ~p->flags)
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

static void	recursive(uint64_t n, t_manager *p, int *is_neg, int *digits)
{
	char	c;
	int		idx;

	idx = ++(*digits);
	c = n % 10 + '0';
	if (n < 10)
	{
		if ((F_SPACE & p->flags && !(*is_neg || F_PLUS & p->flags))
			&& p->specifier != 'u' && (p->width-- || 1))
			write_buffer(p, " ", 1);
		if (c == '0' && *digits == 1 && (F_DOT & p->flags) && p->precision == 0)
			(*digits) = 0;
		if (F_DASH & ~p->flags && (F_ZERO & ~p->flags || F_DOT & p->flags))
			put_width(p, *digits, (*is_neg || F_PLUS & p->flags));
		if ((*is_neg || F_PLUS & p->flags) && p->specifier != 'u')
			write_buffer(p, (*is_neg ? "-" : "+"), 1);
		put_precision(p, *digits, (*is_neg || F_PLUS & p->flags));
		if (*digits != 0 || F_DOT & ~p->flags || p->precision != 0)
			write_buffer(p, &c, 1);
		return ;
	}
	recursive(n / 10, p, is_neg, digits);
	if ((F_APOSTROPHE & p->flags) && idx % 3 == 0)
		write_buffer(p, ",", 1);
	write_buffer(p, &c, 1);
}

void		put_int(int64_t n, t_manager *p)
{
	int is_neg;
	int nb_digit;

	is_neg = 0;
	nb_digit = 0;
	if (n < 0)
	{
		is_neg = 1;
		recursive(-n, p, &is_neg, &nb_digit);
	}
	else
		recursive(n, p, &is_neg, &nb_digit);
	if (F_DASH & p->flags)
		put_width(p, nb_digit, (is_neg || F_PLUS & p->flags));
}

void		put_uint(uint64_t n, t_manager *p)
{
	int is_neg;
	int nb_digit;

	is_neg = 0;
	nb_digit = 0;
	recursive(n, p, &is_neg, &nb_digit);
	if (F_DASH & p->flags)
		put_width(p, nb_digit, (is_neg || F_PLUS & p->flags));
}
