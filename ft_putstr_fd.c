/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:44:54 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/12 13:26:32 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_fd(va_list *args, int fd)
{
	char *s = va_arg(*args, char*);
	int len;

	write(fd, s, (len = ft_strlen(s)));
	return (len);
	// modify to return ssize_t from write
}
