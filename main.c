/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:47:31 by juligonz          #+#    #+#             */
/*   Updated: 2019/10/30 19:24:01 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int 	main(void)
{
	char *t = "t";
	char *t1 = "t1";
	char *t2 = "t2";

	int ret1;
	int ret2;
	
	ret1 = printf("1234\n");
	ret2 = ft_printf("1234\n");
	printf("\n\n\n%d|%d\n", ret1, ret2);

	ret1 = printf("-%s|%s|%s\n", t, t1, t2);
	ret2 = ft_printf("_%s|%s|%s\n", t, t1, t2);
	printf("\n\n\n%d|%d\n", ret1, ret2);


}
