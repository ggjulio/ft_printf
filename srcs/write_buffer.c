/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:28:25 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/02 18:09:37 by juligonz         ###   ########.fr       */
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
			if (p->caller == SPRINTF)
			{
				ft_strncpy(p->dst + p->dst_len, p->buffer, BUFFER_SIZE);
				p->dst_len += BUFFER_SIZE;
			}
			else if (p->caller == ASPRINTF)
			{
				p->dst = ft_strdup_cat(p->dst, p->buffer,
									p->dst_len, BUFFER_SIZE);
				p->dst_len += BUFFER_SIZE;
			}
			else
				write(p->fd, p->buffer, BUFFER_SIZE);
			p->buffer_idx = 0;
		}
		p->buffer[p->buffer_idx++] = s[i++];
		p->len++;
	}
}
