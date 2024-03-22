# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/18 15:08:58 by ymanchon          #+#    #+#              #
#    Updated: 2024/03/21 16:24:43 by ymanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

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
		./srcs/ft_substr.c \
		./srcs/ft_tolower.c \
		./srcs/ft_toupper.c \

SRCS_BONUS =	./bonus/ft_lstadd_back_bonus.c \
				./bonus/ft_lstadd_front_bonus.c \
				./bonus/ft_lstclear_bonus.c \
				./bonus/ft_lstdelone_bonus.c \
				./bonus/ft_lstiter_bonus.c \
				./bonus/ft_lstlast_bonus.c \
				./bonus/ft_lstmap_bonus.c \
				./bonus/ft_lstnew_bonus.c \
				./bonus/ft_lstsize_bonus.c \

OBJS = $(patsubst %.c,%.o,$(SRCS))
OBJS_BONUS = $(patsubst %.c,%.o,$(SRCS_BONUS))

FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

$(NAME_BONUS): $(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS_BONUS)

$(OBJS): $(SRCS)
	gcc $(FLAGS) $< -c -o $@

$(OBJS_BONUS): $(SRCS_BONUS)
	gcc $(FLAGS) $< -c -o $@

all: $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS_BONUS) $(OBJS)
	ar -rcs $(NAME) $(OBJS_BONUS) $(OBJS)

.PHONY: all clean fclean re bonus
