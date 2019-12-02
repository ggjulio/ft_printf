/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:44:52 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/02 21:38:05 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_f(va_list args, t_manager *p)
{
	long double n;

	if (F_FLOAT_L & p->flags)
		n = va_arg(args, long double);
	else
		n = va_arg(args, double);
	if (is_valid_float(n, p))
		put_f(n, p);
}
