/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:31:41 by bepoisso          #+#    #+#             */
/*   Updated: 2025/04/30 12:33:06 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_error(char *s, bool free, t_mlx *mlx)
{
	(void)mlx;
	if (free)
	{
		ft_putstr_fd(RED"", 2);
		ft_putstr_fd("Error\n", 2);
	}
	else
	{
		ft_putstr_fd(YELLOW"", 2);
		ft_putstr_fd("Warning\n", 2);
	}
	ft_putstr_fd(s, 2);
	ft_putstr_fd(""RESET, 2);
	if (free == true)
	{
		free_all(mlx);
		exit(1);
	}
}

void	print_debug(t_mlx *mlx)
{
	if (mlx->player->debug)
	{
		printf("path NO texture = %s\n", mlx->element->no_img->path);
		printf("path SO texture = %s\n", mlx->element->so_img->path);
		printf("path WE texture = %s\n", mlx->element->we_img->path);
		printf("path EA texture = %s\n", mlx->element->ea_img->path);
	}
}

/* Pardon maisj'ai plus de place */
void	init_texture_default(t_mlx *mlx)
{
	mlx->element->no_img->path = ft_strdup(" ");
	mlx->element->so_img->path = ft_strdup(" ");
	mlx->element->we_img->path = ft_strdup(" ");
	mlx->element->ea_img->path = ft_strdup(" ");
}
