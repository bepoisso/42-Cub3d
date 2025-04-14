#include "cub3d.h"

static float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

static float	fixed_dist(float x1, float y1, float x2, float y2, t_mlx *mlx)
{
	float delta_x;
	float delta_y;
	float angle;
	float fix_dist;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	angle = atan2(delta_y, delta_x) - mlx->player->angle;
	fix_dist = distance(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}

static bool	touch(float px, float py, t_mlx *mlx)
{
	int x;
	int y;

	x = px / TEXTURE;
	y = py / TEXTURE;
	if (mlx->map->map[y][x] == '1')
		return (true);
	return (false);
}

static void	no_debug_draw_line(int ray_x, int ray_y, t_mlx *mlx, t_player *player, int i)
{
	float	dist;
	float	height;
	int		start_y;
	int		end;

	dist = fixed_dist(player->x, player->y, ray_x, ray_y, mlx);
	height = (TEXTURE / dist) * (WIDTH / 2);
	start_y = (HEIGHT - height) / 2;
	end = start_y + height;
	while (start_y < end)
	{
		put_pixel(i, start_y, 0x00FF00, mlx);
		start_y++;
	}
}

void	draw_line(t_player *player, t_mlx *mlx, float start_x, int i)
{
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;

	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	ray_x = player->x;
	ray_y = player->y;

	while (!touch(ray_x, ray_y, mlx))
	{
		if (DEBUG)
			put_pixel(ray_x, ray_y, 0xFF0000, mlx);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
	if (!DEBUG)
		draw_textured_wall(ray_x, ray_y, mlx, player, i);
}