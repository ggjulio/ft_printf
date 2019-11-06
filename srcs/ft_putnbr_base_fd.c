/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:42:57 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/06 17:58:00 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	ft_u(unsigned long long n, unsigned int *base, int *fd, int *upcase)
{
	char c;

	if (n >= *base)
		ft_putnbru_base_fd(n / *base, base, fd, upcase);
	c = n % *base + '0';
	if (c > '9')
		c += 39;
	if (*upcase)
		c -= 32;
	ft_putchar_fd(c, *fd);
}

int			t_putnbr_base_fd(long long n, unsigned int base, int fd, int upcase)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_u(-n, &base, &fd, &upcase);
	}
	else
		ft_u(n, &base, &fd, &upcase);
	return (-1000);
	// TODO return len
}
