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

float	pixtof(int pixel)
{
	return ((float)pixel / TEXTURE);
}

int	ftopix(float pos)
{
	int abs = 0;
	float only = 0;
	float pix_in = 0;
	int	pixel = 0;

	abs = (int)floorf(pos);
	only = pos - (int)floorf(pos);
	pix_in = only * TEXTURE;
	pixel = (abs * TEXTURE) + pix_in;
	return (pixel);
}

float	degtorad(float	degree)
{
	return (degree * PI / 180);
}

float	radtodeg(float radian)
{
	return (radian * 180 / PI);
}