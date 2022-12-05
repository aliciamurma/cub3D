/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:40:02 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/03 11:54:08 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "color.h"
#include "exit.h"

/**
 * @brief Verifica que el color entre entre el numero 0 y 255, incluidos
 * 
 * @param color 
 */
void	ft_check_color(int color)
{
	if (color < 0 || color > 255)
		ft_exit_cub3d(COLOR_FORMAT);
}

/**
 * @brief Verifica si el color es un numero
 * 
 * @param color 
 */
void	ft_check_color_digit(char *color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		if (!ft_isdigit(color[i]))
			ft_exit_cub3d(COLOR_FORMAT);
		i++;
	}
}

/**
 * @brief Convierte un color rgb a hexadecimal
 * 
 * @param color color grb
 * @return unsigned int 
 */
unsigned int	ft_create_rgb(t_color color)
{
	return (
		((color.r & 0xff) << 16)
		+ ((color.g & 0xff) << 8)
		+ (color.b & 0xff)
	);
}
