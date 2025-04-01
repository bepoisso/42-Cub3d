
#ifndef PARSING_H
# define PARSING_H

typedef struct	s_mlx	t_mlx;

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
}	t_mlx;

t_map	*get_file(char *file);
void	init_element(char **str, t_mlx *mlx);

#endif