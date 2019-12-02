/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:34:13 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/02 18:05:07 by juligonz         ###   ########.fr       */
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

	ft_asprintf(&test, "123456%s", "jfewkjfjkew");
	ft_printf("asprintf>>>>%s|\n", test);
	free(test);
}
