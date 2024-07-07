# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 16:21:19 by ymanchon          #+#    #+#              #
#    Updated: 2024/07/07 19:36:47 by ymanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ################ #
#*    COULEURS    *#
# ################ #

CLASSIC	=	\e[0m
RED_B	=	\e[1;31m
GREEN_B	=	\e[1;32m
YELLO	=	\e[33m

# ############### #
#*   VARIABLES   *#
# ############### #

NAME = fractol

CC =	cc

SRCS =	./srcs/utils.c \
		./srcs/hooks.c \
		./srcs/parsing.c \
		./srcs/drawing.c \
		./srcs/fractol.c \

OBJS_DIR =		objs

OBJS =	$(SRCS:%.c=$(OBJS_DIR)/%.obj)

DEPS =	$(OBJS:%.obj=%.d)

INCLUDES =	-I ./includes/ -I $(PRINTF_P)/ -I $(LIBFT_P)/ -I ./minilibx/ -I .

CFLAGS =	-Wall -Wextra -Werror -MMD

LIBFT_P		=	./libft
PRINTF_P	=	./ft_printf

LIB	=	$(LIBFT_P)/libft.a \

MLX =	-lX11 -lXext -lmlx_Linux -L ./minilibx/ -Imlx_Linux \
		-lm \

# ############## #
#*    REGLES    *#
# ############## #

all: _colorY_ $(NAME) _colorG_

$(NAME): $(OBJS)
	make -C $(LIBFT_P)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX) -o $@

$(OBJS_DIR)/%.obj: %.c
	@mkdir -p $(@D)
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

_colorY_:
	@echo "$(YELLO)Compilation en cours... ⚙️\n"

_colorR_:
	@echo "$(RED_B)"

_colorG_:
	@echo "$(GREEN_B)Compilation terminée 🗿\n$(CLASSIC)"

clean: _colorR_
	rm $(LIBFT_P)/$(OBJS_DIR) -rf
	rm $(OBJS_DIR) -rf

fclean: clean
	rm $(LIB) -f
	rm $(NAME) -f
	@echo "Tout à été supprimé... 🗑️\n$(CLASSIC)"

mlx:
	make -C ./minilibx

libft: _colorY_
	make -C $(LIBFT_P)

re: fclean mlx all

.PHONY: all clean fclean mlx libft re
-include $(DEPS)