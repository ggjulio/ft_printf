/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:14:57 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/13 15:12:34 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


#include <limits.h>

void		conv_c(va_list args, t_manager *p)
{
	int		c;
	char	mbs[MB_LEN_MAX];
	int8_t	mbs_len;

	mbs_len = 1;
	c = (int)cast_s(p, args);
	p->is_error = (c < 0 ? 1 : 0);
	if (!p->f.dash)
		while (--p->width > 0)
			write_buffer(p, " ", 1);
	if (p->f.l) 
	{
		mbs_len = wctomb(mbs, c);
		if (mbs_len == -1) // || (c > 255 && !getlocale()) )  Need check locale here 
			p->is_error = 1;
	}
	else
	{
		mbs[0] = (char)c;
	}
	if (!p->is_error)
		write_buffer(p, &mbs, mbs_len);
	if (p->f.dash)
		while (--p->width > 0)
			write_buffer(p, " ", 1);
}

