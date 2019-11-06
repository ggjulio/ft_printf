/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 18:10:37 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/06 18:12:02 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putstr_range(char const *s_begin, char const *s_end)
{
	int n;

	n = s_end - s_begin;
	write(1, s_begin, n);
	return (n);
}
