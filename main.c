/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:47:31 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/26 19:17:39 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include "printf_proto.h"

#include <stdio.h>
#include <locale.h>

int 	main(void)
{
    setlocale(LC_NUMERIC, "en_US");
/*
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

	printf("|%d|\n",    printf("%f", 43.924));
	printf("|%d|\n", ft_printf("%f", 43.924));

	printf("|%d|\n",    printf("%f", 42.925));
	printf("|%d|\n", ft_printf("%f", 42.925));

	printf("|%d|\n",    printf("%f", 42.926));
	printf("|%d|\n", ft_printf("%f", 42.926));

	printf("|%d|\n",    printf("%f", 42.12345));
	printf("|%d|\n", ft_printf("%f", 42.12345));

	ft_printf("%Lf\n", -958.125l);
	ft_printf("%Lf\n", -958.125L);
	printf("%Lf\n", -958.125l);
	printf("%Lf\n", -958.125L);



	printf("\n\n\n");

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

	printf("%g\n", 1.13);
	ft_printf("%g\n", 1.13);
	printf("%f\n", 1.13);
	ft_printf("%f\n", 1.13);
	printf("%e\n", 1.13);
	ft_printf("%e\n", 1.13);

	printf("%.15g\n", 1.1353255243);
	printf("%g\n", 0.00003);

	   printf("%e\n", 0.1);
	ft_printf("%e\n", 0.1);
	   printf("%e\n", 0.01);
	ft_printf("%e\n", 0.01);
	   printf("%e\n", 0.04);
	ft_printf("%e\n", 0.04);
	   printf("%e\n", 0.0042);
	ft_printf("%e\n", 0.0042);
*/
	printf("%#8.5o_\n", 34);
	ft_printf("%#8.5o_\n", 34);
	printf("%#-8.5o_\n", 34);
	ft_printf("%#-8.5o_\n", 34);

	printf("%'f_\n", 1234.735268);
	ft_printf("%'f_\n", 1234.735268);
	printf("%'f_\n", 12343243244.735268);
	ft_printf("%'f_\n", 12343243244.735268);
	ft_printf("%'f_\n", 124.735268);
	printf("%'f_\n", 124.735268);
	ft_printf("%'f_\n", 1234.735268);
	printf("%'f_\n", 1234.735268);
	ft_printf("%'f_\n", 1000000.00000);
}
