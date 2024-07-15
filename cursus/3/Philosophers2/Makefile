# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 16:21:19 by ymanchon          #+#    #+#              #
#    Updated: 2024/07/15 18:53:38 by ymanchon         ###   ########.fr        #
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

NAME = philo

CC =	cc

SRCS =	./srcs/ft_atoi.c \
		./srcs/args_handle.c \
		./srcs/utils.c \
		./srcs/utils2.c \
		./srcs/philo_fct.c \
		./srcs/philo_fct2.c \
		./srcs/philo.c \

OBJS_DIR =		objs

OBJS =	$(SRCS:%.c=$(OBJS_DIR)/%.obj)

DEPS =	$(OBJS:%.obj=%.d)

NAME_BONUS = philo_bonus

SRCS_BONUS =	./bonus/ft_atoi.c \
				./bonus/args_handle.c \
				./bonus/utils.c \
				./bonus/utils2.c \
				./bonus/philo_fct.c \
				./bonus/philo_fct2.c \
				./bonus/philo.c \

OBJS_BONUS =	$(SRCS_BONUS:%.c=$(OBJS_DIR)/%.obj)

DEPS_BONUS =	$(OBJS_BONUS:%.obj=%.d)

INCLUDES =	-I ./includes/ -I $(PRINTF_P)/ -I $(LIBFT_P)/ -I ./minilibx/ -I .

CFLAGS =	-Wall -Wextra -MMD #-fsanitize=thread -g -Werror

LIB =	-lpthread

# ############## #
#*    REGLES    *#
# ############## #

all: _colorY_ $(NAME) _colorG_

$(NAME): $(OBJS)
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
	rm $(NAME) -f
	rm $(NAME_BONUS) -f
	@echo "Tout à été supprimé... 🗑️\n$(CLASSIC)"

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIB) -o $@

.PHONY: all clean fclean re bonus
-include $(DEPS) $(DEPS_BONUS)
