/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:07:17 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/26 20:08:58 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "exit.h"

/**
 * @brief Check that the parameters be 2: executable + map
 * 
 * @param argc 
 */
static void	ft_check_nbr_arguments(int argc)
{
	if (argc != 2)
		ft_exit_cub3d(0);
}

/**
 * @brief Check if the map has the correct extension
 * 
 * @param map 
 */
static void	ft_check_extension(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (!ft_strnstr(&map[len - 4], ".cub", 4))
		ft_exit_cub3d(0);
}

/**
 * @brief Check if the given parameters are correct
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
void	ft_check_parameters(int argc, char *map)
{
	ft_check_nbr_arguments(argc);
	ft_check_extension(map);
}
