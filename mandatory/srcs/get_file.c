#include "cub3d.h"

// Count the number of line in a files
static int	files_count_line(char *file_name, t_mlx *mlx)
{
	char	buf[1];
	int		count;
	char	fd;
	char	readed;

	count = 0;
	readed = 1;
	fd = open(file_name, O_RDWR);
	if (errno == EISDIR)
		ft_error("the specified path is a directory,\
not a file.\n\n", true, mlx);
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

static char	**file_to_char(int fd, int size)
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

char	**get_file(char *file, t_mlx *mlx)
{
	int		size;
	int		fd;
	char	**res;

	if (!file || file[0] == '\0')
		ft_error("invalid map\n", true, mlx);
	size = files_count_line(file, mlx) + 1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("permission denid or file dosen't exist\n", true, mlx);
	if (size <= 0)
		ft_error("map is empty\n", true, mlx);
	res = file_to_char(fd, size);
	close (fd);
	return (res);
}
