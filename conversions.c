/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:42:57 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/15 14:31:27 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			conv_c(va_list *args, t_manager *p)
{
	char c = va_arg(*args, int);

    write_buffer(p, &c, 1);
	return (1);
}

int			conv_s(va_list *args, t_manager *p)
{
	char	*s = va_arg(*args, char*);
    int		len;

    write_buffer(p, s, (len = ft_strlen(s)));
    return (len);
}

int			conv_p(va_list *args, t_manager *p)
{
    write_buffer(p, "0x", 2);
	return (ft_putnbr_base_fd(va_arg(*args, unsigned long), 16, p) + 2);
}

int			conv_d(va_list *args, t_manager *p)
{
	return (ft_putnbr_base_fd(va_arg(*args, int), 10, p));
}

int			conv_i(va_list *args, t_manager *p)
{
	return (ft_putnbr_base_fd(va_arg(*args, int), 10, p));
}

int			conv_u(va_list *args, t_manager *p)
{
	return (ft_putnbr_base_fd(va_arg(*args, long long), 10, p));
}

int			conv_x_upcase(va_list *args, t_manager *p)
{
	return (ft_putnbr_base_fd(va_arg(*args, long long), 16, p));
}

int			conv_x_lowcase(va_list *args, t_manager *p)
{
	return (ft_putnbr_base_fd(va_arg(*args, long long), 16, p));
}

int			conv_mod(va_list *args, t_manager *p)
{
	(void)args;
	write(p->fd, "%", 1);	
	return (1);
}
