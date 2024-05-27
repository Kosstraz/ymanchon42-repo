# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 16:21:19 by ymanchon          #+#    #+#              #
#    Updated: 2024/05/27 18:15:36 by ymanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC =	cc

AR =  ar -rcs

SRCS =	./srcs/ft_printf_utils.c \
		./srcs/ft_printf_utils2.c \
		./srcs/ft_hexa.c \
		./srcs/ft_showptr.c \
		./srcs/ft_printf.c \

SRCS_BONUS =	./bonus/ft_printf_handle_bonus.c \

OBJS_DIR =		objs

OBJS =	$(SRCS:%.c=$(OBJS_DIR)/%.o)

OBJS_BONUS =	$(SRCS_BONUS:%.c=$(OBJS_DIR)/%.o)

INCLUDES = -I .

CFLAGS =	-Wall -Wextra -Werror

BONUS_FLAGS =	-D BONUS_PART=1

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) -o $@ $(OBJS)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

$(OBJS_DIR_B)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(INCLUDES)$(CFLAGS) $(BONUS_FLAG) -c $< -o $@

clean:
	rm $(OBJS_DIR) -rf

fclean: clean
	rm $(NAME) -f

re: fclean all

bonus: CFLAGS += $(BONUS_FLAGS)
bonus: fclean all $(OBJS_BONUS)
	$(AR) -o $(NAME) $(OBJS_BONUS)

.PHONY: all clean fclean re bonus
