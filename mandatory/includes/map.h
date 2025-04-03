#ifndef MAP_H
# define MAP_H

# include "cub3d.h"

typedef struct	s_mlx	t_mlx;
typedef struct	s_player	t_player;

typedef struct	s_map
{
	int		x;
	int		y;
	int		x_max;
	int		y_max;
	char	**map;
	t_mlx	*mlx;
}	t_map;

t_map		*init_map(char **file, t_mlx *mlx);
t_player	*init_player(t_mlx *mlx);
char		**get_map(char **file);
void		check_map(t_mlx *mlx);
void		get_player_pos(t_mlx *mlx);

#endif