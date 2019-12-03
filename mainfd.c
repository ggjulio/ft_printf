/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:34:13 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/03 15:55:29 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include "printf_proto.h"

int main(void)
{
	int fd = -1;
	char *file = "test.txt";

	fd = open(file, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
	if (fd >= 1)
		ft_printf("|fd:%d|ret:%d| output in \"%s\"", fd, ft_dprintf(fd, "%s|%d|\nok", "THE  test\n", 422), file);
	else
		write(1, "fd < 1|", 7);
	close(fd);
}
