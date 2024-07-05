# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 16:21:19 by ymanchon          #+#    #+#              #
#    Updated: 2024/07/05 15:33:30 by ymanchon         ###   ########.fr        #
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

NAME	=	push_swap

CC =	cc

SRCS =	./srcs/ps_inst_p.c \
		./srcs/ps_inst_r.c \
		./srcs/ps_inst_rr.c \
		./srcs/ps_inst_s.c \
		./srcs/ps_parsing.c \
		./srcs/ps_sort.c \
		./srcs/ps_big_sort.c \
		./srcs/ps_handle.c \
		./srcs/ps_opti.c \
		./srcs/push_swap.c \

OBJS_DIR =		objs

OBJS =	$(SRCS:%.c=$(OBJS_DIR)/%.obj)

DEPS =	$(OBJS:$(OBJS_DIR)/%.obj=%.d)

INCLUDES =	-I $(LIBFT_P)/ -I .

CFLAGS =	-MMD -Wall -Wextra #-Werror

LIBFT_P	=	./libft

LIB	=	$(LIBFT_P)/libft.a

SMAKE =	make --no-print-directory

# ############## #
#*    REGLES    *#
# ############## #

all: _colorY_ $(NAME) _colorG_

$(NAME): $(OBJS)
	make -C $(LIBFT_P)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $@

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

re: fclean all

.PHONY: all clean fclean re
-include $(DEPS)