/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:44:54 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/06 17:59:04 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putstr_fd(char const *s, int fd)
{
	int len;

	write(fd, s, (len = ft_strlen(s)));
	return (len);
	// modify to return ssize_t from write
}
