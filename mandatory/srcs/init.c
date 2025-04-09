#include "cub3d.h"

void	init_struct(t_mlx *mlx, char **av)
{
	char	**file;

	file = get_file(av[1], mlx);
	mlx->map = init_map(file, mlx->map, mlx);
	mlx->player = init_player(mlx->player, mlx->map);
	get_player_pos(mlx);
	is_valid_map(mlx->map->map, mlx);
	mlx->element = (t_element *)malloc(sizeof(t_element));
	mlx->element->no_img = malloc(sizeof(t_img));
	mlx->element->so_img = malloc(sizeof(t_img));
	mlx->element->ea_img = malloc(sizeof(t_img));
	mlx->element->we_img = malloc(sizeof(t_img));

	mlx->element->flag_element = 0;
	init_element(file, mlx);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->link = mlx_init();
	mlx->screen = mlx_new_window(mlx->link, WIDTH, HEIGHT, "CUB3D");
	mlx->img = mlx_new_image(mlx->link, WIDTH, HEIGHT);
	mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->size_line, &mlx->endian);
	mlx_put_image_to_window(mlx->link, mlx->screen, mlx->img, 0, 0);
}