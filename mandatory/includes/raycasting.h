#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"

typedef struct s_ray
{
	float	x;
	float	y;
	float	x1;
	float	y1;
	float	x2;
	float	y2;
	float	angle;
	float	slope;
}	t_ray;

void	print_wall(t_mlx *mlx, int unit);

#endif