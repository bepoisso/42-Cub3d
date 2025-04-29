#include "../includes/cub3d.h"

float	distance(float x, float y)
{
	return (sqrt(x * x + y * y));
}

float	fixed_dist(float raw_dist, float ray_angle, float player_angle)
{
	return (raw_dist * cos(ray_angle - player_angle));
}
