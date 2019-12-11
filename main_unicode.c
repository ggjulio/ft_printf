/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_unicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 18:09:17 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/11 18:09:47 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"

int count_active_bits(int c_uni)
{
	int count_b;

	count_b = 0;
	while (c_uni)
	{
		c_uni = c_uni >> 1;
		count_b++;
	}
	return (count_b);
}

int main(void)
{
    int     c_uni;
    int bits_amt;

    c_uni = 986;
    bits_amt = count_active_bits(c_uni);
    printf("There are %d bits in input number.\n", bits_amt);
    return (0);
}
