#include "cub3d.h"

int get_texture_color(t_img *texture, int tex_x, int tex_y)
{
	int pixel_pos;
	if (tex_x < 0 || tex_x >= texture->width || tex_y < 0 || tex_y >= texture->height)
		return (0x000000); 
	pixel_pos = tex_y * texture->line_len + tex_x * (texture->bpp / 8);
	return (*(int *)(texture->add + pixel_pos));
}


void draw_floor_and_cieling (t_mlx *mlx)
{
	int x;
	int y;

	y = 0;


	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2)
				put_pixel(x, y, mlx->element->cieling_color, mlx);
			else
				put_pixel(x, y, mlx->element->floor_color, mlx);
			x++;
		}
		y++;
	}
}

void	draw_line_2d(t_mlx *mlx, int color, int i)
{
	float steps;
	float x_inc;
	float y_inc;
	float x;
	float y;
	
	steps = fmax(fabs(mlx->dda->ray_x - mlx->player->x), 
			fabs(mlx->dda->ray_y - mlx->player->y));
	y_inc = (mlx->dda->ray_y - mlx->player->y) / steps;
	x_inc = (mlx->dda->ray_x - mlx->player->x) / steps;
	x = mlx->player->x;
	y = mlx->player->y;
	while (i <= steps)
	{
		put_pixel(x, y, color, mlx);
		x += x_inc;
		y += y_inc;
		i++;
	}
}

void	print_game(t_player *player, t_mlx *mlx, int i, float ray_angle)
{
	if (DEBUG)
		draw_line_2d(mlx, 0xFF0000, 0);
	if (!DEBUG)
	{
		draw_textured_wall(mlx, player, i, ray_angle);
	}
}

void	init_drawing(t_mlx *mlx, t_player *player, float start_x)
{
	mlx->dda->map_x = (int)(player->x / TEXTURE);
	mlx->dda->map_y = (int)(player->y / TEXTURE);
	mlx->dda->cos_angle = cos(start_x);
	mlx->dda->sin_angle = sin(start_x);
	mlx->dda->ray_x = player->x;
	mlx->dda->ray_y = player->y;
	mlx->dda->delta_x = fabs(1 / mlx->dda->cos_angle) * TEXTURE;
	mlx->dda->delta_y = fabs(1 / mlx->dda->sin_angle) * TEXTURE;

}

void	ray_impact(t_mlx *mlx, t_player *player)
{
	if (mlx->dda->side == 0)
	{
		mlx->dda->ray_x = mlx->dda->map_x * TEXTURE;
		if (mlx->dda->step_x < 0)
			mlx->dda->ray_x += TEXTURE;
		mlx->dda->ray_y = player->y + (mlx->dda->ray_x - player->x) 
			* mlx->dda->sin_angle / mlx->dda->cos_angle;
	}
	else
	{
		mlx->dda->ray_y = mlx->dda->map_y * TEXTURE;
		if (mlx->dda->step_y < 0)
			mlx->dda->ray_y += TEXTURE;
		mlx->dda->ray_x = player->x + (mlx->dda->ray_y - player->y) 
			* mlx->dda->cos_angle / mlx->dda->sin_angle;
	}
	
}

void	ray_dda(t_mlx *mlx)
{
	while (1)
	{
		if (mlx->dda->side_x < mlx->dda->side_y)
		{
			mlx->dda->side_x += mlx->dda->delta_x;
			mlx->dda->map_x += mlx->dda->step_x;
			mlx->dda->side = 0;
		}
		else
		{
			mlx->dda->side_y += mlx->dda->delta_y;
			mlx->dda->map_y += mlx->dda->step_y;
			mlx->dda->side = 1;
		}
		if (mlx->map->map[mlx->dda->map_y][mlx->dda->map_x] == '1')
		break;
	}
}

void	draw_line(t_player *player, t_mlx *mlx, float start_x, int i)
{
	init_drawing(mlx, player, start_x);
	if (mlx->dda->cos_angle < 0)
	{
		mlx->dda->step_x = -1;
		mlx->dda->side_x = (mlx->dda->ray_x - mlx->dda->map_x * TEXTURE) 
			* mlx->dda->delta_x / TEXTURE;
	}
	else
	{
		mlx->dda->step_x = 1;
		mlx->dda->side_x = ((mlx->dda->map_x + 1) * TEXTURE - mlx->dda->ray_x) 
			* mlx->dda->delta_x / TEXTURE;
	}
	if (mlx->dda->sin_angle < 0)
	{
		mlx->dda->step_y = -1;
		mlx->dda->side_y = (mlx->dda->ray_y - mlx->dda->map_y * TEXTURE) 
			* mlx->dda->delta_y / TEXTURE;
	}
	else
	{
		mlx->dda->step_y = 1;
		mlx->dda->side_y = ((mlx->dda->map_y + 1) * TEXTURE - mlx->dda->ray_y) 
			* mlx->dda->delta_y / TEXTURE;
	}
	ray_dda(mlx);
	ray_impact(mlx, player);
	print_game(player, mlx, i, start_x);
}
