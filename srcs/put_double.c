/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:53:52 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/22 13:08:47 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void put_width(t_manager *p, int nb_char, int show_sign)
{
    int i;

    i = p->width - show_sign;
    while (i > p->precision && i > nb_char)
    {
        write_buffer(p, " ", 1);
        i--;
    }
}

char		get_round(double mantissa)
{
	char c;
	char c2;

	mantissa *= 10;
	c = (long)mantissa + '0';
	mantissa -= (long)mantissa;
	mantissa *= 10;
	c2 = (long)mantissa + '0';
	if (c2 > '5')
		return (c + 1);
	else if (c2 < '5')
		return (c);
	else 
		return (c);
}


void		put_mantissa(double mantissa, int prec, t_manager *p, int *nb_digit)
{
	char c;

	(*nb_digit)++;
	mantissa *= 10;
	c = (long)mantissa + '0';
	mantissa -= (long)mantissa;
	if (prec > 0)
		put_mantissa(mantissa, --prec, p, nb_digit);
	write_buffer(p, &c, 1);
		
}

void		put_double(double n, t_manager *p)
{
	int nb_digit;
	int is_neg;
	long long exp;
	double mantissa;
	unsigned int precision;


	is_neg = (n < 0 ? 1 : 0);	
	exp = (long long)n;
	mantissa = (n - exp < 0 ? -(n - exp) : n - exp);
//	mantissa = n & ;
	nb_digit = 0;
	precision = (p->precision != 0 ? p->precision : 6);

	ft_putu_d_i((exp < 0 ? -exp : exp), p, &is_neg, &nb_digit);
	write_buffer(p, ".", 1);

//	put_mantissa(mantissa, --precision, p, &nb_digit);

	

	

/*	char c;
	while (--precision)
	{
		mantissa *= 10;
		c = (long)mantissa + '0';
		mantissa -= (long)mantissa;
		write_buffer(p, &c, 1);
	}
	put_round(mantissa);
//	write_buffer(p, &c, 1);
*/





	if (GET(F_DASH))
		put_width(p, nb_digit, (is_neg || GET(F_PLUS)));
}
