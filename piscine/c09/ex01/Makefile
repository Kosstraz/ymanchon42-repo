CC = gcc

SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c

OBJS = $(SRCS:.c=.o)

HEADER = -I includes/

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

$(NAME): $(OBJS)
	ar -rcs $(OBJS) $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean 
	rm -f $(NAME)
	
re: fclean all
