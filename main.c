/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:47:31 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/08 19:34:52 by juligonz         ###   ########.fr       */
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
	

	char *locale_changed;
	locale_changed = setlocale(LC_ALL, "fr_FR.UTF-8");
//	locale_changed = setlocale(LC_ALL, "");
//	locale_changed = setlocale(LC_ALL, "chs");
//	locale_changed = setlocale(LC_ALL, "chinese-simplified");

	if (locale_changed == NULL)
		printf("\n|||||||||| ERROR : Unable to set locale ||||||||\n");
	
	wchar_t *ws = L"Salut Gérard !";
	char *s = "Salut Gérard !";

	printf("____________________________________________\n");
	printf("|||||||||||||||||||TEST|||||||||||||||||||||\n");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

	printf("|%d|r\n",    printf("Grâve."));
	printf("|%d|m\n", ft_printf("Grâve."));
	   
    ft_printf("++++++++++++++++++++++++===\n");
	
	printf("~~~~~~~~~~~~~~\n");
	printf("|%d|r\n",    printf("%s", s));
	printf("|%d|m\n", ft_printf("%s", s));
	
	printf("~~~~~~~~~~~~~~\n");
	printf("|%d|r\n",    printf("%ls", ws));
	printf("|%d|m\n", ft_printf("%ls", ws));

	printf("~~~~~~~~~~~~~~\n");
	printf("|%d|r\n",    printf("%S", ws));
	printf("|%d|m\n", ft_printf("%S", ws));

	
//	   printf( "%lc_\n", wc);
//	ft_printf( "%ls_\n", ws);
//	   printf( "%lc_\n", wc);
//	ft_printf( "%lc_\n", wc);
	
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
/*
	int64_t n_int = LONG_MAX;


	   printf( "d   = %d\n",   n_int);
	ft_printf( "d   = %d\n",   n_int);
  	   printf( "hd  = %hd\n",  n_int);
	ft_printf( "hd  = %hd\n",  n_int);
	   printf( "hhd = %hhd\n", n_int);
	ft_printf( "hhd = %hhd\n\n", n_int);

	   printf( "d   = %d\n",   n_int);
	ft_printf( "d   = %d\n",   n_int);
	   printf( "ld  = %ld\n",  n_int);
	ft_printf( "ld  = %ld\n",  n_int);
	   printf( "lld = %lld\n", n_int);
	ft_printf( "lld = %lld\n\n", n_int);



 */
