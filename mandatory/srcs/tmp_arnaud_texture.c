#include "cub3d.h"



static float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}


static float	fixed_dist(float x1, float y1, float x2, float y2, t_mlx *mlx)
{
	float delta_x;
	float delta_y;
	float angle;
	float fix_dist;

	delta_x = x2 - x1;
	delta_y = y2 - y1;
	angle = atan2(delta_y, delta_x) - mlx->player->angle;
	fix_dist = distance(delta_x, delta_y) * cos(angle);
	return (fix_dist);
}

void	final_draw(t_mlx *mlx, int y, int end, t_img *texture, int start_y, int height, int i, int tex_x)
{
	float	ratio;
	float	blend;
	int tex_y1;
	int tex_y2;
	int color;
	int color1;
	int color2;
	t_color	rgb;
	

	while (y < end)
	{
		ratio = (float)(y - start_y) * texture->height / height;
		tex_y1 = (int)ratio;
		tex_y2 = tex_y1 + 1;
		if (tex_y2 >= texture->height)
			tex_y2 = texture->height - 1;
		blend = ratio -tex_y1;

		color1 = get_texture_color(texture, tex_x, tex_y1);
		color2 = get_texture_color(texture, tex_x, tex_y2);
		rgb.r_color = ((1.0 - blend) * ((color1 >> 16) & 0xFF) + blend * ((color2 >> 16) & 0xFF));
		rgb.g_color = ((1.0 - blend) * ((color1 >> 8) & 0xFF) + blend * ((color2 >> 8) & 0xFF));
		rgb.b_color = ((1.0 - blend) * (color1 & 0xFF) + blend * (color2 & 0xFF));
		color = (rgb.r_color << 16) | (rgb.g_color << 8) | rgb.b_color;
		put_pixel(i, y, color, mlx);
	}
}

void	draw_textured_wall(int ray_x, int ray_y, t_mlx *mlx, t_player *player, int i, int side)
{
	float	dist;
	float	height;
	int		start_y;
	int		end;
	float	wall_x;
	int		y;
	int		color;
	int		tex_y;
	int		tex_x;
	t_img	*texture;

	dist = fixed_dist(player->x, player->y, ray_x, ray_y, mlx);
	height = (TEXTURE / dist) * (WIDTH / 2);
	start_y = (HEIGHT - height) / 2;
	end = start_y + height;
	if (side == 1)
	{
		if (ray_y < player->y)
			texture = mlx->element->no_img;
		else
			texture = mlx->element->so_img;
		wall_x = ray_x;
	}
	else
	{
		if (ray_x < player->x)
			texture = mlx->element->we_img;
		else
			texture = mlx->element->ea_img;
		wall_x = ray_y;
	}
	wall_x = fmod(wall_x, TEXTURE);
	tex_x = (int)(wall_x / TEXTURE * texture->width);
	if (tex_x < 0) tex_x = 0;
	if (tex_x >= texture->width) tex_x = texture->width - 1;	
	y = start_y;
	//final_draw(mlx, y, end, texture, start_y, height, i, tex_x);
	while (y < end)
	{
		if (y >= 0 && y < HEIGHT)
		{
			tex_y = (int)((y - start_y) * texture->height / height);
			color = get_texture_color(texture, tex_x, tex_y);
			put_pixel(i, y, color, mlx);
		}
		y++;
	}
}

