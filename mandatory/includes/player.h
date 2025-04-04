#ifndef PLAYER_H
# define PLAYER_H

typedef struct	s_player
{
	float	x;
	float	y;
	int		angle;
	t_draw	*circle;
	t_mlx	*mlx;
}	t_player;

void	print_player(t_mlx *mlx, bool clear);
void	move_player_lr(t_player *player, bool angle);
void	move_player_fb(t_player *player, bool angle);

#endif