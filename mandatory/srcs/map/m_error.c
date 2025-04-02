#include "cub3d.h"

static int	check_validchar(char **map)
{
	int	y;
	int x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_ischarset(map[y][x], ELEM) == 0)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

static int	check_only_one_player(char **map)
{
	bool	check;
	int x;
	int y;
	
	check = false;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (ft_ischarset(map[y][x], "NSEW"))
			{
				if (!check)
					check = true;
				else if (check)
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

void	check_map(t_mlx *mlx)
{
	if (check_validchar(mlx->map->map))
		ft_error("invalid character in map\n", true, mlx);
	if (check_only_one_player(mlx->map->map))
		ft_error("multiple player in map\n", true, mlx);
}