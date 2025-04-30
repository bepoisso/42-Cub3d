/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:30:54 by bepoisso          #+#    #+#             */
/*   Updated: 2025/04/30 12:32:11 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static bool	check_door_prox(int x, int y, t_mlx *mlx, char c)
{
	char	**map;

	map = mlx->map->map;
	if (map[y][x] == c
		|| map[y - 1][x] == c
		|| map[y + 1][x] == c
		|| map[y][x + 1] == c
		|| map[y][x - 1] == c)
		return (true);
	return (false);
}

static void	get_door_pos(int *x, int *y, t_mlx *mlx)
{
	char	**map;

	map = mlx->map->map;
	if (map[*y][*x] == 'P')
		return ;
	if (map[(*y) - 1][*x] == 'P')
	{
		(*y)--;
		return ;
	}
	if (map[(*y) + 1][*x] == 'P')
	{
		(*y)++;
		return ;
	}
	if (map[*y][(*x) + 1] == 'P')
	{
		(*x)++;
		return ;
	}
	if (map[*y][(*x) - 1] == 'P')
	{
		(*x)--;
		return ;
	}
}

void	door_handling(t_mlx *mlx, t_player *player)
{
	int			x;
	int			y;
	static int	px = 0;
	static int	py = 0;

	x = (int)floor(pixtof(player->x));
	y = (int)floor(pixtof(player->y));
	if (!check_door_prox(x, y, mlx, 'P') && !check_door_prox(x, y, mlx, 'Q'))
	{
		if (mlx->map->map[py][px] == 'Q')
			mlx->map->map[py][px] = 'P';
		py = 0;
		px = 0;
		return ;
	}
	else if (check_door_prox(x, y, mlx, 'P'))
	{
		px = x;
		py = y;
		get_door_pos(&px, &py, mlx);
		mlx->map->map[py][px] = 'Q';
	}
}
