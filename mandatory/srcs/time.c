/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:31:39 by bepoisso          #+#    #+#             */
/*   Updated: 2025/04/30 12:31:40 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

long	time_in_ms(struct timeval *time)
{
	return (time->tv_sec * 1000 + time->tv_usec / 1000);
}

void	get_time(t_mlx *mlx)
{
	struct timeval	current_time;
	long			time_pass;
	static int		time = 0;

	gettimeofday(&current_time, NULL);
	time_pass = time_in_ms(&current_time) - time_in_ms(&mlx->last_time);
	mlx->frame_count++;
	if (time_pass >= 250)
	{
		time = mlx->frame_count * 4;
		if (mlx->player->debug)
			printf("fps = %d\n", mlx->frame_count * 4);
		mlx->frame_count = 0;
		mlx->last_time = current_time;
	}
	mlx->time = time;
}
