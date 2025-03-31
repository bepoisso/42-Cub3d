#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdbool.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
# include "../libft/includes/libft.h"
# include "map.h"
# include "parsing.h"
# include "utiles.h"
# include "map.h"

/* Color */
# define BLUE "\001\033[0;34m\002"
# define RED "\001\033[0;31m\002"
# define GREEN "\001\033[0;32m\002"
# define YELLOW "\001\033[0;33m\002"
# define CYAN "\001\033[0;36m\002"
# define VIOLET "\001\033[0;35m\002"
# define RESET "\001\033[0m\002"

typedef struct	s_mlx
{
	void		*link;
	void		*screen;
	t_map		*map;
	t_element	*element;
}	t_mlx;

#endif