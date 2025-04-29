#include "cub3d.h"

void	init_door(t_mlx *mlx)
{
	int		x;
	int		y;
	char	**map;

	mlx->door = malloc(sizeof(t_door **) * mlx->map->y_max);
	if (!mlx->door)
		ft_error("error malloc door", true, mlx);
	map = mlx->map->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		mlx->door[y] = malloc(sizeof(t_door *) * mlx->map->x_max);
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				mlx->door[y][x] = malloc(sizeof(t_door));
				mlx->door[y][x]->open_progress = 0.0f;
			}
			x++;
		}
		y++;
	}
}

void	free_door(t_mlx *mlx)
{
	int		x;
	int		y;
	char	**map;

	map = mlx->map->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				free(mlx->door[y][x]);
			}
			x++;
		}
		free(mlx->door[y]);
		y++;
	}
	free(mlx->door);
}

void	check_open_progress(t_mlx *mlx, float dist, int x, int y)
{
	if (dist < 1.5f)
	{
		mlx->door[y][x]->open_progress += 0.02f;
		if (mlx->door[y][x]->open_progress > 1.0f)
			mlx->door[y][x]->open_progress = 1.0f;
	}
	else
	{
		mlx->door[y][x]->open_progress -= 0.02f;
		if (mlx->door[y][x]->open_progress < 0.0f)
			mlx->door[y][x]->open_progress = 0.0f;
	}
}

void	update_door(t_mlx *mlx, t_player *player)
{
	int		x;
	int		y;
	float	dist;
	float	dx;
	float	dy;

	y = -1;
	while (++y < mlx->map->y_max)
	{
		x = -1;
		while (++x < mlx->map->x_max)
		{
			if (mlx->map->map[y][x] == 'P' || mlx->map->map[y][x] == 'Q')
			{
				if (mlx->door[y][x]->open_progress != 0.0f)
					mlx->map->map[y][x] = 'Q';
				else
					mlx->map->map[y][x] = 'P';
				dx = (player->x / TEXTURE) - (x + 1.5f);
				dy = (player->y / TEXTURE) - (y + 1.5f);
				dist = sqrtf(dx * dx + dy * dy);
				check_open_progress(mlx, dist, x, y);
			}
		}
	}
}
