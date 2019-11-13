/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:42:57 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/13 15:19:52 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			conv_c(va_list *args, int fd)
{
    const unsigned char c = va_arg(*args, int);

    write(fd, &c, 1);
	return (1);
}

int			conv_s(va_list *args, int fd)
{
	char *s = va_arg(*args, char*);
    int len;

    write(fd, s, (len = ft_strlen(s)));
    return (len);
    // modify to return ssize_t from write
}

int			conv_p(va_list *args, int fd)
{
	write(fd, "0x", 2);
	return (ft_putnbr_base_fd(va_arg(*args, long long), 16, fd, 0) + 2);
}

int			conv_d(va_list *args, int fd)
{
	return (ft_putnbr_base_fd(va_arg(*args, long long), 10, fd, 0));
}

int			conv_i(va_list *args, int fd)
{
	return (ft_putnbr_base_fd(va_arg(*args, long long), 10, fd, 0));
}

int			conv_u(va_list *args, int fd)
{
	return (ft_putnbr_base_fd(va_arg(*args, long long), 10, fd, 0));
}

int			conv_x_upcase(va_list *args, int fd)
{
	return (ft_putnbr_base_fd(va_arg(*args, long long), 16, fd, 0));
}

int			conv_x_lowcase(va_list *args, int fd)
{
	return (ft_putnbr_base_fd(va_arg(*args, long long), 16, fd, 1));
}

int			conv_mod(va_list *args, int fd)
{
	(void)args;
	write(fd, "%", 1);	
	return (1);
}

#include <math.h>

/*
void		do_flags(short *flags, char )
{
	if (F_DASH & *flags)
		
}
*/
