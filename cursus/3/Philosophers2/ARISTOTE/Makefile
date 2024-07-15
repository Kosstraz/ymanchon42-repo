# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bama <bama@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 16:21:19 by ymanchon          #+#    #+#              #
#    Updated: 2024/07/14 21:03:11 by bama             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ############### #
#*   VARIABLES   *#
# ############### #

NAME = aristote

CC =	cc

SRCS =	./srcs/utils.c \
		./srcs/signals_handle.c \
		./srcs/ft_split.c \
		./srcs/ft_strjoin.c \
		./srcs/freemem.c \
		./srcs/get_next_line_utils.c \
		./srcs/get_next_line.c \
		./srcs/parsing.c \
		./srcs/aristote.c \

OBJS_DIR =		objs

OBJS =	$(SRCS:%.c=$(OBJS_DIR)/%.obj)

DEPS =	$(OBJS:%.obj=%.d)

INCLUDES =	-I ./includes/

CFLAGS =	-Wall -Wextra -MMD #-fsanitize=thread -g -Werror

LIB = 	-lpthread

# ############## #
#*    REGLES    *#
# ############## #

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIB) $(MLX) -o $@

$(OBJS_DIR)/%.obj: %.c
	@mkdir -p $(@D)
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	rm $(LIBFT_P)/$(OBJS_DIR) -rf
	rm $(OBJS_DIR) -rf

fclean: clean
	rm $(NAME) -f
	@echo "Tout à été supprimé... 🗑️\n$(CLASSIC)"

re: fclean all

.PHONY: all clean fclean re
-include $(DEPS)
