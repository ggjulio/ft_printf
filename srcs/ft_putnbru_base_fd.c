/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru_base_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 17:07:52 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/17 17:08:47 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		put_width(t_manager *p, int nb_char, int show_sign)
{
	int		i;

	i = p->width - show_sign;
	while (i > p->precision && i > nb_char)
	{
		write_buffer(p, " ", 1);
		i--;
	}
}

static void		put_precision(t_manager *p, int nb_char, int show_sign)
{
	int i;

	if ((F_ZERO & p->flags) && !(F_DOT & p->flags))
		i = p->width - show_sign;
	else
		i = p->precision;
	while (i > nb_char)
	{
		write_buffer(p, "0", 1);
		i--;
	}
}

#define MAX_DIGIT_DEC_LL 21

void			ft_putnbru_base_fd(unsigned long long n, unsigned int base, t_manager *p)
{
	short				idx_buffer;
	char				buffer[MAX_DIGIT_DEC_LL];
	char				c;
	int					nb_digits;
	int					show_sign;

	idx_buffer = MAX_DIGIT_DEC_LL;
	if (!n_u && !(GET(F_DOT) && n == 0))
		buffer[--idx_buffer] = '0';
	while (n_u)
	{
		c = n_u % base + '0';
		if (c > '9')
			c += (p->specifier == 'X' ? 7 : 39);
		buffer[--idx_buffer] = c;
		n_u /= base;
	}
	show_sign = ((n < 0 || GET(F_PLUS)) && p->specifier != 'p');
	nb_digits = MAX_DIGIT_DEC_LL - idx_buffer;
	if (GET(F_SPACE) && !show_sign)
		write_buffer(p, " ", 1);
	if (!GET(F_DASH) && (!GET(F_ZERO) || GET(F_DOT)))
		put_width(p, nb_digits, show_sign);
	if ((n < 0 || GET(F_PLUS)) && p->specifier != 'p')
		write_buffer(p, (n < 0 ? "-" : "+"), 1);
	put_precision(p, nb_digits, show_sign);
	write_buffer(p, buffer + idx_buffer, nb_digits);
	if (GET(F_DASH))
		put_width(p, nb_digits, show_sign);
}
