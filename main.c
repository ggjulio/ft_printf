/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:47:31 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/13 18:29:50 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_printf(const char *format, ...) __attribute__((format(printf,1,2)));

#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <stdint.h>
#include <locale.h>

#include <wchar.h>

void	test_ls(wchar_t *ws)
{
	   printf("|%d|\n",    printf("%ls", ws));
	ft_printf("|%d|\n", ft_printf("%ls", ws));
}

int 	main(void)
{
	uint64_t n = ULONG_MAX;
	(void)n;

//	locale_changed = setlocale(LC_ALL, "");


	   printf( "%g\n", -0.1);
	ft_printf( "%g\n", -0.1);
	   printf( "%g\n", -543.1);
	ft_printf( "%g\n", -543.1);

	   printf( "%g\n", -543.1543);
	ft_printf( "%g\n", -543.1543);
	   printf( "%g\n", -543.15432);
	ft_printf( "%g\n", -543.15432);

	   printf( "%g\n", -543.15432);
	ft_printf( "%g\n", -543.15432);

	printf( "\n");
	   printf( "%g\n", 543.1543);
	ft_printf( "%g\n", 543.1543);
	   printf( "%g\n", 543.15432);
	ft_printf( "%g\n", 543.15432);
	   printf( "%g\n", 543.154321);
	ft_printf( "%g\n", 543.154321);


	   printf( "%g\n", 0.0);
	ft_printf( "%g\n", 0.0);
	   printf( "%g\n", -120.4254);
	ft_printf( "%g\n", -120.4254);
	   printf( "%g\n", 120.4254);
	ft_printf( "%g\n", 120.4254);
	   printf( "%g\n", 1120.4254);
	ft_printf( "%g\n", 1120.4254);
	   printf( "%g\n", 11230.4254);
	ft_printf( "%g\n", 11230.4254);
	   printf( "%g\n", 11230.425454);
	ft_printf( "%g\n", 11230.425454);
	   printf( "%g\n", 10.425454);
	ft_printf( "%g\n", 10.425454);
	   printf( "%g\n", 0.425454);
	ft_printf( "%g\n", 0.425454);
	   printf( "%g\n", 41.0);
	ft_printf( "%g\n", 41.0);
	   printf( "%g\n", 0.0344313);
	ft_printf( "%g\n", 0.0344313);
	   printf( "%g\n", 0.034431213);
	ft_printf( "%g\n", 0.034431213);
	   printf( "%.8g\n", 0.034431213);
	ft_printf( "%.8g\n", 0.034431213);
	   printf( "%.8g\n", 0.034431213);
	ft_printf( "%.8g\n", 0.034431213);
	   printf( "%g\n", 0.00034431213);
	ft_printf( "%g\n", 0.00034431213);
	   printf( "%g\n", 0.0000344312);
	ft_printf( "%g\n", 0.0000344312);
	   printf( "%g\n", 300000.0);
	ft_printf( "%g\n", 300000.0);
	   printf( "%g\n", 3000000.0);
	ft_printf( "%g\n", 3000000.0);
	   printf( "%g\n", -300000.0);
	ft_printf( "%g\n", -300000.0);
	   printf( "%g\n", -3000000.0);
	ft_printf( "%g\n", -3000000.0);

	
}
