/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:05:45 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/27 18:46:36 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "textures.h"
#include "helpers.h"
#include <stdio.h>

unsigned int	create_rgb(t_color color)
{
	return (((color.r & 0xff) << 16) + ((color.g & 0xff) << 8) + (color.b & 0xff));
}

// TODO valorar si seria necesario que el atoi mirase si no enviamos un numero y dar un error
unsigned int	ft_parse_color(char *input)
{
	char	**color_arr;
	char	*aux;
	t_color	color;
	int		i;

	color_arr = ft_split(input, ',');
	i = 0;
	while (color_arr[i])
	{
		aux = ft_strtrim(color_arr[i], " ");
		if (i == 0)
			color.r = ft_atoi(aux);
		if (i == 1)
			color.g = ft_atoi(aux);
		if (i == 2)
			color.b = ft_atoi(aux);
		free(aux);
		i++;
	}
	ft_free_matrix(color_arr);
	return (create_rgb(color));
}
