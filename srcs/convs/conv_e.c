/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:47:35 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/30 15:38:27 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_e(va_list *args, t_manager *p)
{
	if (F_FLOAT_L & p->flags)
		put_e(va_arg(*args, long double), p);
	else
		put_e(va_arg(*args, double), p);
}
