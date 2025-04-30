/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:30:25 by bepoisso          #+#    #+#             */
/*   Updated: 2025/04/30 12:30:26 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	alloc_element(t_mlx *mlx)
{
	ft_memset(mlx->element->so_img, 0, sizeof(t_img));
	mlx->element->we_img = (t_img *)malloc(sizeof(t_img));
	ft_memset(mlx->element->we_img, 0, sizeof(t_img));
	mlx->element->ea_img = (t_img *)malloc(sizeof(t_img));
	ft_memset(mlx->element->ea_img, 0, sizeof(t_img));
	mlx->element->bopcat1 = (t_img *)malloc(sizeof(t_img));
	ft_memset(mlx->element->bopcat1, 0, sizeof(t_img));
	mlx->element->bopcat2 = (t_img *)malloc(sizeof(t_img));
	ft_memset(mlx->element->bopcat2, 0, sizeof(t_img));
	mlx->element->door = (t_img *)malloc(sizeof(t_img));
	ft_memset(mlx->element->door, 0, sizeof(t_img));
}

static void	handling_linkage(t_mlx *mlx)
{
	mlx->player->mlx = mlx;
	mlx->map->mlx = mlx;
	mlx->element->mlx = mlx;
	mlx->element->no_img->mlx = mlx;
	mlx->element->so_img->mlx = mlx;
	mlx->element->ea_img->mlx = mlx;
	mlx->element->we_img->mlx = mlx;
}

t_mlx	*alloc_all(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	ft_memset(mlx, 0, sizeof(t_mlx));
	mlx->map = (t_map *)malloc(sizeof(t_map));
	ft_memset(mlx->map, 0, sizeof(t_map));
	mlx->player = (t_player *)malloc(sizeof(t_player));
	ft_memset(mlx->player, 0, sizeof(t_player));
	mlx->element = (t_element *)malloc(sizeof(t_element));
	ft_memset(mlx->element, 0, sizeof(t_element));
	mlx->dda = (t_dda *)malloc(sizeof(t_dda));
	ft_memset(mlx->dda, 0, sizeof(t_dda));
	mlx->element->no_img = (t_img *)malloc(sizeof(t_img));
	ft_memset(mlx->element->no_img, 0, sizeof(t_img));
	mlx->element->so_img = (t_img *)malloc(sizeof(t_img));
	alloc_element(mlx);
	handling_linkage(mlx);
	return (mlx);
}
