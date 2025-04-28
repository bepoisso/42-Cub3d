#include "cub3d.h"

void	draw_square(t_draw *sqrt, t_mlx *mlx)
{
	int	i;
	
	i = -1;
	while (++i < sqrt->size)
		put_pixel(sqrt->x + i, sqrt->y, sqrt->color, mlx);
	i = -1;
	while (++i < sqrt->size)
		put_pixel(sqrt->x, sqrt->y + i, sqrt->color, mlx);
	i = -1;
	while (++i < sqrt->size)
		put_pixel(sqrt->x + sqrt->size, sqrt->y + i, sqrt->color, mlx);
	i = -1;
	while (++i < sqrt->size)
		put_pixel(sqrt->x + i, sqrt->y + sqrt->size, sqrt->color, mlx);
}

void	draw_circle(t_draw *circle, t_mlx *mlx)
{
	float	i;
	float	angle;
	float	x1;
	float	y1;

	i = 0;
	while (i < 360)
	{
		angle = i;
		x1 = circle->radius * cos(angle * PI / 180);
		y1 = circle->radius * sin(angle * PI / 180);
		put_pixel(circle->x + x1, circle->y + y1, circle->color, mlx);
		i += 0.1;
	}
}

void	draw_map(t_mlx *mlx)
{
	char	**map;
	int		x;
	int		y;
	t_draw	sqrt;

	sqrt.color = 0x00FF00;
	map = mlx->map->map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
			{
				sqrt.x = x * TEXTURE;
				sqrt.y = y * TEXTURE;
				sqrt.size = TEXTURE;
				draw_square(&sqrt, mlx);
			}
			x++;
		}
		y++;
	}
}

void	debug_draw_loop(t_mlx *mlx)
{
	t_draw	circle;

	circle.x = mlx->player->x;
	circle.y = mlx->player->y;
	circle.radius = 5;
	circle.color = 0xFFFFFF;
	draw_circle(&circle, mlx);
	draw_map(mlx);
}

long	time_in_ms(struct timeval *time)
{
	return(time->tv_sec * 1000 + time->tv_usec / 1000);
}

void	get_time(t_mlx *mlx)
{
	struct timeval	current_time;
	long	time_pass;
	static int	time = 0;

	gettimeofday(&current_time, NULL);
	time_pass = time_in_ms(&current_time) - time_in_ms(&mlx->last_time);
	mlx->frame_count++;
	if(time_pass >= 250)
	{
		time = mlx->frame_count * 4;
		printf("fps = %d\n", mlx->frame_count * 4);
		mlx->frame_count = 0;
		mlx->last_time = current_time;
	}
	mlx_string_put(mlx->link, mlx->screen, 5, 10, 0xFFFFFF, "FPS : ");
	mlx_string_put(mlx->link, mlx->screen, 50, 10, 0xFFFFFF, ft_itoa(time));
}

//void	draw_circle

int	draw_loop(t_mlx *mlx)
{
	float		fraction;
	float		start_x;
	int			i;

	move_player(mlx->player);
	clear_image(mlx);
	if (mlx->player->debug)
		debug_draw_loop(mlx);
	else
		draw_floor_and_cieling(mlx);
	i = 0;
	while (i < WIDTH)
	{
		fraction = 2.0 * i / (float)WIDTH - 1.0;
		start_x = mlx->player->angle + atan(fraction * tan(FOV / 2));
		draw_line(mlx->player, mlx, start_x, i);
		start_x += fraction;
		i++;
	}
	mlx_put_image_to_window(mlx->link, mlx->screen, mlx->img, 0, 0);
	get_time(mlx);
	if (!mlx->player->debug)
		draw_circle_minimap(mlx);

	return (0);
}
