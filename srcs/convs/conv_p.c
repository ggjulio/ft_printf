/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:15:58 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/18 20:12:41 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static void     put_width(t_manager *p, int nb_char)
{
    int     i;

    i = p->width;
    while (i > p->precision && i > nb_char)
    {
        write_buffer(p, " ", 1);
        i--;
    }
}

static void     put_precision(t_manager *p, int nb_char)
{
    int i;

    if (GET(F_ZERO) && !GET(F_DOT))
		i = p->width;
    else
        i = p->precision;
    while (i > nb_char)
    {
        write_buffer(p, "0", 1);
        i--;
    }
}

static void		ft_putu_p(unsigned long long n, t_manager *p, int *nb_digit)
{
	char c;

	(void)put_precision;

	(*nb_digit)++;
	c = n % 16 + '0';
	if (c > '9')
		c += (p->specifier == 'X' ? 7 : 39);
	if (n >= 16)
		ft_putu_p(n / 16, p, nb_digit);
	else
	{
		p->width -= 2;
		if (!GET(F_DASH))
			put_width(p, *nb_digit);
		write_buffer(p, "0x", 2);
	}
	write_buffer(p, &c, 1);
}



void		conv_p(va_list *args, t_manager *p)
{
	int nb_digit;

	nb_digit = 0;
    ft_putu_p(va_arg(*args, unsigned long), p, &nb_digit);
}
