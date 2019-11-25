/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_g.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:22:59 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/25 18:59:38 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		put_g(double n, t_manager *p)
{
	char	is_neg;
	int 	i;
	int		e;

	p->precision = (GET(F_DOT) ? p->precision : 6);
	is_neg = (n < 0 ? 1 : 0);
	n = (n < 0 ? -n : n);
	n = ft_round(n, p->precision);


	//g
}
