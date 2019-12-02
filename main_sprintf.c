/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:34:13 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/02 14:50:03 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "printf_proto.h"
#include "ft_printf.h"

int main(void)
{
	char test[15];

	ft_memset(test, 0, 10);
	ft_sprintf(test, "123456789A");
	ft_printf("sprintf>>>>%s|\n", test);

}
