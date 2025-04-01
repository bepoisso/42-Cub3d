#include "cub3d.h"

static void cpy_no_texture(char *str, t_element *element)
{
	int fd;
	int i;

	i = 2;
	while (str[i] == ' ')
		i++;
	element->no_texture = ft_substr(str, i, ft_strlen(str) - i - 1);
	fd = open(element->no_texture, O_RDONLY);
	if (fd < 0)
		ft_error("wrong NO texture\n", true, element->mlx);
	close(fd);
	element->flag_element++;
}

static void cpy_so_texture(char *str, t_element *element)
{
	int fd;
	int i;

	i = 2;
	while (str[i] == ' ')
		i++;
	element->so_texture = ft_substr(str, i, ft_strlen(str) - i - 1);
	fd = open(element->so_texture, O_RDONLY);
	if (fd < 0)
		ft_error("wrong SO texture\n", true, element->mlx);
	close(fd);
	element->flag_element++;
}

static void cpy_we_texture(char *str, t_element *element)
{
	int fd;
	int i;

	i = 2;
	while (str[i] == ' ')
		i++;
	element->we_texture = ft_substr(str, i, ft_strlen(str) - i - 1);
	fd = open(element->we_texture, O_RDONLY);
	if (fd < 0)
		ft_error("wrong WE texture\n", true, element->mlx);
	close(fd);
	element->flag_element++;
}

static void cpy_ea_texture(char *str, t_element *element)
{
	int fd;
	int i;

	i = 2;
	while (str[i] == ' ')
		i++;
	element->ea_texture = ft_substr(str, i, ft_strlen(str) - i - 1);
	fd = open(element->ea_texture, O_RDONLY);
	if (fd < 0)
		ft_error("wrong EA texture\n", true, element->mlx);
	close(fd);
	element->flag_element++;
}

void	check_color(t_color *color, t_element *element)
{
	if (color->r_color == INT_MIN || color->g_color == INT_MIN
		|| color->b_color == INT_MIN)
		ft_error("wrong color\n", true, element->mlx);
	if (color->r_color > 255)
	{		
		ft_error("bad nb of color\n", false, element->mlx);
		color->r_color = 255;
	}
	if (color->g_color > 255)
	{		
		ft_error("bad nb of color\n", false, element->mlx);
		color->g_color = 255;
	}
	if (color->b_color > 255)
	{		
		ft_error("bad nb of color\n", false, element->mlx);
		color->b_color = 255;
	}
	if (color->r_color < 0)
	{		
		ft_error("bad nb of color\n", false, element->mlx);
		color->r_color = 0;
	}
	if (color->g_color < 0)
	{		
		ft_error("bad nb of color\n", false, element->mlx);
		color->g_color = 0;
	}
	if (color->b_color < 0)
	{		
		ft_error("bad nb of color\n", false, element->mlx);
		color->b_color = 0;
	}
}

void init_color(char *str, t_color *color, t_element *element)
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
	check_color(color, element);
	element->flag_element++;
}



void init_element(char **str, t_mlx *mlx)
{
	int i;

	i = 0;
	mlx->element = (t_element *)malloc(sizeof(t_element));
	mlx->element->flag_element = 0;
	mlx->element->ceiling = (t_color *)malloc(sizeof(t_color));
	mlx->element->floor = (t_color *)malloc(sizeof(t_color));
	ft_bzero(mlx->element->floor, sizeof(t_color));
	ft_bzero(mlx->element->ceiling, sizeof(t_color));
	while (str[i])
	{
		if ((ft_strncmp(str[i], "NO", 2) == 0))
			cpy_no_texture(str[i], mlx->element);
		if ((ft_strncmp(str[i], "SO", 2) == 0))
			cpy_so_texture(str[i], mlx->element);
		if ((ft_strncmp(str[i], "WE", 2) == 0))
			cpy_we_texture(str[i], mlx->element);
		if ((ft_strncmp(str[i], "EA", 2) == 0))
			cpy_ea_texture(str[i], mlx->element);
		if ((ft_strncmp(str[i], "F", 1) == 0))
			init_color(str[i], mlx->element->floor, mlx->element);
		if ((ft_strncmp(str[i], "C", 1) == 0))
			init_color(str[i], mlx->element->ceiling, mlx->element);
		i++;
	}
	if (mlx->element->flag_element != 6)
		ft_error("bad type of elements\n", true, mlx);
	//init_texture(mlx->element, mlx);
	ft_printf("texture NO = %s\n", mlx->element->no_texture);
	ft_printf("texture SO = %s\n", mlx->element->so_texture);
	ft_printf("texture WE = %s\n", mlx->element->we_texture);
	ft_printf("texture EA = %s\n", mlx->element->ea_texture);
	ft_printf("floor : %d,%d,%d\n", mlx->element->floor->r_color, mlx->element->floor->g_color, mlx->element->floor->b_color);
	ft_printf("cieling : %d,%d,%d\n", mlx->element->ceiling->r_color, mlx->element->ceiling->g_color, mlx->element->ceiling->b_color);
	
}
