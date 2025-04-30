/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:31:25 by bepoisso          #+#    #+#             */
/*   Updated: 2025/04/30 12:32:45 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_square_minimap(t_draw *sqrt, t_draw circle, t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < sqrt->size)
		if (is_in_circle(sqrt->x + i, sqrt->y, circle))
			put_pixel(sqrt->x + i, sqrt->y, sqrt->color, mlx);
	i = -1;
	while (++i < sqrt->size)
		if (is_in_circle(sqrt->x + i, sqrt->y + sqrt->size, circle))
			put_pixel(sqrt->x + i, sqrt->y + sqrt->size, sqrt->color, mlx);
	i = -1;
	while (++i < sqrt->size)
		if (is_in_circle(sqrt->x, sqrt->y + i, circle))
			put_pixel(sqrt->x, sqrt->y + i, sqrt->color, mlx);
	i = -1;
	while (++i < sqrt->size)
		if (is_in_circle(sqrt->x + sqrt->size, sqrt->y + i, circle))
			put_pixel(sqrt->x + sqrt->size, sqrt->y + i, sqrt->color, mlx);
}

void	draw_filled_circle(t_draw *circle, t_mlx *mlx)
{
	int	x;
	int	y;
	int	radius;

	radius = circle->radius * circle->radius;
	y = -circle->radius;
	while (y <= circle->radius)
	{
		x = -circle->radius;
		while (x <= circle->radius)
		{
			if (x * x + y * y <= radius)
			{
				put_pixel(circle->x + x, circle->y + y, 0x303030, mlx);
			}
			x++;
		}
		y++;
	}
}

void	draw_line_minimap(t_mlx *mlx, int color, int i, float steps)
{
	float	x_inc;
	float	y_inc;
	float	x;
	float	y;
	t_draw	circle;

	circle = init_circle_minimap();
	steps = fmax(fabs(mlx->dda->ray_x - mlx->player->x / ZOOM_MM),
			fabs((mlx->dda->ray_y - mlx->player->y) / ZOOM_MM));
	y_inc = ((mlx->dda->ray_y - mlx->player->y) / ZOOM_MM) / steps;
	x_inc = ((mlx->dda->ray_x - mlx->player->x) / ZOOM_MM) / steps;
	x = WIDTH / RATIO_MINIMAP;
	y = WIDTH / RATIO_MINIMAP;
	while (i <= steps)
	{
		if (is_in_circle(x, y, circle))
			put_pixel(x, y, color, mlx);
		x += x_inc;
		y += y_inc;
		i++;
	}
}

void	check_square_position(t_mlx *mlx, t_draw sqrt, t_draw circle)
{
	int		map_x;
	int		map_y;
	char	**map;

	map = mlx->map->map;
	map_max(mlx->map);
	map_y = 0;
	while (map[map_y])
	{
		map_x = 0;
		while (map[map_y][map_x])
		{
			sqrt.x = (map_x * MM_SCALE)
				- (int)(mlx->player->x / ZOOM_MM) + WIDTH / RATIO_MINIMAP;
			sqrt.y = (map_y * MM_SCALE)
				- (int)(mlx->player->y / ZOOM_MM) + WIDTH / RATIO_MINIMAP;
			if (map[map_y][map_x] == '1' || map[map_y][map_x] == '2')
				draw_square_minimap(&sqrt, circle, mlx);
			map_x++;
		}
		map_y++;
	}
}

void	draw_circle_minimap(t_mlx *mlx)
{
	t_draw	sqrt;
	t_draw	circle;

	sqrt = init_sqrt_minimap();
	circle = init_circle_minimap();
	draw_circle(&circle, mlx);
	check_square_position(mlx, sqrt, circle);
	circle.radius = 5;
	circle.color = 0xFFFFFF;
	draw_circle(&circle, mlx);
}
