/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:15:58 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/17 19:15:59 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_p(va_list *args, t_manager *p)
{
	write_buffer(p, "0x", 2);
	ft_putnbr_base_fd(va_arg(*args, unsigned long), 16, p);
}
