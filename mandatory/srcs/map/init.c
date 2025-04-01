#include "cub3d.h"

t_map	*init_map(char **file, t_mlx *mlx)
{
	t_map *map;

	map = (t_map *)malloc(sizeof(t_map));
	ft_memset(map, 0, sizeof(t_map));
	map->map = get_map(file);
	map->mlx = mlx;
	return (map);
}