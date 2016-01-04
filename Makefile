NAME = fractal

CC = gcc -Wall -Werror -Wextra -L/usr/X11/lib -lmlx -lXext -lX11 -I /usr/X11/include -I /usr/include -Ofast -o3

SRC =   ./src/mlx.c\
        ./src/fractal.c\
		./src/main.c\
		./src/ft_mouse.c\
		./src/ft_init.c\
		./src/ft_key.c\
		./src/ft_environment.c\
		./src/fractal_2.c

COMPILE = echo "\033[36mCompile --fractal-- ...."
COMPILED = echo "\033[32mCompiled --fractal-- Successfully"
CLEAN = echo "\033[36mClean --fractal-- ...."
CLEANED = echo "\033[32mCleaned --fractal-- Successfully"

all: $(NAME)

$(NAME):
	@$(COMPILE)
	@make -C ./libft re
	@$(CC) -o $(NAME) $(SRC) ./libft/libft.a
	@$(COMPILED)

norme:
	@norminette $(SRC) ./src/fractal.h
	@make -C ./libft norme

rego: re
	@./$(NAME)

clean:
	@$(CLEAN)
	@make -C ./libft clean
	@$(CLEANED)

fclean: clean
	@make -C ./libft fclean
	@rm -f $(NAME)

re : fclean all