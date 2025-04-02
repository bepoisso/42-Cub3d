#include "cub3d.h"

int	ft_ischarset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_strslen(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}