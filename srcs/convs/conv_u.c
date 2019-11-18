/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:16:27 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/18 14:57:07 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        ft_put_u(unsigned long long n, t_manager *p)
{
	int is_neg;
	int nb_digit;

	is_neg = 0;
	nb_digit = 0;
	ft_putu_d_i(n, p, &is_neg, &nb_digit);
    if (GET(F_DASH))
		put_width(p, nb_digit, (is_neg || GET(F_PLUS)));
}

void		conv_u(va_list *args, t_manager *p)
{
	ft_put_u(cast_u_x_x(p, args), p);
//	ft_put_d_i(va_arg(*args, long long), p);
}
