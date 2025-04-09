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
	return (0);
}

int	key_release(int	keysym, t_player *player)
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
	return (0);
}

static void	angle_player(t_player *player)
{
	if (player->left_rotate)
		player->angle -= A_SPEED;
	if (player->right_rotate)
		player->angle += A_SPEED;
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
	{
		player->y += sin_angle * SPEED;
		player->x += cos_angle * SPEED;
	}
	if (player->key_down)
	{
		player->y -= sin_angle * SPEED;
		player->x -= cos_angle * SPEED;
	}
	if (player->key_left)
	{
		player->y -= cos_angle * SPEED;
		player->x += sin_angle * SPEED;
	}
	if (player->key_right)
	{
		player->y += cos_angle * SPEED;
		player->x -= sin_angle * SPEED;
	}
}

void get_player_pos(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (mlx->map->map[y])
	{
		x = 0;
		while (mlx->map->map[y][x])
		{
			if (ft_ischarset(mlx->map->map[y][x], "NSEW"))
			{
				mlx->player->x = x * TEXTURE;
				mlx->player->y = y * TEXTURE;
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
	y++;
}
}