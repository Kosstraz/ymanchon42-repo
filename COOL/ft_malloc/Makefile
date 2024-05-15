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

######################### VARIABLES #########################

NAME = ft_malloc.a

CC =	cc

AR =	ar -rcs

SRCS =	./srcs/ft_allocstate_handle.c \
		./srcs/ft_malloc.c \

OBJS_DIR =	objs

OBJS =	$(SRCS:%.c=$(OBJS_DIR)/%.o)

INCLUDES = ./includes/

CFLAGS =	-Wall -Wextra -Werror

######################### CONDITIONS #########################

#ifeq ($(HOSTTYPE),)
#	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
#	$(NAME) += $(HOSTTYPE)
#endif

######################### REGLES #########################

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