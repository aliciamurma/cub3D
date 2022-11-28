/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:07:17 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/28 15:06:56 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft.h"
#include "exit.h"
#include "errors.h"

/**
 * @brief Check that the parameters be 2: executable + map
 * 
 * @param argc 
 */
static bool	ft_check_nbr_arguments(int argc)
{
	if (argc != 2)
		return (false);
	return (true);
}

/**
 * @brief Check if the map has the correct extension
 * 
 * @param map 
 */
static bool	ft_check_extension(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (len < 4 || !ft_strnstr(&map[len - 4], ".cub", 4))
		return (false);
	return (true);
}

/**
 * @brief Check if the given parameters are correct
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
void	ft_check_parameters(int argc, char **argv)
{
	if (!ft_check_nbr_arguments(argc))
		ft_exit_cub3d(INV_ARGS);
	if (!ft_check_extension(argv[1]))
		ft_exit_cub3d(INV_CUB_EXT);
}
