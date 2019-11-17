/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:42:57 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/17 13:48:00 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long	cast_len(t_manager *p, long long n)
{
	if (GET(F_H))
		return ((short)n);
	if (GET(F_HH))
		return ((signed char)n);
	if (GET(F_L))
		return ((long)n);
	if (GET(F_LL))
		return ((long long)n);
	return (n);
}

void		conv_c(va_list *args, t_manager *p)
{
	char c = va_arg(*args, int);

	if (!GET(F_DASH))
		while (--p->width > 0)
			write_buffer(p, " ", 1);	
    write_buffer(p, &c, 1);
	if (GET(F_DASH))
		while (--p->width > 0)
			write_buffer(p, " ", 1);
}

void		conv_s(va_list *args, t_manager *p)
{
	char	*s = va_arg(*args, char*);
    int		len;

	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	len = (GET(F_DOT) && p->precision < len ? p->precision : len);
	p->width -= len;
	if (!GET(F_DASH))
		while (p->width-- > 0)
			write_buffer(p, " ", 1);
    write_buffer(p, s, len);
	if (GET(F_DASH))
		while (p->width-- > 0)
			write_buffer(p, " ", 1);
}

void		conv_p(va_list *args, t_manager *p)
{
    write_buffer(p, "0x", 2);
	ft_putnbr_base_fd(va_arg(*args, unsigned long), 16, p);
}

void		conv_d(va_list *args, t_manager *p)
{
	ft_putnbr_base_fd(cast_len(p, va_arg(*args, int)), 10, p);
//	ft_putnbr_base_fd(va_arg(*args, int), 10, p);
}

void		conv_i(va_list *args, t_manager *p)
{
	ft_putnbr_base_fd(va_arg(*args, int), 10, p);
}

void		conv_u(va_list *args, t_manager *p)
{
	ft_putnbr_base_fd(va_arg(*args, long long), 10, p);
}

void		conv_x_upcase(va_list *args, t_manager *p)
{
	ft_putnbr_base_fd(va_arg(*args, long long), 16, p);
}

void		conv_x_lowcase(va_list *args, t_manager *p)
{
	ft_putnbr_base_fd(va_arg(*args, long long), 16, p);
}

void		conv_n(va_list *args, t_manager *p)
{
	int *n = va_arg(*args, int *);

	*n = p->len;
}

void		conv_mod(va_list *args, t_manager *p)
{
	char c;
	(void)args;

	c = (GET(F_ZERO) ? '0': ' ');
	if (!GET(F_DASH))
		while (--p->width > 0)
			write_buffer(p, &c, 1);
	write_buffer(p, "%", 1);	
	if (GET(F_DASH))
		while (--p->width > 0)
			write_buffer(p, " ", 1);
}
