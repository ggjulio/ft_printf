/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_proto.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 20:46:39 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/25 20:47:08 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PRINTF_PROTO_H
# define PRINTF_PROTO_H

int				ft_printf(const char *format, ...) __attribute__((format(printf,1,2)));

#endif
