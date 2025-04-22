#include "cub3d.h"

void	move_key_up(t_player *player, float cos_angle, float sin_angle)
{
	float	x;
	float	y;

	y = player->y + sin_angle * SPEED * player->shift;
	x = player->x + cos_angle * SPEED * player->shift;
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

	y = player->y - sin_angle * SPEED * player->shift;
	x = player->x - cos_angle * SPEED * player->shift;
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

	y = player->y - cos_angle * SPEED * player->shift;
	x = player->x + sin_angle * SPEED * player->shift;
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

	y = player->y + cos_angle * SPEED * player->shift;
	x = player->x - sin_angle * SPEED * player->shift;
	if (player->mlx->map->map[(int)floorf(pixtof(y))]
		[(int)floorf(pixtof(x))] == '1')
		return ;
	player->y = y;
	player->x = x;
}
