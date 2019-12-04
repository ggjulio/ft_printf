/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:47:31 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/04 21:03:07 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_printf(const char *format, ...) __attribute__((format(printf,1,2)));

#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <stdint.h>

#include <wchar.h>


int 	main(void)
{
	uint64_t n = ULONG_MAX;

	(void)n;

	wchar_t ws[50] = L"Salut Gérard !";
	wchar_t wc = ws[7];

	   printf( "%ls_\n", ws);
	ft_printf( "%ls_\n", ws);
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
