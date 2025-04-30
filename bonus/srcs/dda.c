/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:30:53 by bepoisso          #+#    #+#             */
/*   Updated: 2025/04/30 12:32:08 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ray_impact(t_mlx *mlx, t_player *player)
{
	if (mlx->dda->side == 0)
	{
		mlx->dda->ray_x = mlx->dda->map_x * TEXTURE;
		if (mlx->dda->step_x < 0)
			mlx->dda->ray_x += TEXTURE;
		mlx->dda->ray_y = player->y + (mlx->dda->ray_x - player->x)
			* mlx->dda->sin_angle / mlx->dda->cos_angle;
	}
	else
	{
		mlx->dda->ray_y = mlx->dda->map_y * TEXTURE;
		if (mlx->dda->step_y < 0)
			mlx->dda->ray_y += TEXTURE;
		mlx->dda->ray_x = player->x + (mlx->dda->ray_y - player->y)
			* mlx->dda->cos_angle / mlx->dda->sin_angle;
	}
}

static void	ray_dda(t_mlx *mlx)
{
	while (1)
	{
		if (mlx->dda->side_x < mlx->dda->side_y)
		{
			mlx->dda->side_x += mlx->dda->delta_x;
			mlx->dda->map_x += mlx->dda->step_x;
			mlx->dda->side = 0;
		}
		else
		{
			mlx->dda->side_y += mlx->dda->delta_y;
			mlx->dda->map_y += mlx->dda->step_y;
			mlx->dda->side = 1;
		}
		if (mlx->map->map[mlx->dda->map_y][mlx->dda->map_x] == '1'
			|| mlx->map->map[mlx->dda->map_y][mlx->dda->map_x] == '2'
			|| mlx->map->map[mlx->dda->map_y][mlx->dda->map_x] == 'P')
			break ;
	}
}

static void	set_dda_step(t_mlx *mlx)
{
	if (mlx->dda->cos_angle < 0)
	{
		mlx->dda->step_x = -1;
		mlx->dda->side_x = (mlx->dda->ray_x - mlx->dda->map_x * TEXTURE)
			* mlx->dda->delta_x / TEXTURE;
	}
	else
	{
		mlx->dda->step_x = 1;
		mlx->dda->side_x = ((mlx->dda->map_x + 1) * TEXTURE - mlx->dda->ray_x)
			* mlx->dda->delta_x / TEXTURE;
	}
	if (mlx->dda->sin_angle < 0)
	{
		mlx->dda->step_y = -1;
		mlx->dda->side_y = (mlx->dda->ray_y - mlx->dda->map_y * TEXTURE)
			* mlx->dda->delta_y / TEXTURE;
	}
	else
	{
		mlx->dda->step_y = 1;
		mlx->dda->side_y = ((mlx->dda->map_y + 1) * TEXTURE - mlx->dda->ray_y)
			* mlx->dda->delta_y / TEXTURE;
	}
}

void	draw_line(t_player *player, t_mlx *mlx, float start_x, int i)
{
	init_drawing(mlx, player, start_x);
	set_dda_step(mlx);
	ray_dda(mlx);
	ray_impact(mlx, player);
	print_game(player, mlx, i, start_x);
}
