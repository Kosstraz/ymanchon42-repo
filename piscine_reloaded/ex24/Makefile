# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 16:21:19 by ymanchon          #+#    #+#              #
#    Updated: 2024/05/13 17:43:00 by ymanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC =	cc

AR =	ar -rcs

SRCS =	./srcs/ft_putstr.c \
		./srcs/ft_swap.c \
		./srcs/ft_putchar.c \
		./srcs/ft_strlen.c \
		./srcs/ft_strcmp.c

OBJS_DIR =	objs

OBJS =	$(SRCS:%.c=$(OBJS_DIR)/%.o)

INCLUDES =	./includes/

CFLAGS =	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) -o $@ $(OBJS)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -I $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJS_DIR) -rf

fclean: clean
	rm $(NAME) -f

re: fclean all

.PHONY: all clean fclean re
