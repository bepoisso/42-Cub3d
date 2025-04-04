#include "cub3d.h"

void	print_player(t_mlx *mlx, bool clear)
{
	if (clear)
		mlx->player->circle->color = mlx->element->cieling_color;
	else
		mlx->player->circle->color = 0xFF00FF;
	mlx->player->circle->x_pos = ftopix(mlx->player->x);
	mlx->player->circle->y_pos = ftopix(mlx->player->y);
	mlx->player->circle->size_x = 10;
	mlx->player->circle->size_y = 10;
	mlx_draw_filled_circle(mlx, mlx->player->circle);
	ft_printf("Player was draw, pos %d %d\n", (int)floorf(mlx->player->x), (int)floorf(mlx->player->y));
}

void	move_player_fb(t_player *player, bool angle)
{
	if (angle)
	{
		player->y = player->y + (sin(player->angle * PI / 180) * SPEED);
		player->x = player->x + (cos(player->angle * PI / 180) * SPEED);
	}
	else
	{
		player->y = player->y - (sin(player->angle * PI / 180) * SPEED);
		player->x = player->x - (cos(player->angle * PI / 180) * SPEED);
	}
}

void	move_player_lr(t_player *player, bool angle)
{
	if (angle)
	{
		player->y = player->y + (cos(player->angle * PI / 180) * SPEED);
		player->x = player->x - (sin(player->angle * PI / 180) * SPEED);
	}
	else
	{
		player->y = player->y - (cos(player->angle * PI / 180) * SPEED);
		player->x = player->x + (sin(player->angle * PI / 180) * SPEED);
	}
}