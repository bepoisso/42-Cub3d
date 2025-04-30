/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:31:43 by bepoisso          #+#    #+#             */
/*   Updated: 2025/04/30 12:33:13 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	close_cross(t_mlx *mlx)
{
	free_all(mlx);
	exit(0);
}

void	put_pixel(int x, int y, int color, t_mlx *mlx)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * mlx->size_line + x * mlx->bpp / 8;
	mlx->data[index] = color & 0xFF;
	mlx->data[index + 1] = (color >> 8) & 0xFF;
	mlx->data[index + 2] = (color >> 16) & 0xFF;
}

void	clear_image(t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			put_pixel(x, y, 0, mlx);
			x++;
		}
		y++;
	}
}

char	**ft_copy_strs(char **strs)
{
	int		i;
	int		len;
	char	**cpy;

	len = 0;
	while (strs[len])
		len++;
	cpy = (char **)malloc(sizeof(char *) * (len + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (strs[i])
	{
		cpy[i] = ft_strdup(strs[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

bool	is_in_circle(int x, int y, t_draw circle)
{
	int	dx;
	int	dy;

	dx = x - circle.x;
	dy = y - circle.y;
	return (dx * dx + dy * dy <= circle.radius * circle.radius);
}
