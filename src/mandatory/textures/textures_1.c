/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:05:45 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/03 11:55:23 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "color.h"
#include "exit.h"
#include "helpers.h"
#include "textures.h"

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
	return (ft_create_rgb(color));
}
