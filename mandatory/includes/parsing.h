
#ifndef PARSING_H
# define PARSING_H

# define HEIGHT 128
# define WIDTH 128

typedef struct	s_mlx		t_mlx;
typedef struct	s_player	t_player;

typedef struct s_color
{
	int	r_color;
	int	g_color;
	int	b_color;
}	t_color;

typedef struct s_element
{
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	void	*no_img;
	void	*so_img;
	void	*we_img;
	void	*ea_img;
	int		flag_element;
	int		floor_color;
	int		cieling_color;
	t_color	*floor;
	t_color	*ceiling;
	t_mlx	*mlx;
}	t_element;


typedef struct	s_mlx
{
	void		*link;
	void		*screen;
	t_map		*map;
	t_element	*element;
	t_player	*player;
	int	p_unite;
}	t_mlx;

char	**get_file(char *file, t_mlx *mlx);
void	init_element(char **str, t_mlx *mlx);
void	flood_fill(char **map, int x, int y, t_mlx *mlx);
void	check_map_ff(char **map, t_mlx *mlx);

void	set_colors(t_element *element);
void	init_color(char *str, t_color *color, t_element *element);
void	draw_map(t_mlx *mlx);
void	ft_print_map(char **map);

#endif