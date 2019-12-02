/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:34:13 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/02 19:35:09 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "printf_proto.h"
#include "ft_printf.h"

#define ARR_SIZE 20

int main(void)
{
	char test[ARR_SIZE];
	int ret;

	ft_memset(test, 0, ARR_SIZE);
	ret = ft_sprintf(test, "0123456789|%d", 16);
	ft_printf("sprintf>>|ret:%d|>>\n%s", ret, test);

}
