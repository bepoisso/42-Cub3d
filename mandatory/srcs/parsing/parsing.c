/* parsing */

#include "../includes/cub3d.h"
#include "../includes/parsing.h"

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <limits.h>
#include <bool.h>


void cpy_no_texture(char *str, t_pars *pars)
{
	int fd;
	int i;

	i = 2;
	while (str[i] == ' ')
		i++;
	pars->no_texture = ft_substr(str, i, ft_strlen(str) - i);
	fd = open(pars->no_texture, O_RDONLY);
	if (!fd)
		ft_error("wrong texture\n", TRUE);
	close(fd);
}

void cpy_so_texture(char *str, t_pars *pars)
{
	int fd;
	int i;

	i = 2;
	while (str[i] == ' ')
		i++;
	pars->so_texture = ft_substr(str, 3, ft_strlen(str) - 3);
	fd = open(pars->so_texture, O_RDONLY);
	if (!fd)
		ft_error("wrong texture\n", TRUE);
	close(fd);
}

void cpy_we_texture(char *str, t_pars *pars)
{
	int fd;
	int i;

	i = 2;
	while (str[i] == ' ')
		i++;
	pars->we_texture = ft_substr(str, 3, ft_strlen(str) - 3);
	fd = open(pars->we_texture, O_RDONLY);
	if (!fd)
		ft_error("wrong texture\n", TRUE);
	close(fd);
}

void cpy_ea_texture(char *str, t_pars *pars)
{
	int fd;
	int i;

	i = 2;
	while (str[i] == ' ')
		i++;
	pars->ea_texture = ft_substr(str, 3, ft_strlen(str) - 3);
	fd = open(pars->ea_texture, O_RDONLY);
	if (!fd)
		ft_error("wrong texture\n", TRUE);
	close(fd);
}

void check_color(t_color *color)
{
	if (color->r_color == INT_MIN || color->g_color == INT_MIN
		|| color->b_color == INT_MIN)
		ft_error("wrong color\n", TRUE)
	if (color->r_color > 255)
		color->r_color = 255
	if (color->g_color > 255)
		color->g_color = 255
	if (color->b_color > 255)
		color->b_color = 255
	if (color->r_color < 0)
		color->r_color = 0
	if (color->g_color < 0)
		color->g_color = 0
	if (color->b_color < 0)
		color->b_color = 0
}

void init_color(char *str, t_color *color)
{
	char *tmp;
	int i;
	int j;

	i = 1;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		j = i;
		while (str[i] != ',')
			i++;
		i++;
		tmp = ft_substr(str, j, i-j);
		color->r_color = ft_atoi(tmp);
		j = i;
		while (str[i] != ',')
			i++;
		i++;
		tmp = ft_substr(str, j, i-j);
		color->g_color = ft_atoi(tmp);
		j = i;
		while (str[i] != ',')
			i++;
		i++;
		tmp = ft_substr(str, j, i-j);
		color->b_color = ft_atoi(tmp);
	}
	check_color(color);
}

void check_texture(char **str, t_pars *pars)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((ft_strncmp(str[i], "NO", 2) == 0))
			cpy_no_texture(str[i], pars);
		if ((ft_strncmp(str[i], "SO", 2) == 0))
			cpy_so_texture(str[i], pars);
		if ((ft_strncmp(str[i], "WE", 2) == 0))
			cpy_we_texture(str[i], pars);
		if ((ft_strncmp(str[i], "EA", 2) == 0))
			cpy_ea_texture(str[i], pars);
		if ((ft_strncmp(str[i], "F", 1) == 0))
			init_color(str[i], pars->floor);
		if ((ft_strncmp(str[i], "C", 1) == 0))

	}
}
