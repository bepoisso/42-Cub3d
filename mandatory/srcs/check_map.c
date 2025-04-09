#include "cub3d.h"

static void check_valid_case(t_mlx *mlx, int x, int y, int len)
{
	if (y == 0 || y == len - 1 || x == 0 || x == (int)ft_strlen(mlx->map->map[y]) - 1)
		ft_error("invalid map\n", true, mlx);
	if (ft_ischarset(mlx->map->map[y + 1][x], " \n"))
		ft_error("invalid map\n", true, mlx);
	if (ft_ischarset(mlx->map->map[y - 1][x], " \n"))
		ft_error("invalid map\n", true, mlx);
	if (ft_ischarset(mlx->map->map[y][x + 1], " \n"))
		ft_error("invalid map\n", true, mlx);
	if (ft_ischarset(mlx->map->map[y][x - 1], " \n"))
		ft_error("invalid map\n", true, mlx);
}

static char	**ft_copy_strs(char **strs)
{
	int i;
	int len;
	char	**cpy;

	len = 0;
	while (strs[len])
		len++;
	cpy = (char **)malloc(sizeof(char *) * (len + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		cpy[i] = ft_strdup(strs[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

static void flood_fill(char **map, int x, int y, t_mlx *mlx)
{	
	int len;

	len = 0;
	while (map[len])
		len++;
	if (y < 0 || y >= len || x < 0)
		return;
	if (!map[y])
	 	return;
	if (x >= (int)ft_strlen(map[y]))
		return;
	if (map[y][x] == 'F')
		return;
	if (map[y][x] == '0')
		check_valid_case(mlx, x, y, len);
	map[y][x] = 'F';
	if (x )
	flood_fill(map, x + 1, y, mlx);
	flood_fill(map, x - 1, y, mlx);
	flood_fill(map, x, y + 1, mlx);
	flood_fill(map, x, y - 1, mlx);
}

void ft_print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		printf("y %d \t:\t %s", i , map[i]);
		i++;
	}
	printf( "-----------\n" );
}

void is_valid_map(char **map, t_mlx *mlx)
{
	char **map_cpy;

	map_cpy= ft_copy_strs(map);
	//ft_print_map(map_cpy);
	flood_fill(map_cpy, 0, 0, mlx);
	ft_freef("%d", map_cpy);
}
