#include "cub3d.h"

void check_valid_case(t_mlx *mlx, int x, int y)
{
	printf("y = %d", y);
	if (y == 0 || !mlx->map->map[y + 1][x] || x == 0 || !mlx->map->map[y][x + 1])
		ft_error("invalid map\n", true, mlx);
	if (ft_ischarset(mlx->map->map[y + 1][x], " \n"))
		ft_error("invalid map\n", true, mlx);
	if (mlx->map->map[y - 1][x] == ' ')
		ft_error("invalid map\n", true, mlx);
	if (ft_ischarset(mlx->map->map[y][x + 1], " \n"))
		ft_error("invalid map\n", true, mlx);
	if (ft_ischarset(mlx->map->map[y][x - 1], " \n"))
		ft_error("invalid map\n", true, mlx);
}

void ft_print_map(char **map)
{
	int i;

	i = 0;
	while (map[i])
	{
		printf("ligne %d \t:\t %s", i , map[i]);
		i++;
	}
}
char	**ft_copy_strs(char **strs)
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

void flood_fill(char **map, int x, int y, t_mlx *mlx, int len)
{
	//ft_print_map(map_cpy);
	if (x < 0 || y < 0 || x > ft_strlen(map[y]) || y > len)
		return;
	if (map[y][x] == 'F')
		return;
	if (map[y][x] == '0')
	{
		printf("test\n");
		check_valid_case(mlx, x, y);
	}
	map[y][x] = 'F';

	flood_fill(map, x + 1, y, mlx, len);
	flood_fill(map, x - 1, y, mlx, len);
	flood_fill(map, x, y + 1, mlx, len);
	flood_fill(map, x, y - 1, mlx, len);
}

void check_map_ff(char **map, t_mlx *mlx)
{
	char **map_cpy;
	int len;

	len = 0;
	while (map[len])
		len++;
	map_cpy= ft_copy_strs(map);
	flood_fill(map_cpy, 0, 0, mlx, len);
	ft_freef("%d", map_cpy);

}