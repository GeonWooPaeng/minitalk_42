CC = gcc
CFLAGS = -Wextra -Werror -Wall
CFLAGS += -g

NAME1 = client
NAME2 = server

DIR_H = ./includes/
DIR_S = ./srcs/
DIR_O = ./

SRC1 = client/main.c
SRC2 = server/main.c`

SRCS1 = $(addprefix $(DIR_S), $(SRC1))
SRCS2 = $(addprefix $(DIR_S), $(SRC2))

OBJS1 = $(SRCS1.c=.o)
OBJS2 = $(SRCS2.c=.o)

$(NAME1): $(OBJS1)
	$(CC) -o $(NAME1) -I $(DIR_H) $(OBJS1) $(CFLAGS)

$(NAME2): $(OBJS2)
	$(CC) -o $(NAME2) -I $(DIR_H) $(OBJS2) $(CFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) - c $< -I $(DIR_H) - o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re