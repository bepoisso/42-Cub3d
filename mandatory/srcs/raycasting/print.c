#include "cub3d.h"

void	print_wall(t_mlx *mlx, int unit)
{
	int	wall_width;
	int	wall_height;
	int	start_x;
	int	start_y;
	int	x;
	int	y;

	if (!mlx || !mlx->link || !mlx->screen)
		return ;
	wall_width = unit;
	wall_height = unit;
	start_x = (WIN_WIDTH / 2) - (wall_width / 2);
	start_y = (WIN_HEIGHT / 2) - (wall_height / 2);
	x = start_x;
	while (x < start_x + wall_width && x < WIN_WIDTH)
	{
		y = start_y;
		while (y < start_y + wall_height && y < WIN_HEIGHT)
		{
			mlx_pixel_put(mlx->link, mlx->screen, x, y, 0xFFFFFF);
			y++;
		}
		x++;
	}
}