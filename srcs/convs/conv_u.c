/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:16:27 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/20 13:01:35 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_u(va_list *args, t_manager *p)
{
	ft_put_u(cast_unsigned(p, args), p);
//	ft_put_d_i(va_arg(*args, long long), p);
}
