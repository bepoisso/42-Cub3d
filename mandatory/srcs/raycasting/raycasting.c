#include "cub3d.h"

int	find_wall(t_player *player)
{
	t_ray	ray;
	char	**map;

	map = player->mlx->map;
	ray.x = player->x;
	ray.y = player->y;
	ray.slope = tanf(player->angle) * 100;

	
}

/* PSEUDO */
/* 
	while (vec[y][x] is not wall)
		y + 1;
		x + 1 / slope (angle to slope searsh)
	x1 = x;
	y1 = y;
	x = pos player
	y   ''   ''
	while (vec[y][x] is not wall)
		x + 1;
		y + slope
	x2 = x;
	y2 = y;

	sqrt((p_x - x1) ** 2 + (p_y - y1) ** 2)
	sqrt((p_x - x2) ** 2 + (p_y - y2) ** 2)
	return < coordoner;
 */