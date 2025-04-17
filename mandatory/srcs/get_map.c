#include "cub3d.h"

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

t_map	*init_map(char **file, t_map *map, t_mlx *mlx)
{
	map = (t_map *)malloc(sizeof(t_map));
	ft_memset(map, 0, sizeof(t_map));
	map->map = get_map(file);
	map->y_max = ft_strslen(map->map);
	map->mlx = mlx;
	return (map);
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
