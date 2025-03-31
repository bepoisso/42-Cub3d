#include "cub3d.h"

int main(int argc, char *argv[])
{
	t_mlx	*mlx;
	char	**map;
	int		i;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	ft_memset(mlx, 0, sizeof(t_mlx));
	if (argc != 2)
		ft_error("invalid argument\n", true);
	map = get_file(argv[1]);
	i = 0;
	return (0);
}
