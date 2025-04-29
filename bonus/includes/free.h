#ifndef FREE_H
# define FREE_H

# include "cub3d.h"

typedef struct s_img	t_img;
typedef struct s_map	t_map;
typedef struct s_mlx	t_mlx;

void	free_img(t_img *img, t_mlx *mlx);
void	free_all(t_mlx *mlx);



// A METTRE DANS LE POINT H PRINCIPAL
void	map_max(t_map *map);

#endif
