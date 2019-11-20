/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x_lowcase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:16:36 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/20 13:00:35 by juligonz         ###   ########.fr       */
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

void	ft_putu_x_x(unsigned long long n, t_manager *p, int *nb_digit)
{
	char c;

	(*nb_digit)++;
	c = n % 16 + '0';
	if (c > '9')
		c += (p->specifier == 'X' ? 7 : 39);
	if (n >= 16)
		ft_putu_x_x(n / 16, p, nb_digit);
	else
	{
		if (c == '0' && *nb_digit == 1 && GET(F_DOT) && p->precision == 0)
			(*nb_digit) = 0;
		if (GET(F_HASH) && *nb_digit > 0 && c != '0')
			p->width -= 2;	
	    if (!GET(F_DASH) && (!GET(F_ZERO) || GET(F_DOT)))
			put_width(p, *nb_digit);
		if ((GET(F_HASH) && *nb_digit > 0 && c != '0'))
			write_buffer(p, (p->specifier == 'X' ? "0X" : "0x"), 2);
		put_precision(p, *nb_digit);
		if (*nb_digit != 0 || !GET(F_DOT) || p->precision != 0)
		{
			write_buffer(p, &c, 1);
		}
		return ;
	}
	write_buffer(p, &c, 1);
}

void        ft_put_x_x(long long n, t_manager *p)
{
    int nb_digit;

    nb_digit = 0;
	ft_putu_x_x(n, p, &nb_digit);
    if (GET(F_DASH))
        put_width(p, nb_digit);
}

void		conv_x_lowcase(va_list *args, t_manager *p)
{
	ft_put_x_x(cast_unsigned(p, args), p);
}
