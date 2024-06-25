NAME     = runfile
CC       = cc
CFLAGS   = -Wall -Wextra -Werror 
SRC      = init.c utils.c dfs.c main.c 
OBJ      = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


