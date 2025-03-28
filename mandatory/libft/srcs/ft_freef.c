/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freef.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bepoisso <bepoisso@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 14:16:07 by bepoisso          #+#    #+#             */
/*   Updated: 2025/03/28 16:37:10 by bepoisso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"
// #include "../../includes/free_struct.h"

static void	check_freef_format(char format, va_list ap)
{
	if (format == 's')
		free(va_arg(ap, char *));
	else if (format == 'p')
		free(va_arg(ap, void *));
	else if (format == 'd')
		free_2d(va_arg(ap, char **));
	else if (format == 'i')
		free(va_arg(ap, int *));
}

/* 
*	ft_freef is for free multiple things in one line
	you can use like ft_printf()
	
	Args :
		str : type what you wante to free like printf
			("%p%d%i%s")
		%s : string
		%p : pointer
		%d : char ** (double strs)
		%i : int * (tab)
		... : you need to put the variable to free

	Exemple :
		ft_freef("%s%d%p", str, tab, ptr);

	You can add your struct with the lettre you want to use add a free_struct()
	to free it like this :
	
	else if (format == 'q')
		free_t_struct(va_arg(ap, t_struct *));
	
	you need to create a function to free your struct and link it with
	include to this files

	I recomade to cheate a file free_struct.h to put all your
	function to free your own struct
 */
void	ft_freef(const char *str, ...)
{
	va_list	ap;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			check_freef_format(*(++str), ap);
		str++;
	}
	va_end(ap);
}
