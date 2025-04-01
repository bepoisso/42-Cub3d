#include "cub3d.h"

void cpy_no_texture(char *str, t_element *element)
{
	int fd;
	int i;

	i = 2;
	while (str[i] == ' ')
		i++;
	element->no_texture = ft_substr(str, i, ft_strlen(str) - i - 1);
	fd = open(element->no_texture, O_RDONLY);
	if (fd < 0)
		ft_error("wrong NO texture\n", true);
	close(fd);
}

void cpy_so_texture(char *str, t_element *element)
{
	int fd;
	int i;

	i = 2;
	while (str[i] == ' ')
		i++;
	element->so_texture = ft_substr(str, i, ft_strlen(str) - i - 1);
	fd = open(element->so_texture, O_RDONLY);
	if (fd < 0)
		ft_error("wrong SO texture\n", true);
	close(fd);
}

void cpy_we_texture(char *str, t_element *element)
{
	int fd;
	int i;

	i = 2;
	while (str[i] == ' ')
		i++;
	element->we_texture = ft_substr(str, i, ft_strlen(str) - i - 1);
	fd = open(element->we_texture, O_RDONLY);
	if (fd < 0)
		ft_error("wrong WE texture\n", true);
	close(fd);
}

void cpy_ea_texture(char *str, t_element *element)
{
	int fd;
	int i;

	i = 2;
	while (str[i] == ' ')
		i++;
	element->ea_texture = ft_substr(str, i, ft_strlen(str) - i - 1);
	fd = open(element->ea_texture, O_RDONLY);
	if (fd < 0)
		ft_error("wrong EA texture\n", true);
	close(fd);
}

void check_color(t_color *color)
{
	if (color->r_color == INT_MIN || color->g_color == INT_MIN
		|| color->b_color == INT_MIN)
		ft_error("wrong color\n", true);
	if (color->r_color > 255)
		color->r_color = 255;
	if (color->g_color > 255)
		color->g_color = 255;
	if (color->b_color > 255)
		color->b_color = 255;
	if (color->r_color < 0)
		color->r_color = 0;
	if (color->g_color < 0)
		color->g_color = 0;
	if (color->b_color < 0)
		color->b_color = 0;
}

void init_color(char *str, t_color *color)
{
	char **colors;
	int i;

	i = 1;
	while (str[i] == ' ')
		i++;
	colors = ft_split(str + i, ',');
	color->r_color = ft_atoi(colors[0]);
	color->g_color = ft_atoi(colors[1]);
	color->b_color = ft_atoi(colors[2]);
	i = 0;
	while (colors[i])
		free(colors[i++]);
	free(colors);
	check_color(color);
}

void init_element(char **str, t_element *element)
{
	int i;

	i = 0;
	element = (t_element *)malloc(sizeof(t_element));
	element->ceiling = (t_color *)malloc(sizeof(t_color));
	element->floor = (t_color *)malloc(sizeof(t_color));
	ft_bzero(element->floor, sizeof(t_color));
	ft_bzero(element->ceiling, sizeof(t_color));
	while (str[i])
	{
		if ((ft_strncmp(str[i], "NO", 2) == 0))
			cpy_no_texture(str[i], element);
		if ((ft_strncmp(str[i], "SO", 2) == 0))
			cpy_so_texture(str[i], element);
		if ((ft_strncmp(str[i], "WE", 2) == 0))
			cpy_we_texture(str[i], element);
		if ((ft_strncmp(str[i], "EA", 2) == 0))
			cpy_ea_texture(str[i], element);
		if ((ft_strncmp(str[i], "F", 1) == 0))
			init_color(str[i], element->floor);
		if ((ft_strncmp(str[i], "C", 1) == 0))
			init_color(str[i], element->ceiling);
		i++;
	}
	ft_printf("texture NO = %s\n", element->no_texture);
	ft_printf("texture SO = %s\n", element->so_texture);
	ft_printf("texture WE = %s\n", element->we_texture);
	ft_printf("texture EA = %s\n", element->ea_texture);
	ft_printf("floor : %d,%d,%d\n", element->floor->r_color, element->floor->g_color, element->floor->b_color);
	ft_printf("cieling : %d,%d,%d\n", element->ceiling->r_color, element->ceiling->g_color, element->ceiling->b_color);
	
}
