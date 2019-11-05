/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:47:31 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/05 20:51:41 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int 	main(void)
{
	char *t = "test";
	char *t1 = "t1 ok";
	char *t2 = "t2";
	int ret1;
	int ret2;

	(void)t;
	(void)t1;
	(void)t2;
	(void)ret1;
	(void)ret2;
	
//	ret1 = printf("1234\n");
//	ret2 = ft_printf("1234\n");
//	printf("\n\n\n%d|%d\n", ret1, ret2);


	printf("c:\n");
	printf("ok_%c_ok\n", 'B');
	ft_printf("ok_%c_ok\n", 'B');

	printf("s:\n");
	ret1 = printf("%s\n", "ok");
	ret2 = ft_printf("%s\n", "ok");

	printf("p:\n");
	printf("%p\n", (void *)42);
	ft_printf("%p\n", (void *)42);

	printf("d:\n");
	printf("%d\n", 42);
	ft_printf("%d\n", 42);

	printf("i:\n");
	printf("%i\n", 42);
	ft_printf("%i\n", 42);

// u

// x

// X


//	printf("%%:\n");

//	ret1 = printf("%%\n");
//	ret2 = ft_printf("%%\n");



//	printf("\n\n\n%d|%d\n", ret1, ret2);


}
