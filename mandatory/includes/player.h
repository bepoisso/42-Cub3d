#ifndef PLAYER_H
# define PLAYER_H

typedef struct	s_player
{
	float	x;
	float	y;
	int	angle;
	t_draw	*circle;
}	t_player;

void	print_player(t_mlx *mlx, bool clear);

#endif