#ifndef ARNAUD_H
# define ARNAUD_H

typedef struct s_element t_element;
typedef struct s_mlx t_mlx;
typedef struct s_player t_player;

void init_texture(t_element *element, t_mlx *mlx);
void	draw_textured_wall(int ray_x, int ray_y, t_mlx *mlx, t_player *player, int i);

#endif