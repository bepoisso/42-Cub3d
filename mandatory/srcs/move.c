/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:31:29 by bepoisso          #+#    #+#             */
/*   Updated: 2025/04/30 12:31:30 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	move_key_up(t_player *player, float cos_angle, float sin_angle)
{
	float	x;
	float	y;
	int		speed;

	speed = SPEED;
	if (player->crouch)
		speed /= 2;
	y = player->y + sin_angle * speed * player->shift;
	x = player->x + cos_angle * speed * player->shift;
	if (player->mlx->map->map[(int)floorf(pixtof(y))]
		[(int)floorf(pixtof(x))] == '1'
		|| player->mlx->map->map[(int)floorf(pixtof(y))]
		[(int)floorf(pixtof(x))] == '2')
		return ;
	player->y = y;
	player->x = x;
}

void	move_key_down(t_player *player, float cos_angle, float sin_angle)
{
	float	x;
	float	y;
	int		speed;

	speed = SPEED;
	if (player->crouch)
		speed /= 2;
	y = player->y - sin_angle * speed * player->shift;
	x = player->x - cos_angle * speed * player->shift;
	if (player->mlx->map->map[(int)floorf(pixtof(y))]
		[(int)floorf(pixtof(x))] == '1'
		|| player->mlx->map->map[(int)floorf(pixtof(y))]
		[(int)floorf(pixtof(x))] == '2')
		return ;
	player->y = y;
	player->x = x;
}

void	move_key_left(t_player *player, float cos_angle, float sin_angle)
{
	float	x;
	float	y;
	int		speed;

	speed = SPEED;
	if (player->crouch)
		speed /= 2;
	y = player->y - cos_angle * speed * player->shift;
	x = player->x + sin_angle * speed * player->shift;
	if (player->mlx->map->map[(int)floorf(pixtof(y))]
		[(int)floorf(pixtof(x))] == '1'
		|| player->mlx->map->map[(int)floorf(pixtof(y))]
		[(int)floorf(pixtof(x))] == '2')
		return ;
	player->y = y;
	player->x = x;
}

void	move_key_right(t_player *player, float cos_angle, float sin_angle)
{
	float	x;
	float	y;
	int		speed;

	speed = SPEED;
	if (player->crouch)
		speed /= 2;
	y = player->y + cos_angle * speed * player->shift;
	x = player->x - sin_angle * speed * player->shift;
	if (player->mlx->map->map[(int)floorf(pixtof(y))]
		[(int)floorf(pixtof(x))] == '1'
		|| player->mlx->map->map[(int)floorf(pixtof(y))]
		[(int)floorf(pixtof(x))] == '2')
		return ;
	player->y = y;
	player->x = x;
}

void	move_key_jump(t_player *player)
{
	static bool	pressed = false;
	static bool	top = false;

	if (!(pressed) && player->jump)
		pressed = true;
	if (pressed)
	{
		if (player->jump_value < JUMP_MAX && !top)
			player->jump_value += JUMP;
		if (player->jump_value >= JUMP_MAX)
			top = true;
		if (top)
			player->jump_value -= JUMP;
		if (player->jump_value < 0)
			player->jump_value = 0;
	}
	if (player->jump_value == 0)
	{
		pressed = false;
		top = false;
	}
}
