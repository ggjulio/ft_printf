/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:47:31 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/13 15:13:07 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_printf(const char *format, ...) __attribute__((format(printf,1,2)));

#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <stdint.h>
#include <locale.h>

#include <wchar.h>


int 	main(void)
{
	uint64_t n = ULONG_MAX;
	(void)n;
//	locale_changed =  setlocale(LC_NUMERIC, "en_US");
	

	char *locale_changed = NULL;

	(void)locale_changed;
//	locale_changed = setlocale(LC_ALL, "fr_FR.UTF-8");
//	locale_changed = setlocale(LC_ALL, "chinese-simplified");

//	if (locale_changed == NULL)
//		printf("\n|||||||||| ERROR : Unable to set locale ||||||||\n");

	locale_changed = setlocale(LC_ALL, "");

	
	int i;

	i = 240;
	while (i <= 350)
	{
	       printf("|%d|%d|\n",    printf("|%lc", i), i);
//		ft_printf("|%d|%d|\n", ft_printf("|%lc", i), i);
//		   printf("|%d|%d|\n",    printf("%c", i), i);
//		ft_printf("|%d|%d|\n", ft_printf("%c", i), i);
		i++;
	}

//	wchar_t *ws = L"\u00f6\u00e7\u015f\u0131\u011f";

//	   printf("|%d|", printf("%ls", ws));
//	ft_printf("|%d|", printf("%ls", ws));
	
//	printf("ÉGÉìÉRÅ[ÉfÉBÉìÉOÇÕìÔÇµÇ≠Ç»Ç¢\n");
//	ft_printf("ÉGÉìÉRÅ[ÉfÉBÉìÉOÇÕìÔÇµÇ≠Ç»Ç¢\n");

//	printf("|%d|\n", printf("%c", 19001));
//	ft_printf("|%d|\n", ft_printf("%c", 19001));


	
/*
	   printf( "%g\n", -0.0);
	ft_printf( "%g\n", -0.0);
	   printf( "%f\n", -0.0);
	ft_printf( "%f\n", -0.0);
	   printf( "%e\n", -0.0);
	ft_printf( "%e\n", -0.0);

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
*/
	
}
