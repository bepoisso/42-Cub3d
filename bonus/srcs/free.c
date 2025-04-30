/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:30:17 by bepoisso          #+#    #+#             */
/*   Updated: 2025/04/30 12:30:18 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map(t_map *map)
{
	if (map->map)
		ft_freef("%d", map->map);
	if (map->temp_map)
		ft_freef("%d", map->temp_map);
	free(map);
}

void	free_img(t_img *img, t_mlx *mlx)
{
	if (!img)
		return ;
	if (img->img)
		mlx_destroy_image(mlx->link, img->img);
	if (img->path)
		free(img->path);
	free(img);
}

void	free_ellement(t_mlx *mlx)
{
	t_element	*elm;

	elm = mlx->element;
	if (!elm)
		return ;
	if (elm->ea_img)
		free_img(elm->ea_img, mlx);
	if (elm->so_img)
		free_img(elm->so_img, mlx);
	if (elm->no_img)
		free_img(elm->no_img, mlx);
	if (elm->we_img)
		free_img(elm->we_img, mlx);
	if (elm->bopcat1)
		free_img(elm->bopcat1, mlx);
	if (elm->bopcat2)
		free_img(elm->bopcat2, mlx);
	if (elm->door)
		free_img(elm->door, mlx);
	free(elm);
}

void	free_mlx(t_mlx *mlx)
{
	if (mlx->temp_file)
		ft_freef("%d", mlx->temp_file);
	if (mlx->img)
		mlx_destroy_image(mlx->link, mlx->img);
	if (mlx->screen)
		mlx_destroy_window(mlx->link, mlx->screen);
	if (mlx->link)
	{
		mlx_destroy_display(mlx->link);
		free(mlx->link);
	}
	free(mlx);
}

void	free_all(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->dda)
		free(mlx->dda);
	if (mlx->element)
		free_ellement(mlx);
	if (mlx->player)
		free(mlx->player);
	if (mlx->map)
		free_map(mlx->map);
	if (mlx)
		free_mlx(mlx);
}
