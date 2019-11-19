/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:53:56 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/19 18:28:48 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 100

# define GET(f) (f & p->flags)

# define F_DASH (1 << 0)
# define F_ZERO (1 << 1)
# define F_DOT (1 << 2)
# define F_STAR (1 << 3)
# define F_L (1 << 4)
# define F_LL (1 << 5)
# define F_H (1 << 6)
# define F_HH (1 << 7)
# define F_APOSTROPHE (1 << 8)
# define F_HASH (1 << 9)
# define F_SPACE (1 << 10)
# define F_PLUS (1 << 11)

typedef struct	s_manager
{
	int		fd;
	short	flags;
	int		width;
	int		len;
	int		precision;
	char	specifier;
	char	buffer[BUFFER_SIZE];
	size_t	buffer_idx;	
}				t_manager;

typedef	void	(*handler)(va_list *args, t_manager *p);

void	conv_c(va_list *args, t_manager *p);
void	conv_s(va_list *args, t_manager *p);
void	conv_p(va_list *args, t_manager *p);
void	conv_d(va_list *args, t_manager *p);
void	conv_i(va_list *args, t_manager *p);
void	conv_u(va_list *args, t_manager *p);
void	conv_x_lowcase(va_list *args, t_manager *p);
void	conv_x_upcase(va_list *args, t_manager *p);
void	conv_n(va_list *args, t_manager *p);
void	conv_f(va_list *args, t_manager *p);
void	conv_g(va_list *args, t_manager *p);
void	conv_e(va_list *args, t_manager *p);
void	conv_mod(va_list *args, t_manager *p);

int		ft_putstr_range(char const *s_begin, char const *s_end);
size_t	ft_strlen(const char *s);

void	ft_putu_d_i(unsigned long long n, t_manager *p, int *is_neg, int *nb_digit);
void	ft_putu_x_x(unsigned long long n, t_manager *p, int *nb_digit);
void	ft_put_d_i(long long n, t_manager *p);
void	ft_put_u(unsigned long long n, t_manager *p);
void	ft_put_x_x(long long n, t_manager *p);

long long	cast_d_i(t_manager *p, va_list *args);
long long	cast_u_x_x(t_manager *p, va_list *args);

void	write_buffer(t_manager *p, char *s, size_t n);

int		ft_printf(const char *format, ...)  __attribute__((format(printf,1,2)));

#endif
