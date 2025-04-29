#include "../includes/cub3d.h"

t_element	*alloc_ellement(t_mlx *mlx)
{
	t_element	*element;

	element = (t_element *)malloc(sizeof(t_element));
	ft_memset(element, 0, sizeof(t_element));
	element->no_img = malloc(sizeof(t_img));
	element->no_img->mlx = mlx;
	ft_memset(element->no_img, 0, sizeof(t_img));
	element->so_img = malloc(sizeof(t_img));
	element->so_img->mlx = mlx;
	ft_memset(element->so_img, 0, sizeof(t_img));
	element->ea_img = malloc(sizeof(t_img));
	element->ea_img->mlx = mlx;
	ft_memset(element->ea_img, 0, sizeof(t_img));
	element->we_img = malloc(sizeof(t_img));
	element->we_img->mlx = mlx;
	ft_memset(element->we_img, 0, sizeof(t_img));
	element->bopcat1 = malloc(sizeof(t_img));
	element->bopcat1->mlx = mlx;
	ft_memset(element->bopcat1, 0, sizeof(t_img));
	element->bopcat2 = malloc(sizeof(t_img));
	element->bopcat2->mlx = mlx;
	ft_memset(element->bopcat2, 0, sizeof(t_img));
	return (element);
}

void	init_struct(t_mlx *mlx, char **av)
{
	char	**file;

	file = get_file(av[1], mlx);
	mlx->map = init_map(file, mlx->map, mlx);
	mlx->player = init_player(mlx->player, mlx->map);
	if (get_player_pos(mlx, 0, -1))
		ft_error("no player in map", true, mlx);
	is_valid_map(mlx->map->map, mlx);
	mlx->element = alloc_ellement(mlx);
	mlx->dda = malloc(sizeof(t_dda));
	ft_memset(mlx->dda, 0, sizeof(t_dda));
	init_element(file, mlx);
	ft_freef("%d", file);
}

void	init_mlx(t_mlx *mlx)
{
	mlx->link = mlx_init();
	mlx->screen = mlx_new_window(mlx->link, WIDTH, HEIGHT, "CUB3D");
	mlx->img = mlx_new_image(mlx->link, WIDTH, HEIGHT);
	mlx->data = mlx_get_data_addr(mlx->img, &mlx->bpp,
			&mlx->size_line, &mlx->endian);
	mlx_put_image_to_window(mlx->link, mlx->screen, mlx->img, 0, 0);
}

static void	load_texture(t_img *img, void *mlx, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (!img->img)
		ft_error("failed to load texture\n", true, mlx);
	img->add = mlx_get_data_addr(img->img, &img->bpp,
			&img->line_len, &img->endian);
	if (!img->add)
		ft_error("failed to load pixel adress\n", true, mlx);
}

void	init_texture(t_element *element, t_mlx *mlx)
{
	load_texture(element->no_img, mlx->link, element->no_img->path);
	load_texture(element->so_img, mlx->link, element->so_img->path);
	load_texture(element->we_img, mlx->link, element->we_img->path);
	load_texture(element->ea_img, mlx->link, element->ea_img->path);
	load_texture(element->bopcat1, mlx->link, "./assets/textures/bopcat1.xpm");
	load_texture(element->bopcat2, mlx->link, "./assets/textures/bopcat2.xpm");
	if (!mlx->element->we_img)
		printf("Error: WE texture not loaded!\n");
}
