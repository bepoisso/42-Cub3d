#include "cub3d.h"

int	get_player_pos(t_mlx *mlx, int x, int y)
{
	y = -1;
	while (mlx->map->map[++y])
	{
		x = 0;
		while (mlx->map->map[y][x])
		{
			if (ft_ischarset(mlx->map->map[y][x], "NSEW"))
			{
				mlx->player->x = (x * TEXTURE) + (TEXTURE / 2);
				mlx->player->y = (y * TEXTURE) + (TEXTURE / 2);
				if (mlx->map->map[y][x] == 'N')
					mlx->player->angle = degtorad((float)270);
				if (mlx->map->map[y][x] == 'S')
					mlx->player->angle = degtorad((float)90);
				if (mlx->map->map[y][x] == 'E')
					mlx->player->angle = degtorad((float)0);
				if (mlx->map->map[y][x] == 'W')
					mlx->player->angle = degtorad((float)180);
				return (0);
			}
			x++;
		}
	}
	return (1);
}

static int	count_map_size(char **file)
{
	int	i;
	int	j;

	i = 0;
	while (file[i])
		i++;
	j = i - 1;
	while (file[j][0] == '\n')
		j--;
	while (file[j][0] != '\n')
		j--;
	return (i - j);
}

void	init_map(char **file, t_map *map, t_mlx *mlx)
{
	map->map = get_map(file);
	map->y_max = ft_strslen(map->map);
	map->mlx = mlx;
}

char	**get_map(char **file)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = count_map_size(file);
	map = (char **)malloc(sizeof(char *) * (j + 1));
	j--;
	map[j--] = NULL;
	while (file[i])
		i++;
	i--;
	while (file[i][0] == '\n')
		i--;
	while (file[i][0] != '\n')
	{
		map[j] = ft_strdup(file[i]);
		i--;
		j--;
	}
	return (map);
}
