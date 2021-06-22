CC = gcc
CFLAGS = -Wextra -Werror -Wall
CFLAGS += -g
NAME = minitalk

DIR_H = ./includes/
DIR_S = ./srcs/
DIR_O = ./

SRC = main.c

SRCS = $(addprefix $(DIR_S), $(SRC))

OBJS = $(SRCS.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) - c $< -I $(DIR_H) - o $@

$(NAME): $(OBJS)
	$(CC) -o $(NAME) -I $(DIR_H) $(OBJS) $(CFLAGS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re