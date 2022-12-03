/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:05:45 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/03 20:11:11 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "color.h"
#include "exit.h"
#include "helpers.h"
#include "textures.h"

int	ft_get_checked_colors(char *str_color)
{
	int	aux;

	ft_check_color_digit(str_color);
	aux = ft_atoi(str_color);
	ft_check_color(aux);
	return (aux);
}

/**
 * @brief Parsea la informacion del color del .cub
 * 
 * @param input linea leida del .cub
 * @return unsigned int 
 */
unsigned int	ft_parse_color(char *input)
{
	char	**color_arr;
	char	*aux;
	t_color	color;
	int		i;

	color_arr = ft_split(input, ',');
	if (!color_arr[0] || !color_arr[1] || !color_arr[2])
		ft_exit_cub3d(MAP_FORMAT);
	i = 0;
	while (color_arr[i])
	{
		aux = ft_strtrim(color_arr[i], " ");
		if (i == 0)
			color.r = ft_get_checked_colors(aux);
		if (i == 1)
			color.g = ft_get_checked_colors(aux);
		if (i == 2)
			color.b = ft_get_checked_colors(aux);
		free(aux);
		i++;
	}
	ft_free_matrix(color_arr);
	free(input);
	return (ft_create_rgb(color));
}
