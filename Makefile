SRC		= src/main.c src/logging.c
OBJ		= $(SRC:.c=.o)
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -I./includes -g
LFLAGS	= -lpthread
NAME	= server
EXLIB  = ./argv_lib/argv.a
EXLIBDIR = ./argv_lib

all: $(EXLIB) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -I$(EXLIBDIR) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) -I$(EXLIBDIR) $(LFLAGS) $(OBJ) $(EXLIB)   -o $(NAME)

$(EXLIB):
	make -C ./argv_lib

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

run: all
	@echo Running...
	@./$(NAME)

.PHONY: all clean fclean re run