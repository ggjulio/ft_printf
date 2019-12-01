/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_g.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:47:21 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/01 19:01:59 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_g(va_list args, t_manager *p)
{
	if (F_FLOAT_L & p->flags)
		put_g(va_arg(args, long double), p);
	else
		put_g(va_arg(args, double), p);
}
