/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:47:31 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/25 18:41:32 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int 	main(void)
{
    setlocale(LC_NUMERIC, "en_US");
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
	printf("%X\n", 42);
	ft_printf("%X\n", 42);

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



	printf("----------------------\n");
	printf("%.5d_\n", 42);
	ft_printf("%.5d_\n", 42);

	printf("----------------------\n");
	printf("%5d_\n", 42);
	ft_printf("%5d_\n", 42);

	printf("----------------------\n");
	printf("%05d_\n", 42);
	ft_printf("%05d_\n", 42);
	
	printf("----------------------\n");
	ft_printf("%5.3d_\n", 42);
	printf("%5.3d_\n", 42);

	printf("----------------------\n");
	ft_printf("%1.3d_\n", 42);
	printf("%1.3d_\n", 42);

	printf("----------------------\n");
	ft_printf("%10.5d_\n", -216);
	printf("%10.5d_\n", -216);


	printf("----------------------\n");
	ft_printf("% .4d\n", 5263);
	printf("% .4d\n", 5263);

	printf("----------------------\n");
	printf("15--------------------\n");
	ft_printf("%.4d\n", 5263);
	printf("%.4d\n", 5263);

	printf("----------------------\n");
	ft_printf("%d%d_\n",40, 45);
	printf("%d%d_\n",40, 45);




	printf("----------------------\n");
	ft_printf("%32s\n", "abc");
	printf("%32s\n", "abc");

	printf("----------------------\n");
	ft_printf("%.2s_\n", "abc");
	printf("%.2s_\n", "abc");

	printf("----------------------\n");
	ft_printf("%3.1s_\n", "abc");
	printf("%3.1s_\n", "abc");

	printf("----------------------\n");
	ft_printf("%-32s_\n", "abc");
	printf("%-32s_\n", "abc");


	printf("----------------------\n");
	printf("hello, %s.\n", NULL);
	ft_printf("hello, %s.\n", NULL);


	printf("----------------------\n");
	ft_printf("%3c_\n", 'C');
	printf("%3c_\n", 'C');

	printf("----------------------\n");
	ft_printf("%-3c_\n", 'C');
	printf("%-3c_\n", 'C');



	printf("----------------------\n");
	int n;
	printf("12345%n", &n);
	printf("|%d|\n", n);
	ft_printf("12345%n", &n);
	ft_printf("|%d|\n", n);

	printf("----------------------\n");
	printf("%0d_\n", 0);
	ft_printf("%0d_\n", 0);

	printf("----------------------\n");
	printf("%0.d_\n", 1);
	ft_printf("%0.d_\n", 1);

	printf("----------------------\n");
	printf("%0.d_\n", 0);
	ft_printf("%0.d_\n", 0);

	printf("----------------------\n");
	printf("%0.i_\n", 0);
	ft_printf("%0.i_\n", 0);

	printf("----------------------\n");
	printf("%0.u_\n", 0);
	ft_printf("%0.u_\n", 0);

	printf("----------------------\n");
	printf("%0.x_\n", 0);
	ft_printf("%0.x_\n", 0);


//	printf("----------------------\n");
//	printf("%ld\n", 22337203685477);
//	ft_printf("%ld\n", 22337203685477);

	printf("----------------------\n");
	printf("%#x\n", 31);
	ft_printf("%#x\n", 31);

	printf("----------------------\n");
	printf("%x\n", 31);
	ft_printf("%x\n", 31);

	printf("----------------------\n");
	printf("%#X\n", 31);
	ft_printf("%#X\n", 31); 

	printf("----------------------\n");
	printf("%X\n", 31);
	ft_printf("%X\n", 31); 

	printf("----------------------\n");
	printf("%#5.3X\n", 31);
	ft_printf("%#5.3X\n", 31);

	printf("----------------------\n");
	printf("%5.3X\n", 31);
	ft_printf("%5.3X\n", 31);

	printf("----------------------\n");
	printf("%'%_\n");
	ft_printf("%'%_\n");

	printf("----------------------\n");
	printf("% 08.3d\n", 8375);
	ft_printf("% 08.3d\n", 8375);
//	printf("%");
//	ft_printf("%");
//	printf("%hhd_\n", (char)45);




//	printf("%'G_\n", 148934.1432);
//	printf("%'d_\n", 1000000000);


//	int i = 42;
//	int *i0 = &i;
//	int *i1 = i0;
//	int *i2 = i1;
//	printf("%-32p%-32p%-32p%-32p%-32p%-32p_", &i, &i0, &i1, &i2, &i, &i);
	
//	printf("%'f_\n", 1000000.655412);

//	printf("%'d_\n", 1000000);
//	ft_printf("%'d_\n", 1000000);

//	printf("%0-6d_\n", 1);
	printf("%0*.*i\n", 2, 2, 8);
	printf("%0*.*i\n", 2, -2, 8);
	ft_printf("%0*.*i\n", 2, 2, 8);
	ft_printf("%0*.*i\n", 2, -2, 8);
	printf("%.*i\n", -4, 8);
	ft_printf("%.*i\n", -4, 8);
	

	printf("%0*.*i_\n", -3, -5, 8);
	ft_printf("%0*.*i_\n", -3, -5, 8);
	printf("%0*.*i_\n", 2, -2, 8);
	printf("%0*.*i_\n", 2, 2, 8);
	ft_printf("%0*.*i_\n", 2, -2, 8);
	ft_printf("%0*.*i_\n", 2, 2, 8);


	double d = 42.1234;
	double e = 42.1277;
	double f = 40.19;

	(void)d;
	(void)e;
	(void)f;

	printf("%f_\n", d);
	ft_printf("%f_\n", d);
	printf("%f_\n", -3.85);
	ft_printf("%f_\n", -3.85);
	printf("%f_\n", 3.85);
	ft_printf("%f_\n", 3.85);

	printf("|%d|\n",    printf("%f", 23.00041));
	printf("|%d|\n", ft_printf("%f", 23.00041));

	printf("|%d|\n",    printf("%f", 0.9999999));
	printf("|%d|\n", ft_printf("%f", 0.9999999));

	printf("|%d|\n",    printf("%f", 42.123));
	printf("|%d|\n", ft_printf("%f", 42.123));

	printf("|%d|\n",    printf("%f", 0.000039));
	printf("|%d|\n", ft_printf("%f", 0.000039));

	printf("|%d|\n",    printf("%.7f", 0.000039));
	printf("|%d|\n", ft_printf("%.7f", 0.000039));

	printf("|%d|\n",    printf("%f", 999.999999));
	printf("|%d|\n", ft_printf("%f", 999.999999));

//	printf("%f_\n", 0.0);
//	ft_printf("%f_\n", 0.0);
//	printf("%f_\n", f);
//	ft_printf("%f_\n", f);
//	printf("%f_\n", e);
//	ft_printf("%f_\n", e);

	printf("|%d|\n",    printf("%f", 43.924));
	printf("|%d|\n", ft_printf("%f", 43.924));

	printf("|%d|\n",    printf("%f", 42.925));
	printf("|%d|\n", ft_printf("%f", 42.925));

	printf("|%d|\n",    printf("%f", 42.926));
	printf("|%d|\n", ft_printf("%f", 42.926));

	printf("|%d|\n",    printf("%f", 42.12345));
	printf("|%d|\n", ft_printf("%f", 42.12345));



	printf("\n\n\n");
    printf("%0*.*i_\n", 2, -2, 8);
    ft_printf("%0*.*i_\n", 2, -2, 8);
    printf("%.*i_\n", -4, 8);
    ft_printf("%.*i_\n", -4, 8);

*/
/*
	   printf("%'d\n", 10);
	ft_printf("%'d\n", 10);
	   printf("%'d\n", 100);
	ft_printf("%'d\n", 100);
	   printf("%'d\n", 1000);
	ft_printf("%'d\n", 1000);
	   printf("%'d\n", 10000);
	ft_printf("%'d\n", 10000);
	   printf("%'d\n", 100000);
	ft_printf("%'d\n", 100000);
	   printf("%'d\n", 1000000);
	ft_printf("%'d\n", 1000000);
	   printf("%'d\n", 10000000);
	ft_printf("%'d\n", 10000000);
*/

/*
	   printf("%e\n", 0.1);
	ft_printf("%e\n", 0.1);
	   printf("%e\n", 1.00);
	ft_printf("%e\n", 1.00);
	   printf("%e\n", 2.00);
	ft_printf("%e\n", 2.00);
	   printf("%e\n", 9.00);
	ft_printf("%e\n", 9.00);
	   printf("%e\n", 10.00);
	ft_printf("%e\n", 10.00);
	   printf("%e\n", -1230400.0);
	ft_printf("%e\n", -1230400.0);
	   printf("%.19e\n", -9.000000005);
	ft_printf("%.19e\n", -9.000000005);

	ft_printf("\n\n\n\n");
	printf("%e\n", 9.00);
	ft_printf("%e\n", 9.00);
	printf("%e\n", 10.00);
	ft_printf("%e\n", 10.00);
	printf("%e\n", 101.00);
	ft_printf("%e\n", 101.00);
*/
	printf("%g\n", 1.13);
	ft_printf("%g\n", 1.13);
	printf("%f\n", 1.13);
	ft_printf("%f\n", 1.13);
	printf("%e\n", 1.13);
	ft_printf("%e\n", 1.13);

	printf("%.15g\n", 1.1353255243);
	printf("%g\n", 0.00003);


}
