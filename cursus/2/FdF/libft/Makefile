# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 16:21:19 by ymanchon          #+#    #+#              #
#    Updated: 2024/05/29 14:32:58 by ymanchon         ###   ########.fr        #
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
		./gnl/get_next_line_utils_bonus.c \
		./gnl/get_next_line_bonus.c \
		./others/ft_count_words.c \
		./others/ft_intlen.c \
		./parsing/ft_isspace.c \
		./parsing/ft_rev_isspace.c \

SRCS_BONUS =	./bonus/ft_lstadd_back_bonus.c \
				./bonus/ft_lstadd_front_bonus.c \
				./bonus/ft_lstclear_bonus.c \
				./bonus/ft_lstdelone_bonus.c \
				./bonus/ft_lstiter_bonus.c \
				./bonus/ft_lstlast_bonus.c \
				./bonus/ft_lstmap_bonus.c \
				./bonus/ft_lstnew_bonus.c \
				./bonus/ft_lstsize_bonus.c \

OBJS_DIR =	objs

OBJS =			$(SRCS:%.c=$(OBJS_DIR)/%.o)
OBJS_BONUS =	$(SRCS_BONUS:%.c=$(OBJS_DIR)/%.o)

INCLUDES = -I .

CFLAGS =	-Wall -Wextra -Werror

PRINTF_P = ./ft_printf

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(PRINTF_P)
	$(AR) -o $@ $(PRINTF_P)/objs/*/*.o
	$(AR) -o $@ $(OBJS)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

clean:
	rm $(OBJS_DIR) -rf

fclean: clean
	rm $(NAME) -f

re: fclean all

bonus: all $(OBJS_BONUS)
	$(AR) -o $(NAME) $(OBJS_BONUS)

.PHONY: all clean fclean re bonus