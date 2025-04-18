#include "cub3d.h"

t_player	*init_player(t_player *player, t_map *map)
{
	player = (t_player *)malloc(sizeof(t_player));
	ft_memset(player, 0, sizeof(t_player));
	player->key_up = false;
	player->key_down = false;
	player->key_right = false;
	player->key_left = false;
	player->left_rotate = false;
	player->right_rotate = false;
	player->shift = 1;
	player->mlx = map->mlx;
	return (player);
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
	float	x;
	float	y;

	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	angle_player(player);
	if (player->key_up)
	{
		y = player->y + sin_angle * SPEED * player->shift;
		x = player->x + cos_angle * SPEED * player->shift;
		if (player->mlx->map->map[(int)floorf(pixtof(y))]
			[(int)floorf(pixtof(x))] == '1')
			return ;
		player->y = y;
		player->x = x;
	}
	if (player->key_down)
	{
		y = player->y - sin_angle * SPEED * player->shift;
		x = player->x - cos_angle * SPEED * player->shift;
		if (player->mlx->map->map[(int)floorf(pixtof(y))]
			[(int)floorf(pixtof(x))] == '1')
			return ;
		player->y = y;
		player->x = x;
	}
	if (player->key_left)
	{
		y = player->y - cos_angle * SPEED * player->shift;
		x = player->x + sin_angle * SPEED * player->shift;
		if (player->mlx->map->map[(int)floorf(pixtof(y))]
			[(int)floorf(pixtof(x))] == '1')
			return ;
		player->y = y;
		player->x = x;
	}
	if (player->key_right)
	{
		y = player->y + cos_angle * SPEED * player->shift;
		x = player->x - sin_angle * SPEED * player->shift;
		if (player->mlx->map->map[(int)floorf(pixtof(y))]
			[(int)floorf(pixtof(x))] == '1')
			return ;
		player->y = y;
		player->x = x;
	}
}

void	get_player_pos(t_mlx *mlx)
{
	int	x;
	int	y;

	y = -1;
	while (mlx->map->map[++y])
	{
		x = 0;
		while (mlx->map->map[y][x])
		{
			if (ft_ischarset(mlx->map->map[y][x], "NSEW"))
			{
				mlx->player->x = (x * TEXTURE) + (TEXTURE / 2);
				mlx->player->y = (y * TEXTURE) + (TEXTURE / 2);
				if (mlx->map->map[y][x] == 'N')
					mlx->player->angle = degtorad((float)270);
				if (mlx->map->map[y][x] == 'S')
					mlx->player->angle = degtorad((float)90);
				if (mlx->map->map[y][x] == 'E')
					mlx->player->angle = degtorad((float)0);
				if (mlx->map->map[y][x] == 'W')
					mlx->player->angle = degtorad((float)180);
			}
			x++;
		}
	}
}
