/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:04:11 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/25 20:37:15 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
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
	{
		printf("Error\nExtension incorrecta\n");
		ft_exit_cub3d(0);
	}
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
