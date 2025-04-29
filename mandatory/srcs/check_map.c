#include "cub3d.h"

static void	check_valid_pos(t_mlx *mlx, int x, int y, int len)
{
	if (y == 0 || y == len - 1 || x == 0
		|| x == (int)ft_strlen(mlx->map->map[y]) - 1)
		ft_error("invalid map\n", true, mlx);
	if (!ft_ischarset(mlx->map->map[y + 1][x], "10"))
		ft_error("invalid map\n", true, mlx);
	if (!ft_ischarset(mlx->map->map[y - 1][x], "10"))
		ft_error("invalid map\n", true, mlx);
	if (!ft_ischarset(mlx->map->map[y][x + 1], "10"))
		ft_error("invalid map\n", true, mlx);
	if (!ft_ischarset(mlx->map->map[y][x - 1], "10"))
		ft_error("invalid map\n", true, mlx);
}

static void	check_valid_case(t_mlx *mlx, int x, int y, int len)
{
	if (y == 0 || y == len - 1 || x == 0
		|| x == (int)ft_strlen(mlx->map->map[y]) - 1)
		ft_error("invalid map\n", true, mlx);
	if (!ft_ischarset(mlx->map->map[y + 1][x], "10WSNO"))
		ft_error("invalid map\n", true, mlx);
	if (!ft_ischarset(mlx->map->map[y - 1][x], "10WSNO"))
		ft_error("invalid map\n", true, mlx);
	if (!ft_ischarset(mlx->map->map[y][x + 1], "10WSNO"))
		ft_error("invalid map\n", true, mlx);
	if (!ft_ischarset(mlx->map->map[y][x - 1], "10WSNO"))
		ft_error("invalid map\n", true, mlx);
}

static char	**ft_copy_strs(char **strs)
{
	int		i;
	int		len;
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

static void	flood_fill(char **map, int x, int y, t_mlx *mlx)
{
	int	len;

	len = 0;
	while (map[len])
		len++;
	if (y < 0 || y >= len || x < 0)
		return ;
	if (!map[y])
		return ;
	if (x >= (int)ft_strlen(map[y]))
		return ;
	if (map[y][x] == 'F')
		return ;
	if (map[y][x] == '0')
		check_valid_case(mlx, x, y, len);
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, mlx);
	flood_fill(map, x - 1, y, mlx);
	flood_fill(map, x, y + 1, mlx);
	flood_fill(map, x, y - 1, mlx);
}

void	ft_print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("y %d \t:\t %s", i, map[i]);
		i++;
	}
	ft_printf("-----------\n");
}

void check_char_in_map(char **map, t_mlx *mlx)
{
	int x;
	int y;
	int	len;

	len = 0;
	while (map[len])
		len++;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_ischarset(map[y][y], " 10NOWS"))
				ft_error("bad char in map", true, mlx);
			if (ft_ischarset(map[y][y], " NOWS"))
				check_valid_pos(mlx, x, y, len);
			x++;
		}
		y++;
	}
}

void	is_valid_map(char **map, t_mlx *mlx)
{
	char	**map_cpy;

	map_cpy = ft_copy_strs(map);
	check_char_in_map(map_cpy, mlx);
	flood_fill(map_cpy, 0, 0, mlx);
	ft_freef("%d", map_cpy);
}
