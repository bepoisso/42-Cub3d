#include "cub3d.h"

int main(int argc, char *argv[])
{
	char	**map;
	int		i;

	if (argc != 2)
		ft_error("invalid argument\n", true);
	map = get_file(argv[1]);
	i = 0;
	while (map[i])
	{
		ft_printf("map[%d] = %s", i, map[i]);
		i++;
	}
	
	return (0);
}
