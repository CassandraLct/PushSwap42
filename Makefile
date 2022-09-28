CC = GCC
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address
NAME = push_swap
SRC = src/main.c src/parse.c utils/ft_lstadd_back.c utils/ft_lstnew.c utils/utils_atoi.c \
		utils/ft_lstlast.c utils/utils.c utils/actions_a.c utils/actions_b.c src/change_arg.c \
		src/redirection.c src/utils_trie.c src/chunk_utils.c 
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o : %.c
	@echo "\033[1;35m""Compilation de ${NAME}..."
	$(CC) -o $@ -c $< $(CFLAGS)

$(NAME) : $(OBJ)
	@echo "\033[1;35m""Compilation de ${NAME}..."
	$(CC) $(OBJ) $(CFLAGS) -o $(NAME)

clean :
	@echo "\033[1;34m""Suppresion des .o..."
	rm -rf $(OBJ)

fclean : clean
	@echo "\033[1;34m""Supression des executables et librairies..."
	rm -rf $(NAME) 

re : fclean all

.PHONY : all clean fclean re