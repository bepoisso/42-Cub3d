#include "../includes/cub3d.h"

// Count the number of line in a files
int	files_count_line(char *file_name)
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

void	ft_error(char *s, bool free)
{
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

char **file_to_char(int fd, int size)
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
	return (res);
}

char	**get_file(char *file)
{
	char	**res;
	int		size;
	int		fd;

	if (!file || file[0] == '\0')
		ft_error("invalid map\n", true);
	size = files_count_line(file);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("permission denid or file dosen't exist\n", true);
	if (size <= 0)
		ft_error("map is empty\n", true);
	res = file_to_char(fd, size);
	close (fd);
	return (res);
}

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
