#include "cub3d.h"

int	main(int ac, char **av)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	ft_memset(mlx, 0, sizeof(t_mlx));
	if (ac != 2)
		ft_error("invalid argument\n", true, mlx);
	init_struct(mlx, av);
	init_mlx(mlx);
	init_texture(mlx->element, mlx);
	mlx_hook(mlx->screen, 17, 0, &close_cross, mlx);
	mlx_hook(mlx->screen, 2, 1L << 0, key_press, mlx->player);
	mlx_hook(mlx->screen, 3, 1L << 1, key_release, mlx->player);
	mlx_hook(mlx->screen, 17, 0, close_cross, mlx->player);
	mlx_loop_hook(mlx->link, draw_loop, mlx);
	mlx_loop(mlx->link);
	return (0);
}
