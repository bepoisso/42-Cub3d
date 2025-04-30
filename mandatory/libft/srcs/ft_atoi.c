/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afontan <afontan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 00:29:30 by bepoisso          #+#    #+#             */
/*   Updated: 2025/04/29 14:33:51 by afontan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	neg;
	int	i;

	neg = 0;
	result = 0;
	i = 0;
	if (nptr[i] == '-')
	{
		neg = 1;
		i++;
	}
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (-2147483648);
		while (nptr[i] >= '0' && nptr[i] <= '9')
			result = (result * 10) + (nptr[i++] - '0');
		if (nptr[i])
			i++;
	}
	if (neg)
		return (-result);
	return (result);
}
