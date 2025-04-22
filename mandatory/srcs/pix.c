#include "cub3d.h"

float	pixtof(int pixel)
{
	return ((float)pixel / TEXTURE);
}

int	ftopix(float pos)
{
	int		abs;
	float	only;
	float	pix_in;
	int		pixel;

	abs = (int)floorf(pos);
	only = pos - (int)floorf(pos);
	pix_in = only * TEXTURE;
	pixel = (abs * TEXTURE) + pix_in;
	return (pixel);
}
