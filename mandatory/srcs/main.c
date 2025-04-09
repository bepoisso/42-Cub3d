#include "cub3d.h"

void	put_pixel(int x, int y, int color, t_mlx *mlx)
{
	int	index;
	
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * mlx->size_line + x * mlx->bpp / 8;
	mlx->data[index] = color & 0xFF;
	mlx->data[index + 1] = (color >> 8) & 0xFF; 
	mlx->data[index + 2] = (color >> 16) & 0xFF;
}

void	clear_image(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, 0, mlx);
			x++;
		}
		y++;
	}
}

void	draw_square(int	x, int y, int size, int color, t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < size)
		put_pixel(x + i, y, color, mlx);
	i = -1;
	while (++i < size)
		put_pixel(x, y + i, color, mlx);
	i = -1;
	while (++i < size)
		put_pixel(x + size, y + i, color, mlx);
	i = -1;
	while (++i < size)
		put_pixel(x + i, y + size, color, mlx);
}

void	draw_map(t_mlx *mlx)
{
	char	**map;
	int		color;
	int		x;
	int		y;

	color = 0x00FF00;
	map = mlx->map->map;
	
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '1')
				draw_square(x * TEXTURE, y * TEXTURE, TEXTURE, color, mlx);
			x++;
		}
		y++;
	}
}

float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

float	fixed_dist(float x1, float y1, float x2, float y2, t_mlx *mlx)
{
	float delta_x;
	float delta_y;
	float angle;
	float fix_dist;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	angle = atan2(delta_y, delta_x) - mlx->player->angle;
	fix_dist = distance(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}

bool	touch(float px, float py, t_mlx *mlx)
{
	int x;
	int y;

	x = px / TEXTURE;
	y = py / TEXTURE;
	if (mlx->map->map[y][x] == '1')
		return (true);
	return (false);
}

// char	**get_map(void)
// {
// 	char	**map;
	
// 	map = (char **)malloc(sizeof(char *) * 11);
// 	map[0] = "111111111111111";
// 	map[1] = "100000000000001";
// 	map[2] = "100100000000001";
// 	map[3] = "100010000000001";
// 	map[4] = "100001000000001";
// 	map[5] = "100000000000001";
// 	map[6] = "100000000000001";
// 	map[7] = "100001111100001";
// 	map[8] = "100000000100001";
// 	map[9] = "111111111111111";
// 	map[10] = NULL;
// 	return (map);
// }

void	init_mlx(t_mlx *mlx)
{
	mlx->link = mlx_init();
	mlx->screen = mlx_new_window(mlx->link, WIDTH, HEIGHT, "CUB3D");
	mlx->img = mlx_new_image(mlx->link, WIDTH, HEIGHT);
	mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line, &mlx->endian);
	mlx_put_image_to_window(mlx->link, mlx->screen, mlx->img, 0, 0);
}

void	no_debug_draw_line(int ray_x, int ray_y, t_mlx *mlx, t_player *player, int i)
{
	float	dist;
	float	height;
	int		start_y;
	int		end;

	dist = fixed_dist(player->x, player->y, ray_x, ray_y, mlx);
	height = (TEXTURE / dist) * (WIDTH / 2);
	start_y = (HEIGHT - height) / 2;
	end = start_y + height;
	while (start_y < end)
	{
		put_pixel(i, start_y, 0x00FF00, mlx);
		start_y++;
	}
}

void	draw_line(t_player *player, t_mlx *mlx, float start_x, int i)
{
	float	cos_angle;
	float	sin_angle;
	float	ray_x;
	float	ray_y;

	cos_angle = cos(start_x);
	sin_angle = sin(start_x);
	ray_x = player->x;
	ray_y = player->y;

	while (!touch(ray_x, ray_y, mlx))
	{
		if (DEBUG)
			put_pixel(ray_x, ray_y, 0xFF0000, mlx);
		ray_x += cos_angle;
		ray_y += sin_angle;
	}
	if (!DEBUG)
		no_debug_draw_line(ray_x, ray_y, mlx, player, i);
}

int	draw_loop(t_mlx *mlx)
{
	float		fraction;
	float		start_x;
	int			i;
	
	move_player(mlx->player);
	clear_image(mlx);
	if (DEBUG)
	{
		draw_square(mlx->player->x, mlx->player->y, 10, 0xFFFFFF, mlx);
		draw_map(mlx);
	}
	fraction = PI / 3 / WIDTH;
	start_x = mlx->player->angle - PI / 6;
	i = 0;
	while (i < WIDTH)
	{
		draw_line(mlx->player, mlx, start_x, i);
		start_x += fraction;
		i++;
	}
	mlx_put_image_to_window(mlx->link, mlx->screen, mlx->img, 0, 0);
	return (0);
}

void	init_struct(t_mlx *mlx, char **av)
{
	char	**file;

	file = get_file(av[1], mlx);
	mlx->map = init_map(file, mlx->map, mlx);
	mlx->player = init_player(mlx->player);
	is_valid_map(mlx->map->map, mlx);
	mlx->element = (t_element *)malloc(sizeof(t_element));
	mlx->element->no_img = malloc(sizeof(t_img));
	mlx->element->so_img = malloc(sizeof(t_img));
	mlx->element->ea_img = malloc(sizeof(t_img));
	mlx->element->we_img = malloc(sizeof(t_img));

	mlx->element->flag_element = 0;
	init_element(file, mlx);
}

int	close_cross(t_mlx *mlx)
{
	//free_all(mlx);
	mlx_destroy_window(mlx->link, mlx->screen);
	mlx_destroy_display(mlx->link);
	//free();
	//free();
	exit(0);
}

int main(int ac, char **av)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	ft_memset(mlx, 0, sizeof(t_mlx));
	init_struct(mlx, av);
	init_mlx(mlx);
	mlx_hook(mlx->screen, 2, 1L<<0, key_press, mlx->player);
	mlx_hook(mlx->screen, 3, 1L<<1, key_release, mlx->player);
	mlx_loop_hook(mlx->link, draw_loop, mlx);
	mlx_loop(mlx->link);
	return (0);
}
