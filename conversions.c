/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:42:57 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/16 21:33:46 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	cast_len(t_manager *p, long long n)
{
	if (F_H & p->flags)
		return ((short)n);
	if (F_HH & p->flags)
		return ((signed char)n);
	if (F_L & p->flags)
		return ((long)n);
	if (F_LL & p->flags)
		return ((long long)n);
	return (n);
}

int			conv_c(va_list *args, t_manager *p)
{
	char c = va_arg(*args, int);

	if (!(F_DASH & p->flags))
		while (--p->width > 0)
			write_buffer(p, " ", 1);	
    write_buffer(p, &c, 1);
	if ((F_DASH & p->flags))
		while (--p->width > 0)
			write_buffer(p, " ", 1);
	return (1);
}

int			conv_s(va_list *args, t_manager *p)
{
	char	*s = va_arg(*args, char*);
    int		len;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	len = ((F_DOT & p->flags) && p->precision < len ? p->precision : len);
	p->width -= len;
	if (!(F_DASH & p->flags))
		while (p->width-- > 0)
			write_buffer(p, " ", 1);
    write_buffer(p, s, len);
	if ((F_DASH & p->flags))
		while (p->width-- > 0)
			write_buffer(p, " ", 1);
    return (len);
}

int			conv_p(va_list *args, t_manager *p)
{
    write_buffer(p, "0x", 2);
	return (ft_putnbr_base_fd(va_arg(*args, unsigned long), 16, p) + 2);
}

int			conv_d(va_list *args, t_manager *p)
{
	return (ft_putnbr_base_fd(cast_len(p, va_arg(*args, int)), 10, p));
//	return (ft_putnbr_base_fd(va_arg(*args, int), 10, p));
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
