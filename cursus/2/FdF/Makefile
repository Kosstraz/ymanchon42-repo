# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 16:21:19 by ymanchon          #+#    #+#              #
#    Updated: 2024/05/29 18:18:10 by ymanchon         ###   ########.fr        #
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

NAME = fdf

CC =	cc

SRCS =	./srcs/fdf_errors.c \
		./srcs/fdf_utils.c \
		./srcs/fdf_parsing.c \
		./srcs/fdf.c \

OBJS_DIR =		objs

OBJS =	$(SRCS:%.c=$(OBJS_DIR)/%.o)

OBJS_BONUS =	$(SRCS_BONUS:%.c=$(OBJS_DIR)/%.o)

INCLUDES =	-I ./includes/ -I $(PRINTF_P)/ -I $(LIBFT_P)/ -I ./minilibx/

CFLAGS =	-Wall -Wextra -Werror -D GNL_BUFFER_SIZE=100000

LIBFT_P		=	./libft
PRINTF_P	=	./ft_printf

LIB	=	$(LIBFT_P)/libft.a \

MLX =	-lX11 -lXext -lmlx_Linux -L ./minilibx/ -Imlx_Linux \

# ############## #
#*    REGLES    *#
# ############## #

all: _colorY_ $(NAME) _colorG_

$(NAME): $(OBJS)
	make bonus -C $(LIBFT_P)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX) -o $@

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

_colorY_:
	@echo "$(YELLO)Compilation en cours...\n"

_colorR_:
	@echo "$(RED_B)"

_colorG_:
	@echo "$(GREEN_B)Compilation terminee :)\n$(CLASSIC)"

clean: _colorR_
	rm $(LIBFT_P)/$(OBJS_DIR) -rf
	rm $(OBJS_DIR) -rf

fclean: clean
	rm $(LIB) -f
	rm $(NAME) -f
	@echo "Tout a ete supprime... :(\n$(CLASSIC)"

re: fclean all

.PHONY: all clean fclean re
