#include "cub3d.h"

void	ft_error(char *s, bool free, t_mlx *mlx)
{
	(void)mlx;
	ft_putstr_fd(RED"", 2);
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(s, 2);
	ft_putstr_fd(""RESET, 2);
	if (free == true)
	{
		/* free function */
		exit(1);
	}
}