/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:48:38 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/29 10:38:07 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "helpers.h"
#include <stdio.h>

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
	return (cub);
}
