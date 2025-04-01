#include "cub3d.h"

// Count the number of line in a files
static int	files_count_line(char *file_name)
{
	char	buf[1];
	int		count;
	char	fd;
	char	readed;

	count = 0;
	readed = 1;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (readed != 0)
	{
		readed = read(fd, buf, 1);
		if (*buf == '\n')
			count++;
	}
	close(fd);
	return (count);
}

static char **file_to_char(int fd, int size)
{
	char	**res;
	char	*line;
	int		i;


	i = 0;
	res = (char **)malloc(sizeof(char *) * size);
	line = get_next_line(fd);
	while (line)
	{
		res[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	res[i] = NULL;
	return (res);
}

t_map *get_file(char *file, t_mlx *mlx)
{
	t_map	*map;
	int		size;
	int		fd;

	if (!file || file[0] == '\0')
		ft_error("invalid map\n", true, mlx);
	map = (t_map *)malloc(sizeof(t_map));
	ft_memset(map, 0, sizeof(t_map));
	map->mlx = mlx;
	size = files_count_line(file) + 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("permission denid or file dosen't exist\n", true, mlx);
	if (size <= 0)
		ft_error("map is empty\n", true, mlx);
	map->map = file_to_char(fd, size);
	close (fd);
	return (map);
}