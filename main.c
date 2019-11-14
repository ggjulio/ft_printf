/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:47:31 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/14 19:10:59 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int 	main(void)
{
	printf("||||||||||||||||||||| c:\n");
	printf("ok_%c_ok\n", 'B');
	ft_printf("ok_%c_ok\n", 'B');
	printf("||||||||||||||||||||| s:\n");
	printf("%s\n", "ok");
	ft_printf("%s\n", "ok");
	printf("||||||||||||||||||||| p:\n");
	printf("%p\n", (void *)42);
	ft_printf("%p\n", (void *)42);
	printf("||||||||||||||||||||| d:\n");
	printf("%d\n", 42);
	ft_printf("%d\n", 42);
	printf("||||||||||||||||||||| i:\n");
	printf("%i\n", 42);
	ft_printf("%i\n", 42);
	printf("||||||||||||||||||||| u:\n");
	printf("%u\n", 42);
	ft_printf("%u\n", 42);
	printf("%u\n", -42);
	ft_printf("%u\n", -42);
	printf("||||||||||||||||||||| x:\n");
	printf("%x\n", 42);
	ft_printf("%x\n", 42);
	printf("||||||||||||||||||||| X:\n");
	printf("%X\n", 42);
	ft_printf("%X\n", 42);
	printf("||||||||||||||||||||| %%:\n");
	printf("%%\n");
	ft_printf("%%\n");

	printf("||||||||||||||||||||| test ||||||||||||||||||||||||||||||||||||||||||||\n");


	ft_printf("%+4d\n", (int)42);
//	printf("%+5s_\n", "42str");
//	printf("%+5u_\n", (int)42);

//	ft_printf("%     d\n", 42);




//	printf("\n\n\n%d|%d\n", ret1, ret2);


}
