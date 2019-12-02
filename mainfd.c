/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainfd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 18:34:13 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/02 11:34:53 by juligonz         ###   ########.fr       */
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
	int fd;

	fd = open("test2.txt", O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
	if (fd > 1)
		ft_dprintf(fd, "%s|%d|\nok", "test\n", 422);
	else
		write(1, "|error|", 7);
	close(fd);
}
