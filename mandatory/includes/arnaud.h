#ifndef ARNAUD_H
# define ARNAUD_H

#define EPSILON 0.0001

typedef struct s_element t_element;
typedef struct s_mlx t_mlx;
typedef struct s_player t_player;
typedef struct s_img t_img;

typedef struct s_dda
{
	double	cos_angle;
	double	sin_angle;
	int		map_x;
	int		map_y;
	double	ray_x;
	double	ray_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	int		step_x;
	int		step_y;
	int		side;
}	t_dda;

void	init_texture(t_element *element, t_mlx *mlx);
int		get_texture_color(t_img *texture, int tex_x, int tex_y);
void	draw_floor_and_cieling (t_mlx *mlx);
void	draw_textured_wall(int ray_x, int ray_y, t_mlx *mlx, t_player *player, int i, int side);

#endif