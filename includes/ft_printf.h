/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:53:56 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/01 19:24:21 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# define BUFFER_SIZE 64

# define F_DASH (1U << 0U)
# define F_ZERO (1U << 1U)
# define F_DOT (1U << 2U)
# define F_STAR (1U << 3U)
# define F_L (1U << 4U)
# define F_LL (1U << 5U)
# define F_H (1U << 6U)
# define F_HH (1U << 7U)
# define F_J (1U << 8U)
# define F_APOSTROPHE (1U << 9U)
# define F_HASH (1U << 10U)
# define F_SPACE (1U << 11U)
# define F_PLUS (1U << 12U)
# define F_FLOAT_L (1U << 13U)

typedef struct	s_manager
{
	int				fd;
	unsigned short	flags;
	int				width;
	int				len;
	int				precision;
	char			specifier;
	char			buffer[BUFFER_SIZE];
	size_t			buffer_idx;
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
void			*ft_memset(void *s, int c, size_t n);
int				is_digit(char c);
void			write_buffer(t_manager *p, char *s, size_t n);
int				read_flags(t_manager *p, va_list args, const char *format);

#endif
