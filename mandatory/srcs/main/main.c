#include "cub3d.h"

int	close_window(int keycode, t_mlx *mlx)
{
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(mlx->link, mlx->screen);
		if (mlx->link)
			mlx_destroy_display(mlx->link);
		//free();
		//free();
		exit(0);
	}
	return (0);
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

void init_texture(t_element *element, t_mlx *mlx)
{
	int width;
	int height;

	// width = 128;
	// height = 128;
	element->no_img = mlx_xpm_file_to_image(mlx->link, element->no_texture, &width, &height);
	if (!element->no_img)
		ft_error("failed to load NO texture\n", true, mlx);
	element->so_img = mlx_xpm_file_to_image(mlx->link, element->so_texture, &width, &height);
	if (!element->so_img)
		ft_error("failed to load SO texture\n", true, mlx);
	element->we_img = mlx_xpm_file_to_image(mlx->link, element->we_texture, &width, &height);
	if (!element->we_img)
		ft_error("failed to load WE texture\n", true, mlx);
	element->ea_img = mlx_xpm_file_to_image(mlx->link, element->ea_texture, &width, &height);
	if (!element->ea_img)
		ft_error("failed to load NEA texture\n", true, mlx);
}

int	handling_input(int keysym, t_mlx *mlx)
{
	print_player(mlx, true);
	mlx_clear_window(mlx->link, mlx->screen);
	if (keysym == XK_Escape)
		close_window(keysym, mlx);
	else if (keysym == XK_Left)
	{
		ft_printf(BLUE"LEFT Rotate\n"RESET);
		mlx->player->angle -= 5;
		mlx->player->angle %= 360;
		if (mlx->player->angle < 0)
			mlx->player->angle += 360;
	}
	else if (keysym == XK_Right)
	{
		ft_printf(BLUE"RIGHT Rotate\n"RESET);
		mlx->player->angle += 5;
		mlx->player->angle %= 360;
	}
	else if (keysym == 119)
	{
		mlx->player->y -= 5;
		mlx->p_unite += 20;
		ft_printf(BLUE"FORWARD\n"RESET);
	}
	else if (keysym == 97)
	{
		ft_printf(BLUE"LEFT Strafe\n"RESET);
		mlx->player->x -= 5;
	}
	else if (keysym == 115)
	{
		mlx->player->y += 5;
		mlx->p_unite -= 20;
		ft_printf(BLUE"BACKWARD\n"RESET);
	}
	else if (keysym == 100)
	{
		ft_printf(BLUE"RIGHT Strafe\n"RESET);
		mlx->player->x += 5;
	}
	else
		ft_printf(YELLOW"%d key was pressed\n"RESET, keysym);
	draw_map(mlx);
	print_player(mlx, false);
	printf(VIOLET"angle of player %d\n"RESET, mlx->player->angle);
}

void init_mlx(t_mlx *mlx)
{
	mlx->link = mlx_init();
	if(!mlx->link)
		ft_error("wrong init mlx", true, mlx);
	init_texture(mlx->element, mlx);
	mlx->screen = mlx_new_window(mlx->link, WIN_WIDTH, WIN_HEIGHT, "Cube3D");
	if(!mlx->screen)
		ft_error("can't open screen", true, mlx);
	mlx_hook(mlx->screen, 17, 0, &close_cross, mlx);
	draw_map(mlx);
	mlx_hook(mlx->screen, 2, 1L << 0, &handling_input, mlx);
	mlx_loop(mlx->link);
}

int main(int argc, char *argv[])
{
	t_mlx	*mlx;
	char	**file;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	ft_memset(mlx, 0, sizeof(t_mlx));
	if (argc != 2)
		ft_error("invalid argument\n", true, mlx);
	file = get_file(argv[1], mlx);
	mlx->map = init_map(file, mlx);
	check_map(mlx);
	check_map_ff(mlx->map->map, mlx);	
	init_element(file, mlx);
	mlx->player = init_player(mlx);
	get_player_pos(mlx);
	mlx->p_unite = 128;
	init_mlx(mlx);
	return (ft_freef("%s", file), 0);
}
