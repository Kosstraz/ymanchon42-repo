# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 16:21:19 by ymanchon          #+#    #+#              #
#    Updated: 2024/05/16 17:24:14 by ymanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

CC =	cc

SRCS =	./srcs/get_next_line_utils.c \
		./srcs/get_next_line.c \
		./main.c \

OBJS_DIR =	objs

OBJS =	$(SRCS:%.c=$(OBJS_DIR)/%.o)

INCLUDES = -I .

CFLAGS =	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJS_DIR) -rf

fclean: clean
	rm $(NAME) -f

re: fclean all

.PHONY: all clean fclean re
