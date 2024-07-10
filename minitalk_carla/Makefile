# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bama <bama@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 16:25:51 by cachetra          #+#    #+#              #
#    Updated: 2024/07/10 21:16:46 by bama             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = ./server

CLIENT = ./client

S_SRCS =	./srcs/server.c \

C_SRCS =	./srcs/client.c \

INCLUDES = -I ./includes

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = ./objs

S_OBJS = $(S_SRCS:%.c=$(OBJS_DIR)/%.o)

C_OBJS = $(C_SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(SERVER) $(CLIENT)

$(SERVER):$(S_OBJS)
	$(CC) $(CFLAGS) $(S_OBJS) -o $@

$(CLIENT):$(C_OBJS)
	$(CC) $(CFLAGS) $(C_OBJS) -o $@

$(OBJS_DIR)/%.o:%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean:	clean
		rm -f $(SERVER) $(CLIENT)

re: fclean all

bonus: all

.PHONY: all clean fclean re bonus