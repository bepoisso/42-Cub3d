#include "cub3d.h"

t_map	*init_map(char **file, t_mlx *mlx)
{
	t_map *map;

	map = (t_map *)malloc(sizeof(t_map));
	ft_memset(map, 0, sizeof(t_map));
	map->map = get_map(file);
	map->y_max = ft_strslen(map->map);
	map->mlx = mlx;
	return (map);
}

t_player	*init_player(t_mlx *mlx)
{
	t_player	*player;
	t_draw		*circle;

	player = (t_player *)malloc(sizeof(t_player));
	ft_memset(player, 0, sizeof(t_player));
	circle = (t_draw *)malloc(sizeof(t_draw));
	ft_memset(circle, 0, sizeof(t_draw));
	circle->radius = 10;
	player->circle = circle;
	return (player);
}