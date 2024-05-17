# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanchon <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 16:21:19 by ymanchon          #+#    #+#              #
#    Updated: 2024/05/16 16:48:04 by ymanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC =	cc

AR =  ar -rcs

SRCS =  ./srcs/ft_atoi.c \
		./srcs/ft_bzero.c \
		./srcs/ft_calloc.c \
		./srcs/ft_isalnum.c \
		./srcs/ft_isalpha.c \
		./srcs/ft_isascii.c \
		./srcs/ft_isdigit.c \
		./srcs/ft_isprint.c \
		./srcs/ft_itoa.c \
		./srcs/ft_memchr.c \
		./srcs/ft_memcmp.c \
		./srcs/ft_memcpy.c \
		./srcs/ft_memmove.c \
		./srcs/ft_memset.c \
		./srcs/ft_putchar_fd.c \
		./srcs/ft_putendl_fd.c \
		./srcs/ft_putnbr_fd.c \
		./srcs/ft_putstr_fd.c \
		./srcs/ft_split.c \
		./srcs/ft_strchr.c \
		./srcs/ft_strdup.c \
		./srcs/ft_striteri.c \
		./srcs/ft_strjoin.c \
		./srcs/ft_strlen.c \
		./srcs/ft_strmapi.c \
		./srcs/ft_strncmp.c \
		./srcs/ft_strrchr.c \
		./srcs/ft_strtrim.c \
		./srcs/ft_strlcpy.c \
		./srcs/ft_strlcat.c \
		./srcs/ft_substr.c \
		./srcs/ft_tolower.c \
		./srcs/ft_toupper.c \
		./srcs/ft_strnstr.c \

SRCS_BONUS =	./srcs/ft_lstadd_back_bonus.c \
				./srcs/ft_lstadd_front_bonus.c \
				./srcs/ft_lstclear_bonus.c \
				./srcs/ft_lstdelone_bonus.c \
				./srcs/ft_lstiter_bonus.c \
				./srcs/ft_lstlast_bonus.c \
				./srcs/ft_lstmap_bonus.c \
				./srcs/ft_lstnew_bonus.c \
				./srcs/ft_lstsize_bonus.c \

OBJS_DIR =	objs

OBJS =			$(SRCS:%.c=$(OBJS_DIR)/%.o)
OBJS_BONUS =	$(SRCS_BONUS:%.c=$(OBJS_DIR)/%.o)

INCLUDES = ./includes/

CFLAGS =	-Wall -Wextra -Werror

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

bonus: $(OBJS) $(OBJS_BONUS)
	$(AR) -o $@ $(OBJS)
	$(AR) -o $@ $(OBJS_BONUS)

.PHONY: all clean fclean re
