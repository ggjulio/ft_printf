/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:47:31 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/13 18:02:00 by juligonz         ###   ########.fr       */
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
//	locale_changed =  setlocale(LC_NUMERIC, "en_US");
	

	char *locale_changed = NULL;

	(void)locale_changed;
//	locale_changed = setlocale(LC_ALL, "fr_FR.UTF-8");
//	locale_changed = setlocale(LC_ALL, "chinese-simplified");

//	if (locale_changed == NULL)
//		printf("\n|||||||||| ERROR : Unable to set locale ||||||||\n");

//	locale_changed = setlocale(LC_ALL, "");

	test_ls(L"fb1feafewfefewfe");
	test_ls(L"ffb1fefwefew");
	test_ls(L"");
	test_ls(L"a");
	test_ls(L"55555555555555555555555555555555555555555555");
	
// printf -1

	test_ls(L"\u0b11");


	test_ls(L"\uffb1feafewfefewfe");
	
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
