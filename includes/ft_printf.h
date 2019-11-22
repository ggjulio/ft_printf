/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:53:56 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/22 13:17:45 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
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
void	conv_o(va_list *args, t_manager *p);
void	conv_mod(va_list *args, t_manager *p);

int		ft_putstr_range(char const *s_begin, char const *s_end);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
int		is_digit(char c);

void	ft_putu_d_i(uint64_t n, t_manager *p, int *is_neg, int *nb_digit);
void	ft_putu_x_x(uint64_t n, t_manager *p, int *nb_digit);
void	ft_put_d_i(int64_t n, t_manager *p);
void	ft_put_u(uint64_t n, t_manager *p);
void	ft_put_x_x(int64_t n, t_manager *p);
void	put_oct(int64_t n, t_manager *p);
void	put_double(double n, t_manager *p);

void    write_buffer(t_manager *p, char *s, size_t n);

int64_t		cast_signed(t_manager *p, va_list *args);
uint64_t	cast_unsigned(t_manager *p, va_list *args);
void		*cast_ptr(t_manager *p, va_list *args);

void	write_buffer(t_manager *p, char *s, size_t n);
int		read_flags(t_manager *p, va_list *args, const char *format);

int			ft_printf(const char *format, ...)  __attribute__((format(printf,1,2)));

#endif
