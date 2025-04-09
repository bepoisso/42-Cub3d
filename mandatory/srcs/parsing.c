#include "cub3d.h"

static void cpy_no_texture(char *str, t_element *element)
{
	int fd;
	int i;

	i = 2;
	while (str[i] == ' ')
		i++;
	element->no_img->path = ft_substr(str, i, ft_strlen(str) - i - 1);
	fd = open(element->no_img->path, O_RDONLY);
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
	element->so_img->path = ft_substr(str, i, ft_strlen(str) - i - 1);
	fd = open(element->so_img->path, O_RDONLY);
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
	element->we_img->path = ft_substr(str, i, ft_strlen(str) - i - 1);
	fd = open(element->we_img->path, O_RDONLY);
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
	printf("test\n");
	while (str[i] == ' ')
		i++;
	element->ea_img->path = ft_substr(str, i, ft_strlen(str) - i - 1);
	fd = open(element->ea_img->path, O_RDONLY);
	if (fd < 0)
		ft_error("wrong EA texture\n", true, element->mlx);
	close(fd);
	element->flag_element++;
}



void init_element(char **str, t_mlx *mlx)
{
	int i;

	i = 0;
	
	while (str[i])
	{
		printf("%s\n", str[i]);
		if ((ft_strncmp(str[i], "NO", 2) == 0))
			cpy_no_texture(str[i], mlx->element);
		if ((ft_strncmp(str[i], "SO", 2) == 0))
			cpy_so_texture(str[i], mlx->element);
		if ((ft_strncmp(str[i], "WE", 2) == 0))
			cpy_we_texture(str[i], mlx->element);
		if ((ft_strncmp(str[i], "EA", 2) == 0))
			cpy_ea_texture(str[i], mlx->element);
		if ((ft_strncmp(str[i], "F", 1) == 0))
			init_color(str[i], &mlx->element->floor, mlx->element);
		if ((ft_strncmp(str[i], "C", 1) == 0))
			init_color(str[i], &mlx->element->ceiling, mlx->element);
		i++;
	}
	// if (mlx->element->flag_element != 6)
	// 	ft_error("bad type of elements\n", true, mlx);
	// printf("path NO texture = %s\n", mlx->element->no_img->path);
	// printf("path SO texture = %s\n", mlx->element->so_img->path);
	// printf("path WE texture = %s\n", mlx->element->we_img->path);
	// printf("path EA texture = %s\n", mlx->element->ea_img->path);
	set_colors(mlx->element);
}
