/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x_lowcase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:16:36 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/18 15:26:24 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void     put_width(t_manager *p, int nb_char, int show_sign)
{
    int     i;

    i = p->width - show_sign;
    while (i > p->precision && i > nb_char)
    {
        write_buffer(p, " ", 1);
        i--;
    }
}

static void     put_precision(t_manager *p, int nb_char, int show_sign)
{
    int i;

    if (GET(F_ZERO) && !GET(F_DOT))
        i = p->width - show_sign;
    else
        i = p->precision;
    while (i > nb_char)
    {
        write_buffer(p, "0", 1);
        i--;
    }
}

void	ft_putu_d_i(unsigned long long n, t_manager *p, int *is_neg, int *nb_digit)
{
	char c;

	(*nb_digit)++;
	c = n % 16 + '0';
	if (c > '9')
		c = (p->specifier == 'x' ? : );
	if (n >= 16)
		ft_putu_d_i(n / 16, p, is_neg, nb_digit);
	else
	{
		if (GET(F_SPACE) && !(*is_neg || GET(F_PLUS)))
		{
			write_buffer(p, " ", 1);
			p->width--;	
		}
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
	write_buffer(p, &c, 1);
}

void		conv_x_lowcase(va_list *args, t_manager *p)
{
	(void)args;
	(void)p;
//	if (GET(F_HASH))
//		write_buffer(p, "0x", 2);
//	ft_putnbr_base_fd(va_arg(*args, long long), 16, p);
}
