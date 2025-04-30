/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:31:19 by bepoisso          #+#    #+#             */
/*   Updated: 2025/04/30 12:31:20 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	alloc_ellement(t_mlx *mlx, t_element *element)
{
	element->no_img->mlx = mlx;
	element->so_img->mlx = mlx;
	element->ea_img->mlx = mlx;
	element->we_img->mlx = mlx;
	element->bopcat1->mlx = mlx;
	element->bopcat2->mlx = mlx;
	element->door->mlx = mlx;
}

void	init_struct(t_mlx *mlx, char **av)
{
	mlx->temp_file = get_file(av[1], mlx);
	init_map(mlx->temp_file, mlx->map, mlx);
	init_player(mlx->player, mlx->map);
	alloc_ellement(mlx, mlx->element);
	is_valid_map(mlx->map->map, mlx);
	init_element(mlx->temp_file, mlx);
	if (get_player_pos(mlx, 0, -1))
		ft_error("no player in map", true, mlx);
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
	mlx->element->bopcat1->path = ft_strdup("./assets/textures/bopcat1.xpm");
	mlx->element->bopcat2->path = ft_strdup("./assets/textures/bopcat2.xpm");
	mlx->element->door->path = ft_strdup("./assets/textures/door.xpm");
	load_texture(element->no_img, mlx->link, element->no_img->path);
	load_texture(element->so_img, mlx->link, element->so_img->path);
	load_texture(element->we_img, mlx->link, element->we_img->path);
	load_texture(element->ea_img, mlx->link, element->ea_img->path);
	load_texture(element->bopcat1, mlx->link, mlx->element->bopcat1->path);
	load_texture(element->bopcat2, mlx->link, mlx->element->bopcat2->path);
	load_texture(element->door, mlx->link, mlx->element->door->path);
}
