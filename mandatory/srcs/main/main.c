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

void init_mlx(t_mlx *mlx)
{
	mlx->link = mlx_init();
	if(!mlx)
		ft_error("wrong init mlx", true);
	mlx->screen = mlx_new_window(mlx->link, 800, 600, "Cube3D");
	if(!mlx->screen)
		ft_error("can't open screen", true);
	mlx_key_hook(mlx->screen, &close_window, mlx);
	mlx_hook(mlx->screen, 17, 0, &close_cross, mlx);
	mlx_loop(mlx->link);
}

int main(int argc, char *argv[])
{
	t_mlx	*mlx;
	char	**map;
	int		i;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	ft_memset(mlx, 0, sizeof(t_mlx));
	if (argc != 2)
		ft_error("invalid argument\n", true);
	map = get_file(argv[1]);
	i = 0;
	init_element(map, mlx->element);
	init_mlx(mlx);
	return (0);
}
