/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:48:38 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/29 17:40:47 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "helpers.h"
#include <stdio.h>

static	void	ft_free_cub(char **cub)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		free(cub[i]);
		i++;
	}
}

/**
 * @brief Parsea ek archivo .cub
 * 
 * @param mlx 
 * @param cub_raw 
 * @return t_cub 
 */
t_cub	ft_parse_cub(void *mlx, char *cub_raw)
{
	t_cub	cub;
	char	**cub_arr;

	cub_arr = ft_get_cub(cub_raw);
	cub.textures = ft_parse_cub_textures(mlx, cub_arr);
	cub.map = &cub_arr[6];
	cub.height = ft_get_map_height(cub.map);
	cub.width = ft_get_map_width(cub.map);
	ft_parse_map(cub.map, cub.height, cub.width);
	ft_free_cub(cub_arr);
	return (cub);
}
