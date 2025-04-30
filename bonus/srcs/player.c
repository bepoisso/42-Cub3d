/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:31:36 by bepoisso          #+#    #+#             */
/*   Updated: 2025/04/30 12:31:37 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_player(t_player *player, t_map *map)
{
	player->shift = 1;
	player->mlx = map->mlx;
}

int	key_press(int keysym, t_player *player)
{
	if (keysym == XK_Escape)
		close_cross(player->mlx);
	if (keysym == 119)
		player->key_up = true;
	if (keysym == 115)
		player->key_down = true;
	if (keysym == 97)
		player->key_left = true;
	if (keysym == 100)
		player->key_right = true;
	if (keysym == XK_Left)
		player->left_rotate = true;
	if (keysym == XK_Right)
		player->right_rotate = true;
	if (keysym == 65505)
		player->shift = 2;
	if (keysym == 32)
		player->jump = true;
	if (keysym == XK_Control_L)
		player->crouch = true;
	if (keysym == XK_v)
		player->view = (player->view + 1) % 2;
	return (0);
}

int	key_release(int keysym, t_player *player)
{
	if (keysym == 119)
		player->key_up = false;
	if (keysym == 115)
		player->key_down = false;
	if (keysym == 97)
		player->key_left = false;
	if (keysym == 100)
		player->key_right = false;
	if (keysym == XK_Left)
		player->left_rotate = false;
	if (keysym == XK_Right)
		player->right_rotate = false;
	if (keysym == 65505)
		player->shift = 1;
	if (keysym == 32)
		player->jump = false;
	if (keysym == XK_Control_L)
		player->crouch = false;
	return (0);
}

static void	angle_player(t_player *player)
{
	if (player->left_rotate)
		player->angle -= A_SPEED * player->shift;
	if (player->right_rotate)
		player->angle += A_SPEED * player->shift;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
}

void	move_player(t_player *player)
{
	float	cos_angle;
	float	sin_angle;

	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	angle_player(player);
	if (player->key_up)
		move_key_up(player, cos_angle, sin_angle);
	if (player->key_down)
		move_key_down(player, cos_angle, sin_angle);
	if (player->key_left)
		move_key_left(player, cos_angle, sin_angle);
	if (player->key_right)
		move_key_right(player, cos_angle, sin_angle);
	move_key_jump(player);
}
