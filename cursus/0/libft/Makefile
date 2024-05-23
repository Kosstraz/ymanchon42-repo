# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymanchon <ymanchon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/13 16:21:19 by ymanchon          #+#    #+#              #
#    Updated: 2024/05/23 13:37:34 by ymanchon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC =	cc

AR =  ar -rcs

SRCS =  ./ft_atoi.c \
		./ft_bzero.c \
		./ft_calloc.c \
		./ft_isalnum.c \
		./ft_isalpha.c \
		./ft_isascii.c \
		./ft_isdigit.c \
		./ft_isprint.c \
		./ft_itoa.c \
		./ft_memchr.c \
		./ft_memcmp.c \
		./ft_memcpy.c \
		./ft_memmove.c \
		./ft_memset.c \
		./ft_putchar_fd.c \
		./ft_putendl_fd.c \
		./ft_putnbr_fd.c \
		./ft_putstr_fd.c \
		./ft_split.c \
		./ft_strchr.c \
		./ft_strdup.c \
		./ft_striteri.c \
		./ft_strjoin.c \
		./ft_strlen.c \
		./ft_strmapi.c \
		./ft_strncmp.c \
		./ft_strrchr.c \
		./ft_strtrim.c \
		./ft_strlcpy.c \
		./ft_strlcat.c \
		./ft_substr.c \
		./ft_tolower.c \
		./ft_toupper.c \
		./ft_strnstr.c \

SRCS_BONUS =	./ft_lstadd_back_bonus.c \
				./ft_lstadd_front_bonus.c \
				./ft_lstclear_bonus.c \
				./ft_lstdelone_bonus.c \
				./ft_lstiter_bonus.c \
				./ft_lstlast_bonus.c \
				./ft_lstmap_bonus.c \
				./ft_lstnew_bonus.c \
				./ft_lstsize_bonus.c \

OBJS_DIR =	objs

OBJS =			$(SRCS:%.c=$(OBJS_DIR)/%.o)
OBJS_BONUS =	$(SRCS_BONUS:%.c=$(OBJS_DIR)/%.o)

INCLUDES = -I .

CFLAGS =	-Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
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