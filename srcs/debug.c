/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:57:19 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/24 18:42:42 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void		debug_flags(t_manager *p)
{
	printf("|#|#|#|#|#|#|#|#|#|#|# FLAGS #|#|#|#|#|#|#|#|#|#|#|#|\n");
	printf("test  : %u || ", !(F_DASH & p->flags));
	printf("DASH  : %d || ", F_DASH & p->flags);
	printf("ZERO  : %d || ", F_ZERO & p->flags);
	printf("DOT   : %d || ", F_DOT & p->flags);
	printf("STAR  : %d || ", F_STAR & p->flags);
	printf("PLUS  : %d\n", F_PLUS & p->flags);
	printf("L     : %d || ", F_LL & p->flags);
	printf("LL    : %d || ", F_LL & p->flags);
	printf("H     : %d || ", F_H & p->flags);
	printf("HH    : %d\n", F_HH & p->flags);
	printf("-----------------------\n");
	printf("width : %d || ", p->width);
	printf("precision : %d\n", p->precision);
	printf("|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|#|\n");
}
