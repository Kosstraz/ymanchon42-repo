# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 16:21:19 by ymanchon          #+#    #+#              #
#    Updated: 2024/05/13 17:37:11 by ymanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_printf.a

CC =	cc

AR =  ar -rcs

SRCS =	./srcs/ft_utils.c \
		./srcs/ft_utils2.c \
		./srcs/ft_hexa.c \
		./srcs/ft_showptr.c \
		./srcs/ft_printf.c

OBJS_DIR =	objs

OBJS =	$(SRCS:%.c=$(OBJS_DIR)/%.o)

INCLUDES = ./includes/

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