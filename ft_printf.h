/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:53:56 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/12 13:07:05 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

# define F_DASH (1 << 0)
# define F_0 (1 << 1)
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

typedef int (*handler)(va_list *args, int fd);

int		ft_printf(const char *format, ...) __attribute__((format(printf,1,2)));

int		ft_putchar_fd(va_list *args, int fd);
int		ft_putstr_fd(va_list *args, int fd);
int		ft_putstr_range(char const *s_begin, char const *s_end);

size_t	ft_strlen(const char *s);

#endif


