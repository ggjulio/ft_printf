#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 14:58:05 by juligonz          #+#    #+#              #
#    Updated: 2019/12/02 15:41:57 by juligonz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRCS =	srcs/ft_printf.c 				\
		srcs/ft_dprintf.c				\
		srcs/ft_sprintf.c				\
		srcs/ft_strlen.c				\
		srcs/ft_strncpy.c				\
		srcs/ft_isdigit.c				\
		srcs/ft_memset.c				\
		srcs/cast_len_modifier.c		\
		srcs/put_dec.c					\
		srcs/put_hex.c					\
		srcs/put_oct.c					\
		srcs/put_ptr.c					\
		srcs/put_double.c				\
		srcs/put_e.c					\
		srcs/put_g.c					\
		srcs/read_flags.c				\
		srcs/parse.c					\
		srcs/double_utils.c				\
		srcs/double_utils_2.c			\
		srcs/write_buffer.c				\
		srcs/convs/conv_c.c				\
		srcs/convs/conv_s.c				\
		srcs/convs/conv_p.c				\
		srcs/convs/conv_d.c				\
		srcs/convs/conv_i.c				\
		srcs/convs/conv_u.c				\
		srcs/convs/conv_x_lowcase.c		\
		srcs/convs/conv_x_upcase.c		\
		srcs/convs/conv_n.c				\
		srcs/convs/conv_f.c				\
		srcs/convs/conv_g.c				\
		srcs/convs/conv_e.c				\
		srcs/convs/conv_o.c				\
		srcs/convs/conv_mod.c			\

OBJ = $(SRCS:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror -I./includes

all: $(NAME) $(NAME_BONUS)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	$(info Compiled $(NAME))

clean:
	@rm -f $(OBJ)
	$(info .o removed !)

fclean: clean
	@rm -f $(NAME)
	$(info lib removed !)

bonus: $(NAME)

re: fclean all

.PHONY: clean fclean re all bonus