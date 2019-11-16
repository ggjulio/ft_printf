/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:47:31 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/16 19:09:14 by juligonz         ###   ########.fr       */
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

	ft_printf("%hhd_\n", (char)45);
	printf("%hhd_\n", (char)45);
}
