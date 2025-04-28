#include "cub3d.h"

static float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

static float	fixed_dist(float raw_dist, float ray_angle, float player_angle)
{
	return (raw_dist * cos(ray_angle - player_angle));
}

void	draw_on_screen(t_mlx *mlx, t_img *texture, int i)
{
	while (mlx->draw.y < mlx->draw.end)
	{
		if (mlx->draw.y >= 0 && mlx->draw.y < HEIGHT)
		{
			mlx->draw.tex_y = (int)((mlx->draw.y - mlx->draw.start_y)
					* texture->height / mlx->draw.height);
			mlx->draw.color = get_texture_color(texture, mlx->draw.tex_x,
					mlx->draw.tex_y);
			put_pixel(i, mlx->draw.y, mlx->draw.color, mlx);
		}
		mlx->draw.y++;
	}
}

t_img	*texture_in_map(t_mlx *mlx, t_player *player, t_img *texture)
{

	if (mlx->dda->side == 1)
	{
		if (mlx->dda->ray_y < player->y)
			texture = mlx->element->no_img;
		else
			texture = mlx->element->so_img;
		mlx->draw.wall_x = mlx->dda->ray_x;
	}
	else
	{
		if (mlx->dda->ray_x < player->x)
			texture = mlx->element->we_img;
		else
			texture = mlx->element->ea_img;
		mlx->draw.wall_x = mlx->dda->ray_y;
	}
	if (mlx->map->map[mlx->dda->map_y][mlx->dda->map_x] == 'P')
			texture = mlx->element->door;
	return (texture);
}

void	draw_textured_wall(t_mlx *mlx, t_player *player, int i, float ray_angle)
{
	t_img	*texture;

	texture = NULL;
	mlx->draw.fov_v = (2 * atan(tan(FOV / 2) * ((float)HEIGHT / (float)WIDTH)));
	mlx->draw.raw_dist = distance(mlx->dda->ray_x
			- player->x, mlx->dda->ray_y - player->y);
	mlx->draw.dist = fixed_dist(mlx->draw.raw_dist, ray_angle, player->angle);
	mlx->draw.height = (TEXTURE / mlx->draw.dist)
		* (HEIGHT / (2  * tan(mlx->draw.fov_v / 2)));
	mlx->draw.start_y = (HEIGHT - mlx->draw.height) / 2 + player->jump_value;
	mlx->draw.end = mlx->draw.start_y + mlx->draw.height;
	texture = texture_in_map(mlx, player, texture);
	mlx->draw.wall_x = fmod(mlx->draw.wall_x, TEXTURE);
	mlx->draw.tex_x = (int)(mlx->draw.wall_x / TEXTURE * texture->width);
	if (mlx->draw.tex_x < 0)
		mlx->draw.tex_x = 0;
	if (mlx->draw.tex_x >= texture->width)
		mlx->draw.tex_x = texture->width - 1;
	mlx->draw.y = mlx->draw.start_y;
	draw_on_screen(mlx, texture, i);
}
