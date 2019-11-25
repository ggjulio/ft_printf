/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:44:52 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/25 19:23:59 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_f(va_list *args, t_manager *p)
{
	if (GET(F_FLOAT_L))
		put_f(va_arg(*args, long double), p);
	else
		put_f(va_arg(*args, double), p);
}
