#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 14:58:05 by juligonz          #+#    #+#              #
#    Updated: 2019/11/17 17:36:39 by juligonz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRCS =	srcs/ft_printf.c 			\
		srcs/ft_putnbr_base_fd.c		\
		srcs/ft_putstr_range.c		\
		srcs/ft_strlen.c				\
		srcs/conversions.c			\


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