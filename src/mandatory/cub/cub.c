/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:48:38 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/28 16:21:47 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	return (cub);
}
