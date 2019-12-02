/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:28:25 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/02 19:22:17 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_buffer(t_manager *p, char *s, size_t n)
{
	int i;

	i = 0;
	while (n--)
	{
		if (p->buffer_idx == BUFFER_SIZE)
		{
			if (p->caller == PRINTF)
				write(p->fd, p->buffer, BUFFER_SIZE);
			else if (p->caller == SPRINTF)
				ft_strncpy(p->dst + p->dst_len, p->buffer, BUFFER_SIZE);
			else if (p->caller == ASPRINTF && !p->malloc_fail)
			{
				p->dst = ft_strdup_cat(p->dst, p->buffer,
									p->dst_len, BUFFER_SIZE);
				if (!p->dst)
					p->malloc_fail = 1;
			}
			if (p->caller != PRINTF)
				p->dst_len += BUFFER_SIZE;
			p->buffer_idx = 0;
		}
		p->buffer[p->buffer_idx++] = s[i++];
		p->len++;
	}
}
