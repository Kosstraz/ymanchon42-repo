# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 15:08:58 by ymanchon          #+#    #+#              #
#    Updated: 2024/03/21 15:51:24 by ymanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

INCLUDES = ./includes/ft_libprintf.h \

SRCS =  ./srcs/ft_hexa.c \
		./srcs/ft_printf.c \
		./srcs/ft_showptr.c \
		./srcs/ft_utils.c \
		./srcs/ft_utils2.c \

OBJS = $(patsubst %.c,%.o,$(SRCS))

FLAGS = -Wall -Wextra #-Werror

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(OBJS): $(SRCS)
	gcc $(FLAGS) $< -c -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re