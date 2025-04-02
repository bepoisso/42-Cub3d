#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <math.h>
# include <errno.h>
# include <X11/keysym.h>
# include <X11/X.h>

# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include "utiles.h"
# include "map.h"
# include "parsing.h"
# include "raycasting.h"

/* Color */
# define BLUE "\001\033[0;34m\002"
# define RED "\001\033[0;31m\002"
# define GREEN "\001\033[0;32m\002"
# define YELLOW "\001\033[0;33m\002"
# define CYAN "\001\033[0;36m\002"
# define VIOLET "\001\033[0;35m\002"
# define RESET "\001\033[0m\002"

# define	WIN_WIDTH 1280
# define	WIN_HEIGHT 720
# define	ELEM "01SONE \n"
# define	TEXTURE 128
# define	W_UNIT TEXTURE
# define	P_UNIT W_UNIT / 2;
# define	FOV 60
# define	D_SCREEN 1


#endif