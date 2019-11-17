/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_x_upcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:16:45 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/17 19:21:51 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_x_upcase(va_list *args, t_manager *p)
{
	if (GET(F_HASH))
		write_buffer(p, "0X", 2);
	ft_putnbr_base_fd(va_arg(*args, long long), 16, p);
}
