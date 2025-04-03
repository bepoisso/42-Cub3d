#include "cub3d.h"

void	draw_wall(int x, int y, t_mlx *mlx, char wall)
{
	int height;
	int width;
	void	*wall_texture;

	height = TEXTURE;
	width = TEXTURE;
	if (wall == 'N')
		wall_texture = mlx->element->no_img;
	else if (wall == 'S')
		wall_texture = mlx->element->so_img;
	else if (wall == 'W')
		wall_texture = mlx->element->we_img;
	else if (wall == 'E')
		wall_texture = mlx->element->ea_img;
	else
		return;
	mlx_put_image_to_window(mlx->link, mlx->screen, wall_texture, x * width, y * height);
}

void	draw_map(t_mlx *mlx)
{
	int x;
	int y;

	y = 0;
	while (mlx->map->map[y])
	{
		x = 0;
		while (mlx->map->map[y][x])
		{
			if(mlx->map->map[y][x] == '1')
				draw_wall(x, y, mlx, 'E');
			x++;
		}
		y++;
	}
}
