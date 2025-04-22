#include "cub3d.h"

int	close_cross(t_mlx *mlx)
{
	free_all(mlx);
	exit(0);
}

void	put_pixel(int x, int y, int color, t_mlx *mlx)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * mlx->size_line + x * mlx->bpp / 8;
	mlx->data[index] = color & 0xFF;
	mlx->data[index + 1] = (color >> 8) & 0xFF;
	mlx->data[index + 2] = (color >> 16) & 0xFF;
}

void	clear_image(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, 0, mlx);
			x++;
		}
		y++;
	}
}
