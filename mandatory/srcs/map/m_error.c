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

void	check_map(t_mlx *mlx)
{
	if (check_validchar(mlx->map->map))
		ft_error("Invalid character in map\n", true, mlx);
}