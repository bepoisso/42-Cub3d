/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_utiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:31:46 by bepoisso          #+#    #+#             */
/*   Updated: 2025/04/30 12:33:16 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_ischarset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strslen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

float	degtorad(float degree)
{
	return (degree * PI / 180);
}

float	radtodeg(float radian)
{
	return (radian * 180 / PI);
}

void	map_max(t_map *map)
{
	map->y_max = 0;
	while (map->map[map->y_max])
	{
		map->x_max = 0;
		while (map->map[map->y_max][map->x_max])
		{
			map->x_max++;
		}
		map->y_max++;
	}
	map->x_max = ft_strlen(map->map[0]);
}
