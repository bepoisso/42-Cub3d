#include "cub3d.h"



int	mouse_move_handler(int x, int y, t_mlx *mlx)
{
	static int	last_x = WIDTH / 2;
	int			delta_x;
	float		rot_speed;

	printf("Mouse position: x = %d, y = %d\n", x, y);
	rot_speed = 0.03;
	delta_x = x - last_x;
	last_x = x;
	mlx->player->angle += delta_x * rot_speed;
	if (mlx->player->angle < 0)
		mlx->player->angle += 2* PI;
	else if (mlx->player->angle > 2 * PI)
		mlx->player->angle -= 2 * PI;
	mlx_mouse_move(mlx->link, mlx->screen, WIDTH / 2, HEIGHT / 2); 
	last_x = WIDTH / 2;
	return (0);
}