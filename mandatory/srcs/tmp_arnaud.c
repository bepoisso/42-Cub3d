#include "cub3d.h"


int get_texture_color(t_img *texture, int tex_x, int tex_y)
{
	int pixel_pos;
	if (tex_x < 0 || tex_x >= texture->width || tex_y < 0 || tex_y >= texture->height)
		return (0x000000); 
	pixel_pos = tex_y * texture->line_len + tex_x * (texture->bpp / 8);
	return (*(int *)(texture->add + pixel_pos));
}


void	draw_line_2d(float x0, float y0, float x1, float y1, t_mlx *mlx, int color)
{
	float dx = x1 - x0;
	float dy = y1 - y0;
	float steps = fmax(fabs(dx), fabs(dy));
	float x_inc = dx / steps;
	float y_inc = dy / steps;
	
	float x = x0;
	float y = y0;
	for (int i = 0; i <= steps; i++)
	{
		put_pixel(x, y, color, mlx);
		x += x_inc;
		y += y_inc;
	}
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
				put_pixel(x, y, 0xFF0000, mlx);
			else
				put_pixel(x, y, 0xFF0000, mlx);
			x++;
		}
		y++;
	}
}

void	print_game(int ray_x, int ray_y, t_player *player, t_mlx *mlx, int i)
{
	if (DEBUG)
		draw_line_2d(player->x, player->y, ray_x, ray_y, mlx, 0xFF0000);
	if (!DEBUG)
	{
		//draw_floor_and_cieling(mlx->element);
		draw_textured_wall(mlx->dda->ray_x, mlx->dda->ray_y, mlx, player, i, mlx->dda->side);
	}
}

void	draw_line(t_player *player, t_mlx *mlx, float start_x, int i)
{
	mlx->dda->map_x = (int)(player->x / TEXTURE);
	mlx->dda->map_y = (int)(player->y / TEXTURE);
	mlx->dda->cos_angle = cos(start_x);
	mlx->dda->sin_angle = sin(start_x);
	mlx->dda->ray_x = player->x;
	mlx->dda->ray_y = player->y;
	mlx->dda->delta_x = fabs(1 / mlx->dda->cos_angle) * TEXTURE;
	mlx->dda->delta_y = fabs(1 / mlx->dda->sin_angle) * TEXTURE;

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

	while (true)
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
		if (DEBUG)
			put_pixel(mlx->dda->ray_x, mlx->dda->ray_y, 0xFF0000, mlx);
	}

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
	print_game(mlx->dda->ray_x, mlx->dda->ray_y, mlx->player, mlx, i);
}



