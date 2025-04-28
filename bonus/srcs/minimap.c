#include <cub3d.h>


void	draw_square_minimap(t_draw *sqrt, t_draw circle, t_mlx *mlx)
{
	int	i;
	
	if (is_in_circle(sqrt->x, sqrt->y, circle))
	{
		i = -1;
		while (++i < sqrt->size)
		{
			if (is_in_circle(sqrt->x + i, sqrt->y, circle))
				put_pixel(sqrt->x + i, sqrt->y, sqrt->color, mlx);
		}
		i = -1;
		while (++i < sqrt->size)
		{
			if (is_in_circle(sqrt->x, sqrt->y + i, circle))
				put_pixel(sqrt->x, sqrt->y + i, sqrt->color, mlx);
		}
		i = -1;
		while (++i < sqrt->size)
		{
			if (is_in_circle(sqrt->x + sqrt->size, sqrt->y + i, circle))
				put_pixel(sqrt->x + sqrt->size, sqrt->y + i, sqrt->color, mlx);
		}
		i = -1;
		while (++i < sqrt->size)
		{
			if (is_in_circle(sqrt->x + i, sqrt->y + sqrt->size, circle))
			put_pixel(sqrt->x + i, sqrt->y + sqrt->size, sqrt->color, mlx);
		}
	}
}
static t_draw	init_sqrt_minimap(void)
{
	t_draw	sqrt;

	sqrt.size = 20;
	sqrt.color = 0xFF0000;
	return (sqrt);
}

static t_draw	init_circle_minimap(void)
{
	t_draw	circle;

	circle.x = 300;
	circle.y = 300;
	circle.radius = 150;
	circle.color = 0xFFFFFF;
	return (circle);
}

bool	is_in_circle(int x, int y, t_draw circle)
{
	int dx = x - circle.x;
	int dy = y - circle.y;
	return (dx * dx + dy * dy <= circle.radius * circle.radius);
}

void	draw_circle_minimap(t_mlx *mlx)
{
	int	map_x;
	int	map_y;
	char **map;
	t_draw	sqrt;
	t_draw	circle;

	map = mlx->map->map;
	map_max(mlx->map);
	sqrt = init_sqrt_minimap();
	circle = init_circle_minimap();
	draw_circle(&circle, mlx);
	map_y = 0;
	while (map[map_y])
	{
		map_x = 0;
		while (map[map_y][map_x])
		{
			sqrt.x = (map_x * MM_SCALE) - (int)(mlx->player->x / 3) + 300;
			sqrt.y = (map_y * MM_SCALE) - (int)(mlx->player->y / 3) + 300;
			if (map[map_y][map_x] == '1' && is_in_circle(sqrt.x + sqrt.size / 2, sqrt.y + sqrt.size / 2, circle))
				draw_square_minimap(&sqrt, circle, mlx);
			map_x++;
		}
		map_y++;
	}
	circle.radius = 5;
	circle.color = 0xFFFFFF;
	draw_circle(&circle, mlx);
}

