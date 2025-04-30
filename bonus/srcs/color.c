/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:30:52 by bepoisso          #+#    #+#             */
/*   Updated: 2025/04/30 12:32:03 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_value_of_color(int *color, t_element *element)
{
	if (*color > 255)
	{
		ft_error("bad nb of color\n", false, element->mlx);
		*color = 255;
	}
	if (*color < 0)
	{
		ft_error("bad nb of color\n", false, element->mlx);
		*color = 0;
	}
}

static void	check_color(t_color *color, t_element *element)
{
	if (color->r_color == INT_MIN || color->g_color == INT_MIN
		|| color->b_color == INT_MIN)
		ft_error("wrong color\n", true, element->mlx);
	check_value_of_color(&color->r_color, element);
	check_value_of_color(&color->g_color, element);
	check_value_of_color(&color->b_color, element);
}

static int	create_rgb(int r, int g, int b)
{
	return ((r << 16) | (g << 8) | b);
}

void	init_color(char *str, t_color *color, t_element *element)
{
	char	**colors;
	int		i;

	i = 1;
	while (str[i] == ' ')
		i++;
	colors = ft_split(str + i, ',');
	color->r_color = ft_atoi(colors[0]);
	color->g_color = ft_atoi(colors[1]);
	color->b_color = ft_atoi(colors[2]);
	i = 0;
	while (colors[i])
		free(colors[i++]);
	free(colors);
	check_color(color, element);
	element->flag_element++;
}

void	set_colors(t_element *element)
{
	element->floor_color = create_rgb(element->floor.r_color,
			element->floor.g_color, element->floor.b_color);
	element->cieling_color = create_rgb(element->ceiling.r_color,
			element->ceiling.g_color, element->ceiling.b_color);
}
