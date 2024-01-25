NAME = pipex
CC = @gcc
RM = @rm -f
FLAGS = -Wall -Wextra -Werror 

YELLOW = \033[33;49;1m
CYAN = \033[33;36;1m
END = \033[0;0m

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = $(shell find . -name '*.c')
INCLUDES = -I includes

OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME):	$(OBJ)  $(LIBFT)
			$(CC) $(OBJ) $(LIBFT) -o $(NAME)
			@echo "$(YELLOW)${NAME} ✔️"
			@echo "$(CYAN)Mandatory files compiled successfully ✔️$(END)"

%.o: %.c includes/*.h
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@


$(LIBFT):
	@make -s -C $(LIBFT_DIR)
	@echo "$(YELLOW) libft ✔️"


clean:
	${RM} ${OBJ}
	${RM} ${B_OBJ}
	@echo "$(CYAN)Object files have been deleted ✔️$(END)"


fclean: clean
	@make clean -C libft
	@make fclean -C libft
	@echo "$(CYAN)Libft files and executable have been deleted ✔️$(END)"
	${RM} ${NAME}

libft:
	make re -C $(LIBFT_DIR)

re: clean mlx all

check_leaks:
			leaks --atExit -- ./$(NAME) text.txt "grep Best" "wc -c" output.txt   
norm:
			norminette src
			norminette includes/fdf.h

.PHONY: all clean fclean re mlx check_leaks norm
