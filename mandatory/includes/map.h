#ifndef MAP_H
# define MAP_H

# include "cub3d.h"

typedef struct	s_map
{
	int		x;
	int		y;
	char	**map;
}	t_map;

t_map	*init_map(char **file);
char	**get_map(char **file);

#endif