/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:30:45 by bepoisso          #+#    #+#             */
/*   Updated: 2025/04/30 12:30:46 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	check_valid_pos(t_mlx *mlx, int x, int y, int len)
{
	if (y == 0 || y == len - 1 || x == 0
		|| x == (int)ft_strlen(mlx->map->map[y]) - 1)
		ft_error("invalid map\n", true, mlx);
	if (!ft_ischarset(mlx->map->map[y + 1][x], "120"))
		ft_error("invalid map\n", true, mlx);
	if (!ft_ischarset(mlx->map->map[y - 1][x], "120"))
		ft_error("invalid map\n", true, mlx);
	if (!ft_ischarset(mlx->map->map[y][x + 1], "120"))
		ft_error("invalid map\n", true, mlx);
	if (!ft_ischarset(mlx->map->map[y][x - 1], "120"))
		ft_error("invalid map\n", true, mlx);
}

static void	check_valid_case(t_mlx *mlx, int x, int y, int len)
{
	if (y == 0 || y == len - 1 || x == 0
		|| x == (int)ft_strlen(mlx->map->map[y]) - 1)
		ft_error("invalid map\n", true, mlx);
	if (!ft_ischarset(mlx->map->map[y + 1][x], "120WSNEP"))
		ft_error("invalid map\n", true, mlx);
	if (!ft_ischarset(mlx->map->map[y - 1][x], "120WSNEP"))
		ft_error("invalid map\n", true, mlx);
	if (!ft_ischarset(mlx->map->map[y][x + 1], "120WSNEP"))
		ft_error("invalid map\n", true, mlx);
	if (!ft_ischarset(mlx->map->map[y][x - 1], "120WSNEP"))
		ft_error("invalid map\n", true, mlx);
}

static void	flood_fill(char **map, int x, int y, t_mlx *mlx)
{
	int	len;

	len = 0;
	while (map[len])
		len++;
	if (y < 0 || y >= len || x < 0)
		return ;
	if (!map[y])
		return ;
	if (x >= (int)ft_strlen(map[y]))
		return ;
	if (map[y][x] == 'F')
		return ;
	if (map[y][x] == '0')
		check_valid_case(mlx, x, y, len);
	map[y][x] = 'F';
	flood_fill(map, x + 1, y, mlx);
	flood_fill(map, x - 1, y, mlx);
	flood_fill(map, x, y + 1, mlx);
	flood_fill(map, x, y - 1, mlx);
}

void	check_char_in_map(char **map, t_mlx *mlx)
{
	int	x;
	int	y;
	int	len;

	len = 0;
	while (map[len])
		len++;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!ft_ischarset(map[y][x], " 120NEWSP\n"))
				ft_error("bad char in map\n", true, mlx);
			if (ft_ischarset(map[y][x], "NEWSP"))
				check_valid_pos(mlx, x, y, len);
			x++;
		}
		y++;
	}
}

void	is_valid_map(char **map, t_mlx *mlx)
{
	mlx->map->temp_map = ft_copy_strs(map);
	check_char_in_map(mlx->map->temp_map, mlx);
	check_double_player(mlx->map);
	flood_fill(mlx->map->temp_map, 0, 0, mlx);
}
