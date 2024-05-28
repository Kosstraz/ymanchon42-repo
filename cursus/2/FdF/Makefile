# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 16:21:19 by ymanchon          #+#    #+#              #
#    Updated: 2024/05/29 00:12:22 by ymanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC =	cc

SRCS =	./srcs/fdf_errors.c \
		./srcs/fdf_utils.c \
		./srcs/fdf_parsing.c \
		./srcs/fdf.c \

OBJS_DIR =		objs

OBJS =	$(SRCS:%.c=$(OBJS_DIR)/%.o)

OBJS_BONUS =	$(SRCS_BONUS:%.c=$(OBJS_DIR)/%.o)

INCLUDES =	-I ./includes/ -I $(PRINTF_P)/ -I $(LIBFT_P)/

CFLAGS =	-Wall -Wextra -Werror -D GNL_BUFFER_SIZE=100000

LIBFT_P		=	./libft
PRINTF_P	=	./ft_printf

LIB	=	$(LIBFT_P)/libft.a \
		$(PRINTF_P)/libftprintf.a \

all: $(NAME)

$(NAME): $(OBJS)
	make bonus -C $(LIBFT_P)
	make bonus -C $(PRINTF_P)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $@

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	rm $(LIBFT_P)/$(OBJS_DIR) -rf
	rm $(PRINTF_P)/$(OBJS_DIR) -rf
	rm $(OBJS_DIR) -rf

fclean: clean
	rm $(LIB) -f
	rm $(NAME) -f

re: fclean all

.PHONY: all clean fclean re bonus