#include "cub3d.h"

void	print_player(t_mlx *mlx, bool clear)
{
	if (clear)
		mlx->player->circle->color = mlx->element->cieling_color;
	else
		mlx->player->circle->color = 0xFF00FF;
	mlx->player->circle->x_pos = mlx->player->x;
	mlx->player->circle->y_pos = mlx->player->y;
	mlx->player->circle->size_x = 10;
	mlx->player->circle->size_y = 10;
	// mlx_draw_rectangle(mlx, mlx->player->circle);
	mlx_put_image_to_window(mlx->link, mlx->screen, mlx->element->ea_img, (int)floorf(mlx->player->x), (int)floorf(mlx->player->y));
	ft_printf("Player was draw, pos %d %d\n", (int)floorf(mlx->player->x), (int)floorf(mlx->player->y));
}