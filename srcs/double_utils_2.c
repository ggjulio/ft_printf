/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:58:21 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/27 17:39:55 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_double_width(t_manager *p, int nb_char)
{
	int i;

	if (GET(F_ZERO))
		return ;
	i = p->width;
	while (i > nb_char)
	{
		write_buffer(p, " ", 1);
		i--;
	}
}

void	put_double_zero(t_manager *p, int nb_char)
{
	int i;

	if (!GET(F_ZERO))
		return ;
	i = p->width;
	while (i > nb_char)
	{
		write_buffer(p, "0", 1);
		i--;
	}
}
