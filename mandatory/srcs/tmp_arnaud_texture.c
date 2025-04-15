#include "cub3d.h"

void	put_pixel(int x, int y, int color, t_mlx *mlx)
{
	int	index;
	
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * mlx->size_line + x * mlx->bpp / 8;
	mlx->data[index] = color & 0xFF;
	mlx->data[index + 1] = (color >> 8) & 0xFF; 
	mlx->data[index + 2] = (color >> 16) & 0xFF;
}


static float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}


static bool is_no_or_so(float ray_x, float ray_y, t_mlx *mlx)
{
	int map_x;
	int map_y;
	float	x_tile;
	float	y_tile;

	map_x = (int)(ray_x / TEXTURE);
	map_y = (int)(ray_y / TEXTURE);
	x_tile = ray_x - (map_x * TEXTURE);
	y_tile = ray_y - (map_y * TEXTURE);
	if (x_tile < 0.001 || x_tile > TEXTURE - 0.001)
		return (false);
	return (true);
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

void	draw_textured_wall(int ray_x, int ray_y, t_mlx *mlx, t_player *player, int i)
{
	float	dist;
	float	height;
	int		start_y;
	int		end;
	bool	is_ns;
	t_img	*texture;
	float	wall_x;
	int		y;
	int		color;
	int		tex_y;
	int		tex_x;

	dist = fixed_dist(player->x, player->y, ray_x, ray_y, mlx);
	height = (TEXTURE / dist) * (WIDTH / 2);
	start_y = (HEIGHT - height) / 2;
	end = start_y + height;
	is_ns = is_no_or_so(ray_x, ray_y, mlx);
  	if (is_ns) 
	{
        if (ray_y < player->y)
            texture = mlx->element->no_img;
        else
            texture = mlx->element->so_img;
    } 
	else 
	{
        if (ray_x < player->x)
            texture = mlx->element->we_img;
        else
            texture = mlx->element->ea_img;
    }
	if (is_ns)
		wall_x = fmod(ray_x, TEXTURE);
	else
		wall_x = fmod(ray_y, TEXTURE);

	tex_x = (int)(wall_x / TEXTURE * texture->width);
	y = start_y;
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


static void load_texture(t_img *img, void *mlx, char *path)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &img->width, &img->height);
	if (!img->img)
		ft_error("failed to load texture\n", true, mlx);
	img->add = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->endian);
	if (!img->add)
		ft_error("failed to load pixel adress\n", true, mlx);

}

void init_texture(t_element *element, t_mlx *mlx)
{
	load_texture(element->no_img, mlx->link, element->no_img->path);
	load_texture(element->so_img, mlx->link, element->so_img->path);
	load_texture(element->we_img, mlx->link, element->we_img->path);
	load_texture(element->ea_img, mlx->link, element->ea_img->path);
	if (!mlx->element->we_img)
    	printf("Error: WE texture not loaded!\n");
}

