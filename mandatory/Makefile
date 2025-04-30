#_________________COLORS_________________

PURPLE = \033[0;35m
YELLOW = \033[0;93m
RESET = \033[0m

#_________________VARIABLE_________________

NAME = cub3D

CC			= cc
CFLAGS		= -Wall -Wextra -g #-Werror
ARGS		= assets/maps/debug/map_ray.cub
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

SRC_FILES	=	main.c\
				alloc.c\
				player.c\
				color.c\
				check_map.c\
				get_map.c\
				get_file.c\
				parsing.c\
				utils_error.c\
				utils_utiles.c\
				utils_mlx.c\
				draw.c\
				init_draw.c\
				draw_3d.c\
				raycasting.c\
				init.c\
				free.c\
				dda.c\
				move.c\
				pix.c\
				hud.c\
				mouse.c\
				time.c\
				minimap.c\
				door.c\
				fisheye.c\


LIBSX		=	$(addprefix $(MLX_DIR),$(MLX_NAME))
SRCS		=	$(addprefix $(SRC_DIR),$(SRC_FILES))
OBJS		=	$(addprefix $(OBJ_DIR),$(SRC_FILES:.c=.o))

#_________________RULES_________________

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_LIB) $(LIBSX)
	@$(CC) $(CFLAGS) -o $@ $(OBJS) -L$(LIBFT_DIR) -lft -L$(MLX_DIR) $(MLX_FLAGS) -lm
	@echo "Cub3D executable :			✅"

$(OBJ_DIR)%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -I$(MLX_DIR) -c $< -o $@

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(MLX_DIR)$(MLX_NAME):
	@make -C $(MLX_DIR)

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
	valgrind $(VAL_ARGS) ./$(NAME) $(ARGS);

debug: re
	@gdb -tui -q $(NAME);

.PHONY: all clean fclean re val debug
