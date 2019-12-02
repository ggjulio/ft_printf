/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:34:13 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/02 19:09:30 by juligonz         ###   ########.fr       */
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
	char *test;
	int ret;

	ret = ft_asprintf(&test, "123456%s", "7890");
	ft_printf("asprintf>>|ret:%d|>>%s|\n", ret, test);
	free(test);
}
