/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:47:31 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/17 13:21:34 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int 	main(void)
{
/*
	printf("||||||||||||||||||||| c:\n");
	printf("ok_%c_ok\n", 'B');
	ft_printf("ok_%c_ok\n", 'B');

	printf("||||||||||||||||||||| s:\n");
	printf("%s\n", "ok");
	ft_printf("%s\n", "ok");
	printf("||||||||||||||||||||| p:\n");
	printf("%p\n", (void *)-42);
	ft_printf("%p\n", (void *)-42);
	printf("||||||||||||||||||||| d:\n");
	printf("%d\n", -42);
	ft_printf("%d\n", -42);
	printf("||||||||||||||||||||| i:\n");
	printf("%i\n", -42);
	ft_printf("%i\n", -42);
	printf("||||||||||||||||||||| u:\n");
	printf("%u\n", -42);
	ft_printf("%u\n", -42);
	printf("%u\n", -42);
	ft_printf("%u\n", -42);
	printf("||||||||||||||||||||| x:\n");
	printf("%x\n", -42);
	ft_printf("%x\n", -42);
	printf("||||||||||||||||||||| X:\n");
	printf("%X\n", -42);
	ft_printf("%X\n", -42);
	printf("||||||||||||||||||||| %%:\n");
	printf("%%\n");
	ft_printf("%%\n");

	printf("||||||||||||||||||||| test ||||||||||||||||||||||||||||||||||||||||||||\n");
	printf("_-_%s-_-%s\n", "ok","bien");
	ft_printf("_-_%s-_-%s\n", "ok","bien");

	printf("1---------------------\n");
	printf("%.5d|\n", 42);
	ft_printf("%.5d|\n", 42);

	printf("2---------------------\n");
	printf("%05d|\n", 42);
	ft_printf("%05d|\n", 42);

	printf("3---------------------\n");
	printf("%-.5d|\n", 42);
	ft_printf("%-.5d|\n", 42);


	printf("4---------------------\n");
	printf("%-5d|\n", 42);
	ft_printf("%-5d|\n", 42);

	printf("5---------------------\n");
	printf("%5d|\n", 42);
	ft_printf("%5d|\n", 42);

	printf("6---------------------\n");
	printf("%-5d|\n", 42);
	ft_printf("%-5d|\n", 42);

	printf("7---------------------\n");
	printf("%+5d|\n", 42);
	ft_printf("%+5d|\n", 42);

	printf("8---------------------\n");
	printf("%+-5d|\n", 42);
	ft_printf("%+-5d|\n", 42);

	printf("9---------------------\n");
	printf("%5d|\n", -42);
	ft_printf("%5d|\n", -42);

	printf("10--------------------\n");
	printf("%-5d|\n", -42);
	ft_printf("%-5d|\n", -42);

//	printf("11--------------------\n");
//	printf("%08d|\n", 5, 42);
//	ft_printf("%08*d|\n", 5, 42);


//	printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d\n", -2, -2, 8, -2, -2, -12, -2, 0, 123456789, -2, -2, 0, -4, 0, -12345678, -2, -2, 'a');
//	ft_printf("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", -2, -2, 8, -2, -2, -12, -2, 0, 123456789, -2, -2, 0, -4, 0, -12345678, -2, -2, 'a');


	printf("12--------------------\n");
	printf("%3.3d_\n", 42);
	ft_printf("%3.3d_\n", 42);

	printf("13--------------------\n");
	printf("%.4d_\n", 42);
	ft_printf("%.4d_\n", 42);

	printf("14--------------------\n");
	printf("%04d_\n", 42);
	ft_printf("%04d_\n", 42);

	printf("14_BIS----------------\n");
	printf("%+04d_\n", 42);
	ft_printf("%+04d_\n", 42);

	printf("15--------------------\n");
	printf("%4d_\n", 42);
	ft_printf("%4d_\n", 42);



	printf("%.5d_\n", 42);
	ft_printf("%.5d_\n", 42);
	printf("%5d_\n", 42);
	ft_printf("%5d_\n", 42);
	printf("%05d_\n", 42);
	ft_printf("%05d_\n", 42);
	

	ft_printf("%5.3d_\n", 42);
	printf("%5.3d_\n", 42);
	ft_printf("%1.3d_\n", 42);
	printf("%1.3d_\n", 42);

	ft_printf("%10.5d_\n", -216);
	printf("%10.5d_\n", -216);

	ft_printf("% .4d\n", 5263);
	printf("% .4d\n", 5263);
	ft_printf("%.4d\n", 5263);
	printf("%.4d\n", 5263);

	ft_printf("%d%d_\n",40, 45);
	printf("%d%d_\n",40, 45);




	ft_printf("%32s\n", "abc");
	printf("%32s\n", "abc");

	ft_printf("%.2s_\n", "abc");
	printf("%.2s_\n", "abc");
	ft_printf("%3.1s_\n", "abc");
	printf("%3.1s_\n", "abc");

	ft_printf("%-32s_\n", "abc");
	printf("%-32s_\n", "abc");

	printf("hello, %s.\n", NULL);
	ft_printf("hello, %s.\n", NULL);


	ft_printf("%3c_\n", 'C');
	printf("%3c_\n", 'C');
	ft_printf("%-3c_\n", 'C');
	printf("%-3c_\n", 'C');

*/

//	printf("%5");
//	ft_printf("%5");
	
//	int n;
//	printf("12345%n", &n);
//	printf("|%d|\n", n);
//	ft_printf("12345%n", &n);
//	ft_printf("|%d|\n", n);

//	printf("%0d_\n", 0);
//	ft_printf("%0d_\n", 0);
	printf("%0.d_\n", 1);
	printf("%0.d_\n", 0);
	ft_printf("%0.d_\n", 0);




//	printf("%");
//	ft_printf("%");
//	printf("%hhd_\n", (char)45);
}
