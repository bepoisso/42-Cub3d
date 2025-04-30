/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:31:16 by bepoisso          #+#    #+#             */
/*   Updated: 2025/04/30 12:31:17 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	print_dir(t_mlx *mlx)
{
	int	angle;

	angle = (int)radtodeg(mlx->player->angle);
	mlx_string_put(mlx->link, mlx->screen, 5, 75, 0xFFFFFF, "View : ");
	if (angle >= 315 || angle <= 45)
		mlx_string_put(mlx->link, mlx->screen, 50, 75, 0xFFFFFF, "East");
	else if (angle <= 135)
		mlx_string_put(mlx->link, mlx->screen, 50, 75, 0xFFFFFF, "South");
	else if (angle <= 225)
		mlx_string_put(mlx->link, mlx->screen, 50, 75, 0xFFFFFF, "West");
	else
		mlx_string_put(mlx->link, mlx->screen, 50, 75, 0xFFFFFF, "North");
}

static void	print_fps(t_mlx *mlx)
{
	char	*temp;

	mlx_string_put(mlx->link, mlx->screen, 5, 10, 0xFFFFFF, "FPS : ");
	temp = ft_itoa(mlx->time);
	mlx_string_put(mlx->link, mlx->screen, 50, 10, 0xFFFFFF, temp);
	free(temp);
}

static void	print_player(t_mlx *mlx)
{
	char	*temp;

	mlx_string_put(mlx->link, mlx->screen, 5, 30, 0xFFFFFF, "X : ");
	temp = ft_itoa(mlx->player->x);
	mlx_string_put(mlx->link, mlx->screen, 50, 30, 0xFFFFFF, temp);
	free(temp);
	mlx_string_put(mlx->link, mlx->screen, 5, 40, 0xFFFFFF, "Y : ");
	temp = ft_itoa(mlx->player->y);
	mlx_string_put(mlx->link, mlx->screen, 50, 40, 0xFFFFFF, temp);
	free(temp);
	mlx_string_put(mlx->link, mlx->screen, 5, 50, 0xFFFFFF, "Z : ");
	temp = ft_itoa(mlx->player->jump_value);
	mlx_string_put(mlx->link, mlx->screen, 50, 50, 0xFFFFFF, temp);
	free(temp);
	mlx_string_put(mlx->link, mlx->screen, 5, 65, 0xFFFFFF, "Angle : ");
	temp = ft_itoa((int)radtodeg(mlx->player->angle));
	mlx_string_put(mlx->link, mlx->screen, 50, 65, 0xFFFFFF, temp);
	free(temp);
}

void	print_hud(t_mlx *mlx)
{
	print_fps(mlx);
	print_player(mlx);
	print_dir(mlx);
}
