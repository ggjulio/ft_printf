/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_g.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:22:59 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/25 18:45:10 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_g(double n, t_manager *p)
{
	char	is_neg;
	int 	i;
	int		e;

	(void)put_zero;
	(void)put_width;
	(void)get_nb_char;
	
	p->precision = (GET(F_DOT) ? p->precision : 6);
	is_neg = (n < 0 ? 1 : 0);
	n = (n < 0 ? -n : n);
	n = ft_round(n, p->precision);
	e = get_e(n);
//	nb_char = get_nb_char(n - (int64_t)n, is_neg, p);
//	if (!GET(F_DASH))
//		put_width(p, nb_char);
//	if ((GET(F_SPACE) && !(is_neg || GET(F_PLUS))) && (p->width-- || 1))
//		write_buffer(p, " ", 1);
	if (is_neg || GET(F_PLUS))
		write_buffer(p, (is_neg ? "-" : "+"), 1);
//	put_zero(p, nb_char);
	i = e;
	if (i > 0)
		while (i-- != 0)
			n /= 10;
	else
		while (i++ != 0)
			n *= 10;
	put_double(n, p);
	show_exp(e, p);
//	if (GET(F_DASH))
//		put_width(p, nb_char);
}
