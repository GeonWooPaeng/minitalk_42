CC = gcc
CFLAGS = -Wextra -Werror -Wall
CFLAGS += -g

NAME1 = client
NAME2 = server

DIR_H = ./includes/
DIR_S = ./srcs/
DIR_O = ./

SRC1 =	ft_all_utils.c					\
		./client/ft_client_utils.c		\
		./client/ft_client.c			\

SRC2 =	ft_all_utils.c					\
		./server/ft_server_utils.c		\
		./server/ft_server.c			\

SRCS1 = $(addprefix $(DIR_S), $(SRC1))
SRCS2 = $(addprefix $(DIR_S), $(SRC2))

OBJS1 = $(SRCS1:.c=.o)
OBJS2 = $(SRCS2:.c=.o)

all: $(NAME1) $(NAME2)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $<


$(NAME1): $(OBJS1)
	$(CC) $(CFLAGS) $(OBJS1) -o $(NAME1) 

$(NAME2): $(OBJS2)
	$(CC) $(CFLAGS) $(OBJS2) -o $(NAME2)


clean:
	rm -rf $(OBJS1) $(OBJS2)

fclean: clean
	rm -rf $(NAME1) $(NAME2)

re: fclean all

.PHONY: clean fclean all re