/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:31:38 by bepoisso          #+#    #+#             */
/*   Updated: 2025/04/30 12:33:02 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_texture_color(t_img *texture, int tex_x, int tex_y)
{
	int	pixel_pos;

	if (tex_x < 0 || tex_x >= texture->width || tex_y < 0
		|| tex_y >= texture->height)
		return (0x000000);
	pixel_pos = tex_y * texture->line_len + tex_x * (texture->bpp / 8);
	return (*(int *)(texture->add + pixel_pos));
}

void	draw_floor_and_cieling(t_mlx *mlx)
{
	int	x;
	int	y;
	int	crouch;

	crouch = 0;
	if (mlx->player->crouch)
		crouch = -100;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < HEIGHT / 2 + mlx->player->jump_value + crouch)
				put_pixel(x, y, mlx->element->cieling_color, mlx);
			else
				put_pixel(x, y, mlx->element->floor_color, mlx);
			x++;
		}
		y++;
	}
}

void	draw_line_2d(t_mlx *mlx, int color, int i)
{
	float	steps;
	float	x_inc;
	float	y_inc;
	float	x;
	float	y;

	steps = fmax(fabs(mlx->dda->ray_x - mlx->player->x),
			fabs(mlx->dda->ray_y - mlx->player->y));
	y_inc = (mlx->dda->ray_y - mlx->player->y) / steps;
	x_inc = (mlx->dda->ray_x - mlx->player->x) / steps;
	x = mlx->player->x;
	y = mlx->player->y;
	while (i <= steps)
	{
		put_pixel(x, y, color, mlx);
		x += x_inc;
		y += y_inc;
		i++;
	}
}

void	print_game(t_player *player, t_mlx *mlx, int i, float ray_angle)
{
	t_draw	circle;

	circle = init_circle_minimap();
	if (player->debug)
		draw_line_2d(mlx, 0xFF0000, 0);
	if (!player->debug)
	{
		draw_textured_wall(mlx, player, i, ray_angle);
		if (player->view)
			draw_line_minimap(mlx, 0x404040, 0, 0);
	}
}

void	init_drawing(t_mlx *mlx, t_player *player, float start_x)
{
	mlx->dda->map_x = (int)(player->x / TEXTURE);
	mlx->dda->map_y = (int)(player->y / TEXTURE);
	mlx->dda->cos_angle = cos(start_x);
	mlx->dda->sin_angle = sin(start_x);
	mlx->dda->ray_x = player->x;
	mlx->dda->ray_y = player->y;
	mlx->dda->delta_x = fabs(1 / mlx->dda->cos_angle) * TEXTURE;
	mlx->dda->delta_y = fabs(1 / mlx->dda->sin_angle) * TEXTURE;
}
