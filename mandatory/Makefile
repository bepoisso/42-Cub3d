#_________________COLORS_________________

PURPLE = \033[0;35m
YELLOW = \033[0;93m
RESET = \033[0m

#_________________VARIABLE_________________

NAME = cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -g #-Werror
ARGS		= maps/map.cub
MLX_NAME	= libmlx.a
MLX_FLAGS	= -l mlx -l Xext -l X11

VAL_ARGS	= --leak-check=full --track-origins=yes --show-leak-kinds=all --track-fds=yes --show-reachable=yes -s
MAKEFLAGS	+= --no-print-directory

#_________________DIRECTORY_________________
INC_DIR	= includes/
SRC_DIR	= srcs/
OBJ_DIR	= objs/
LIBFT_DIR	= ./libft
LIBFT_LIB	= $(LIBFT_DIR)/libft.a
MLX_DIR	= ./minilibx-linux/

#_________________FILES_________________

SRC_FILES	=	main/main.c\
				parsing/line.c\
				parsing/parsing.c\
				map/map.c\
				utiles/error.c\
				utiles/utiles.c\
				map/init.c\
				map/m_error.c\


LIBSX		=	$(addprefix $(MLX_DIR),$(MLX_NAME))
SRCS		=	$(addprefix $(SRC_DIR),$(SRC_FILES))
OBJS		=	$(addprefix $(OBJ_DIR),$(notdir $(SRC_FILES:.c=.o)))
#_________________RULES_________________

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(LIBSX)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) $(MLX_FLAGS) -lm
	@echo "Cub3D executable :			✅"

$(OBJ_DIR)%.o: $(SRC_DIR)*/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@make -C $(MLX_DIR) > /dev/null 2>&1
	@echo "Minilibx :				✅"
	@make -C $(LIBFT_DIR)
	@echo "Libft :					✅"

clean:
	@rm -rf $(OBJ_DIR)
	@echo "Main's objs delete :			✅"
	@make clean -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "Libft's objs delete :			✅"
	@make clean -C $(MLX_DIR) > /dev/null 2>&1
	@echo "Minilibx's objs delete :		✅"

fclean: clean
	@rm -f $(NAME)
	@echo "Cub3D executable file delete :		✅"
	@make fclean -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "Libft libft.a delete :			✅"

re: fclean all

val: re
	@valgrind $(VAL_ARGS) ./$(NAME) $(ARGS);

debug: re
	@gdb -tui -q $(NAME);

.PHONY: all clean fclean re val debug