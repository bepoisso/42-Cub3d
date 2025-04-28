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
		[(int)floorf(pixtof(x))] == '1')
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
		[(int)floorf(pixtof(x))] == '1')
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
		[(int)floorf(pixtof(x))] == '1')
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
		[(int)floorf(pixtof(x))] == '1')
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
