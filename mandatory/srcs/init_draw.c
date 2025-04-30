/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:31:17 by bepoisso          #+#    #+#             */
/*   Updated: 2025/04/30 12:31:18 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_draw	init_sqrt_minimap(void)
{
	t_draw	sqrt;

	sqrt.size = TEXTURE / ZOOM_MM;
	sqrt.color = 0x808080;
	return (sqrt);
}

t_draw	init_circle_minimap(void)
{
	t_draw	circle;

	circle.x = WIDTH / RATIO_MINIMAP;
	circle.y = WIDTH / RATIO_MINIMAP;
	circle.radius = circle.x * 0.66;
	circle.color = 0xFFFFFF;
	return (circle);
}
