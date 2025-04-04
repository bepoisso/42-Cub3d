#ifndef UTILES_H
# define UTILES_H

typedef struct	s_mlx	t_mlx;

typedef struct s_draw
{
	int	x_pos;
	int	y_pos;
	int	size_x;
	int	size_y;
	int	radius;
	int	thickness;
	int	color;
}	t_draw;


void	ft_error(char *s, bool free, t_mlx *mlx);
int		ft_ischarset(char c, char *charset);
int		ft_strslen(char **s);
void	mlx_draw_circle(t_mlx *mlx, t_draw *circle);
void	mlx_draw_rectangle(t_mlx *data, t_draw *draw);
void	mlx_draw_filled_circle(t_mlx *mlx, t_draw *circle);
float	pixtof(int pixel);
int		ftopix(float pos);

#endif