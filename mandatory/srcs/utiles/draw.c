#include "cub3d.h"

void	mlx_draw_rectangle(t_mlx *data, t_draw *draw)
{
	int	x;
	int	y;

	x = draw->x_pos;
	while (x < draw->size_x + draw->x_pos)
	{
		y = draw->y_pos;
		while (y < draw->size_y + draw->y_pos)
		{
			mlx_pixel_put(data->link, data->screen, draw->x_pos,
				draw->y_pos, draw->color);
			y++;
		}
		x++;
	}
}

void	mlx_draw_circle(t_mlx *mlx, t_draw *circle)
{
	float	i;
	float	angle;
	float	x1;
	float	y1;

	i = 0;
	while (i < 360)
	{
			angle = i;
			x1 = circle->radius * cos(angle * PI / 180);
			y1 = circle->radius * sin(angle * PI / 180);
			mlx_pixel_put(mlx->link, mlx->screen, circle->x_pos + x1, circle->y_pos + y1, circle->color);
			i += 0.1;
	}
}

void	mlx_draw_player_line(t_mlx *mlx, t_draw *circle, int length)
{
	float	x;
	float	y;
	float	angle_rad;
	int		i;
	int		angle;

	angle = mlx->player->angle;
	angle_rad = angle * PI / 180;
	i = 0;
	while (i < length)
	{
		x = circle->x_pos + i * cos(angle_rad);
		y = circle->y_pos + i * sin(angle_rad);
		mlx_pixel_put(mlx->link, mlx->screen, x, y, circle->color);
		i++;
	}
}

void mlx_draw_filled_circle(t_mlx *mlx, t_draw *circle)
{
	float	i;
	float	angle;
	float	x1;
	float	y1;
	int 	r;

	i = 0;
	while (i < 360)
	{
		angle = i * PI / 180;
		r = 0;
		while (r <= circle->radius)
		{
			x1 = circle->x_pos + r * cos(angle);
			y1 = circle->y_pos + r * sin(angle) ;
			mlx_pixel_put(mlx->link, mlx->screen, x1, y1, circle->color);
			r++;
		}
		i += 0.1;
	}
	mlx_draw_player_line(mlx, circle, 20);
}

