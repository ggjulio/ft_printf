/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:53:56 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/02 15:52:53 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# define F_DASH 1
# define F_ZERO 2
# define F_DOT	4
# define F_STAR 8
# define F_L 16
# define F_LL 32
# define F_H 64
# define F_HH 128
# define F_J 256
# define F_APOSTROPHE 512
# define F_HASH 1024
# define F_SPACE 2048
# define F_PLUS 4096
# define F_FLOAT_L 8192

# define BUFFER_SIZE 2

typedef struct	s_manager
{
	int				fd;
	unsigned short	flags;
	int				width;
	int				len;
	int				precision;
	char			specifier;
	char			buffer[BUFFER_SIZE];
	int				buffer_idx;
	char			*sprintf_dst;
	int				sprintf_dst_idx;
}				t_manager;

typedef void	(*t_handler)(va_list args, t_manager *p);

/*
** ***************** conversions ******************
*/

void			conv_c(va_list args, t_manager *p);
void			conv_s(va_list args, t_manager *p);
void			conv_p(va_list args, t_manager *p);
void			conv_d(va_list args, t_manager *p);
void			conv_i(va_list args, t_manager *p);
void			conv_u(va_list args, t_manager *p);
void			conv_x_lowcase(va_list args, t_manager *p);
void			conv_x_upcase(va_list args, t_manager *p);
void			conv_n(va_list args, t_manager *p);
void			conv_f(va_list args, t_manager *p);
void			conv_g(va_list args, t_manager *p);
void			conv_e(va_list args, t_manager *p);
void			conv_o(va_list args, t_manager *p);
void			conv_mod(va_list args, t_manager *p);

/*
** **************** print in buffer ****************
*/

void			put_int(int64_t n, t_manager *p);
void			put_uint(uint64_t n, t_manager *p);
void			put_hex(uint64_t n, t_manager *p);
void			put_ptr(uint64_t n, t_manager *p);
void			put_oct(int64_t n, t_manager *p);
void			put_f(long double n, t_manager *p);
void			put_g(long double n, t_manager *p);
void			put_e(long double n, t_manager *p);

/*
** ***************** floats utils ******************
*/

void			put_double(long double n, t_manager *p);
void			put_double_width(t_manager *p, int nb_char);
void			put_double_zero(t_manager *p, int nb_char);
int				trailing_zero(long double mantis, int precision);

/*
** **************** Lenght modifier ****************
*/

int64_t			cast_signed(t_manager *p, va_list args);
uint64_t		cast_unsigned(t_manager *p, va_list args);
void			*cast_ptr(t_manager *p, va_list args);

/*
** ******************* Utility  ********************
*/

size_t			ft_strlen(const char *s);
char			*ft_strncpy(char *dest, const char *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
int				is_digit(char c);
void			write_buffer(t_manager *p, char *s, size_t n);
int				read_flags(t_manager *p, va_list args, const char *format);
void			parse(va_list args, t_manager *p);

#endif
