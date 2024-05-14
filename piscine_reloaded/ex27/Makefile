# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 16:21:19 by ymanchon          #+#    #+#              #
#    Updated: 2024/05/14 17:36:01 by ymanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_display_file

CC =	cc

SRCS =	./srcs/ft_display_file

OBJS_DIR =	objs

OBJS =	$(SRCS:%.c=$(OBJS_DIR)/%.o)

INCLUDES = ./includes/

CFLAGS =	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) -I $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJS_DIR) -rf

fclean: clean
	rm $(NAME) -f

re: fclean all

.PHONY: all clean fclean re
