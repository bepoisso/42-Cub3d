#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	t_mlx	*mlx;

	if (ac != 2)
		return (ft_putstr_fd("invalid argument\n", 2), 1);
	mlx = alloc_all();
	init_struct(mlx, av);
	init_mlx(mlx);
	init_texture(mlx->element, mlx);
	// mlx_mouse_hide(mlx->link, mlx->screen);
	mlx_hook(mlx->screen, 6, 1L << 6, &mouse_move, mlx);
	mlx_hook(mlx->screen, 17, 0, &close_cross, mlx);
	mlx_hook(mlx->screen, 2, 1L << 0, key_press, mlx->player);
	mlx_hook(mlx->screen, 3, 1L << 1, key_release, mlx->player);
	mlx_hook(mlx->screen, 17, 0, close_cross, mlx->player);
	gettimeofday(&mlx->last_time, NULL);
	mlx_loop_hook(mlx->link, draw_loop, mlx);
	mlx_loop(mlx->link);
	return (0);
}
