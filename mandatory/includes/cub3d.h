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
# include "arnaud.h"

typedef struct s_color
{
	int	r_color;
	int	g_color;
	int	b_color;
}	t_color;

typedef struct	s_map
{
	int				x;
	int				y;
	int				x_max;
	int				y_max;
	char			**map;
	struct s_mlx	*mlx;
}	t_map;

typedef struct s_img
{
	void	*img;
	char	*path;
	char	*add;
	int		width;
	int		height;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_element
{
	int				flag_element;
	int				floor_color;
	int				cieling_color;
	t_img			*no_img;
	t_img			*so_img;
	t_img			*we_img;
	t_img			*ea_img;
	t_color			floor;
	t_color			ceiling;
	struct s_mlx	*mlx;
}	t_element;

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
	t_map		*map;
	char		*data;
	int			bpp;
	int			size_line;
	int			endian;
	t_player	*player;
	t_element	*element;

}	t_mlx;


/* PARSING and INIT */
void	is_valid_map(char **map, t_mlx *mlx);
void	init_element(char **str, t_mlx *mlx);
char	**get_map(char **file);
t_map	*init_map(char **file, t_map *map, t_mlx *mlx);
char	**get_file(char *file, t_mlx *mlx);
void	init_color(char *str, t_color *color, t_element *element);
void	set_colors(t_element *element);



/* UTILS */
void	ft_error(char *s, bool free, t_mlx *mlx);
int		ft_ischarset(char c, char *charset);
int		ft_strslen(char **s);


/* PLAYER */
t_player	*init_player(t_player *player);
int			key_press(int keysym, t_player *player);
int			key_release(int keysym, t_player *player);
void		move_player(t_player *player);

#endif
