# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 16:21:19 by ymanchon          #+#    #+#              #
#    Updated: 2024/06/10 13:00:37 by ymanchon         ###   ########.fr        #
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

CLIENT_NAME	=	client
SERVER_NAME	=	server

CC =	cc

CLIENT_SRCS =	./client.c \
				./client2.c
SERVER_SRCS =	./server.c \
				./server2.c

OBJS_DIR =		objs

CLIENT_OBJS =	$(CLIENT_SRCS:%.c=$(OBJS_DIR)/%.obj)
SERVER_OBJS =	$(SERVER_SRCS:%.c=$(OBJS_DIR)/%.obj)

INCLUDES =	-I $(PRINTF_P)/

CFLAGS =	-Wall -Wextra -Werror

PRINTF_P	=	./ft_printf

LIB	=	$(PRINTF_P)/libftprintf.a

# ############## #
#*    REGLES    *#
# ############## #

all: _colorY_ $(CLIENT_NAME) $(SERVER_NAME) _colorG_

$(CLIENT_NAME): $(CLIENT_OBJS)
	make bonus -C $(PRINTF_P)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) $(LIB) -o $@

$(SERVER_NAME): $(SERVER_OBJS)
	make bonus -C $(PRINTF_P)
	$(CC) $(CFLAGS) $(SERVER_OBJS) $(LIB) -o $@

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
	rm $(PRINTF_P)/$(OBJS_DIR) -rf
	rm $(OBJS_DIR) -rf

fclean: clean
	rm $(LIB) -f
	rm $(CLIENT_NAME) -f
	rm $(SERVER_NAME) -f
	@echo "Tout à été supprimé... 🗑️\n$(CLASSIC)"

re: fclean all

.PHONY: all clean fclean re