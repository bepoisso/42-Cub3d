#ifndef CUB3D_H
# define CUB3D_H

# define DEBUG 1

# define WIDTH 1280
# define HEIGHT 720
# define TEXTURE 64
# define ELEM "01SONE \n"
# define SPEED 3
# define A_SPEED 0.03

# define PI 3.14159265359

# define BLUE "\001\033[0;34m\002"
# define RED "\001\033[0;31m\002"
# define GREEN "\001\033[0;32m\002"
# define YELLOW "\001\033[0;33m\002"
# define CYAN "\001\033[0;36m\002"
# define VIOLET "\001\033[0;35m\002"
# define RESET "\001\033[0m\002"

# include "../minilibx-linux/mlx.h"
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <math.h>
# include <errno.h>
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_player
{
	float	x;
	float	y;
	float	angle;

	bool	key_up;
	bool	key_down;
	bool	key_left;
	bool	key_right;

	bool	left_rotate;
	bool	right_rotate;
}	t_player;

typedef struct s_mlx
{
	void		*link;
	void		*screen;
	void		*img;

	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	t_player	player;

	char		**map;
}	t_mlx;


/* PLAYER */
void	init_player(t_player *player);
int		key_press(int keysym, t_player *player);
int		key_release(int keysym, t_player *player);
void	move_player(t_player *player);

#endif