#ifndef UTILES_H
# define UTILES_H

typedef struct	s_mlx	t_mlx;

void	ft_error(char *s, bool free, t_mlx *mlx);
int		ft_ischarset(char c, char *charset);

#endif