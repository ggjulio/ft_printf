/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:53:56 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/13 15:34:01 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 5

# define F_DASH (1 << 0)
# define F_ZERO (1 << 1)
# define F_DOT (1 << 2)
# define F_STAR (1 << 3)
# define F_L (1 << 4)
# define F_LL (1 << 5)
# define F_H (1 << 6)
# define F_HH (1 << 7)
# define F_SINGLE_QUOTE (1 << 8)
# define F_HASH (1 << 9)
# define F_SPACE (1 << 10)
# define F_PLUS (1 << 11)

typedef struct	s_str
{
	char	*s;
	int		len;
}				t_str;

typedef struct	s_manager
{
	short	flags;
	char	specifier;
}				t_manager;

typedef	int	(*handler)(va_list *args, int fd);

int		conv_c(va_list *args, int fd);
int		conv_s(va_list *args, int fd);
int		conv_p(va_list *args, int fd);
int		conv_d(va_list *args, int fd);
int		conv_i(va_list *args, int fd);
int		conv_u(va_list *args, int fd);
int		conv_x_lowcase(va_list *args, int fd);
int		conv_x_upcase(va_list *args, int fd);
int		conv_mod(va_list *args, int fd);

int		ft_putstr_range(char const *s_begin, char const *s_end);
size_t	ft_strlen(const char *s);
int		ft_putnbr_base_fd(long long n, unsigned int base, int fd, int upcase);

int		ft_printf(const char *format, ...) __attribute__((format(printf,1,2)));

#endif
