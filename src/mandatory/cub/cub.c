/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:48:38 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/03 21:21:16 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include "player.h"
#include "helpers.h"
#include "exit.h"
#include <stdio.h>

/**
 * @brief Libera la memoria de la lectura de las texturas
 * 
 * @param cub 
 */
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

void	ft_check_repeated_textures(char **map)
{
	t_num_text		num_tex;
	t_texture_types	type;
	int				i;

	i = 0;
	while (map[0] && i < 6)
	{
		type = ft_get_texture_type(map[i]);
		if (type == 0)
			ft_exit_cub3d(CUB_FORMAT);
		if (type == NO)
			num_tex.north = true;
		if (type == SO)
			num_tex.south = true;
		if (type == WE)
			num_tex.west = true;
		if (type == EA)
			num_tex.east = true;
		i++;
	}
	if (!num_tex.north || !num_tex.south || !num_tex.east || !num_tex.west)
		ft_exit_cub3d(MAP_FORMAT);
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
	t_cub		cub;
	char		**cub_arr;

	cub_arr = ft_get_cub(cub_raw);
	ft_check_repeated_textures(cub_arr);
	cub.textures = ft_parse_cub_textures(mlx, cub_arr);
	cub.map = &cub_arr[6];
	ft_free_cub(cub_arr);
	cub.height = ft_get_map_height(cub.map);
	cub.width = ft_get_map_width(cub.map);
	ft_parse_map(cub.map, cub.height, cub.width);
	return (cub);
}
