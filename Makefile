#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/22 14:58:05 by juligonz          #+#    #+#              #
#    Updated: 2019/11/12 16:14:28 by juligonz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRCS =	ft_printf.c 			\
		ft_putnbr_base_fd.c		\
		ft_putstr_range.c		\
		ft_strlen.c				\
		conversions.c			\


OBJ = $(SRCS:.c=.o)

CFLAGS = -g -Wall -Wextra -Werror

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