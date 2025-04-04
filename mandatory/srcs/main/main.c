#include "cub3d.h"

int	close_window(int keycode, t_mlx *mlx)
{
	if (keycode == 65307)
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

void init_mlx(t_mlx *mlx)
{
	mlx->link = mlx_init();
	if(!mlx)
		ft_error("wrong init mlx", true, mlx);
	mlx->screen = mlx_new_window(mlx->link, 800, 600, "Cube3D");
	if(!mlx->screen)
		ft_error("can't open screen", true, mlx);
	mlx_key_hook(mlx->screen, &close_window, mlx);
	mlx_hook(mlx->screen, 17, 0, &close_cross, mlx);
	mlx_loop(mlx->link);
}

int main(int argc, char *argv[])
{
	t_mlx	*mlx;
	char	**file;
	int		i;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	ft_memset(mlx, 0, sizeof(t_mlx));
	if (argc != 2)
		ft_error("invalid argument\n", true, mlx);
	file = get_file(argv[1], mlx);
	mlx->map = init_map(file, mlx);
	check_map(mlx);
	i = 0;
	init_element(file, mlx);
	init_mlx(mlx);
	return (ft_freef("%s", file), 0);
}
