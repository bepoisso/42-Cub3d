#include "cub3d.h"

void	print_player(t_mlx *mlx, bool clear)
{
	if (clear)
		mlx->player->circle->color = mlx->element->cieling_color;
	else
		mlx->player->circle->color = 0xFF00FF;
	mlx->player->circle->x_pos = mlx->player->x;
	mlx->player->circle->y_pos = mlx->player->y;
	mlx_draw_circle(mlx, mlx->player->circle);
}