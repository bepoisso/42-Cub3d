/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:31:27 by bepoisso          #+#    #+#             */
/*   Updated: 2025/04/30 12:31:28 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	mouse_move(int x, int y, t_mlx *mlx)
{
	double	angle_max;
	double	angle_diff;

	(void)y;
	if (x == WIDTH / 2)
		return (0);
	mlx_mouse_move(mlx->link, mlx->screen, WIDTH / 2, HEIGHT / 2);
	angle_max = 6.2831853072;
	if (mlx->player->debug)
		printf("*ANGLE*\nx : %d\nprev x : %f\nAngle origine :\
%f", x, mlx->player->prev_x, mlx->player->angle);
	angle_diff = (double)(x - WIDTH / 2) / SENSIBILITY;
	mlx->player->angle += angle_diff;
	if (mlx->player->angle < 0)
		mlx->player->angle += angle_max;
	if (mlx->player->angle > angle_max)
		mlx->player->angle = 0;
	if (mlx->player->debug)
		printf("Angle now %f\n--------------------\n", mlx->player->angle);
	return (0);
}
