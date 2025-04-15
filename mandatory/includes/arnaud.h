#ifndef ARNAUD_H
# define ARNAUD_H

typedef struct s_element t_element;
typedef struct s_mlx t_mlx;
typedef struct s_player t_player;

typedef struct s_dda
{
	float	cos_angle;
	float	sin_angle;
	int		map_x;
	int		map_y;

	float	ray_x;
	float	ray_y;

	float	delta_x;
	float	delta_y;

	float	side_x;
	float	side_y;

	int		step_x;
	int		step_y;
	int		side;
}	t_dda;

void init_texture(t_element *element, t_mlx *mlx);
void	draw_textured_wall(int ray_x, int ray_y, t_mlx *mlx, t_player *player, int i);

#endif