#include "cub3d.h"

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

void	draw_square(int	x, int y, int size, int color, t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < size)
		put_pixel(x + i, y, color, mlx);
	i = -1;
	while (++i < size)
		put_pixel(x, y + i, color, mlx);
	i = -1;
	while (++i < size)
		put_pixel(x + size, y + i, color, mlx);
	i = -1;
	while (++i < size)
		put_pixel(x + i, y + size, color, mlx);
}

void	draw_map(t_mlx *mlx)
{
	char	**map;
	int		color;
	int		x;
	int		y;

	color = 0x00FF00;
	map = mlx->map->map;
	
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_square(x * TEXTURE, y * TEXTURE, TEXTURE, color, mlx);
			x++;
		}
		y++;
	}
}

int	draw_loop(t_mlx *mlx)
{
	float		fraction;
	float		start_x;
	int			i;
	
	move_player(mlx->player);
	clear_image(mlx);
	if (DEBUG)
	{
		draw_square(mlx->player->x, mlx->player->y, 10, 0xFFFFFF, mlx);
		draw_map(mlx);
	}
	fraction = PI / 3 / WIDTH;
	start_x = mlx->player->angle - PI / 6;
	i = 0;
	while (i < WIDTH)
	{
		draw_line(mlx->player, mlx, start_x, i);
		start_x += fraction;
		i++;
	}
	mlx_put_image_to_window(mlx->link, mlx->screen, mlx->img, 0, 0);
	return (0);
}