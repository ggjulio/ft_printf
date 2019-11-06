/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:53:56 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/06 18:18:16 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONVERSIONS "cspdiux%Xnfge"

# define FLAG_DASH (1 >> 1)  // -
# define FLAG_0 (1 >> 2)
# define FLAG_DOT (1 >> 3)
# define FLAG_STAR (1 >> 4)
# define FLAG_L (1 >> 5)
# define FLAG_LL (1 >> 6)
# define FLAG_H (1 >> 7)
# define FLAG_HH (1 >> 8)
# define FLAG_S_QUOTE (1 >> 9) // '
# define FLAG_HASH (1 >> 10)  // #
# define FLAG_SPACE (1 >> 11)
# define FLAG_PLUS (1 >> 12)

int		ft_printf(const char *format, ...) __attribute__((format(printf,1,2)));

#endif


