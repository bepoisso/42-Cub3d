
#ifndef PARSING_H
# define PARSING_H

typedef struct s_color
{
	int r_color;
	int g_color;
	int b_color;
}	t_color;


typedef struct s_element
{
	char *no_texture;
	char *so_texture;
	char *we_texture;
	char *ea_texture;
	t_color	*floor;
	t_color	*ceiling;

}	t_element;

typedef struct	s_mlx
{
	void		*link;
	void		*screen;
	t_map		*map;
	t_element	*element;
}	t_mlx;

t_map	*get_file(char *file, t_mlx *mlx);
void	init_element(char **str, t_mlx *mlx);

#endif