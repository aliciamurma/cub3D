/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:04:11 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/25 13:44:13 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "exit.h"

void	ft_check_nbr_arguments(int argc)
{
	if (argc != 2)
		exit_cub3d(0);
}

// pasar argv[1]
void	ft_check_extension(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (!ft_strnstr(&map[len - 4], ".cub", 4))
	{
		printf("Error\nExtension incorrecta\n");
		exit_cub3d(0);
	}
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
	int		fd;
	size_t	len;

	len = 0;
	// TODO gestor de errores con enum
	// validate el numero de argumentos
	if (argc != 2)
		exit_cub3d(0);
	// TODO validate filemap
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nNo se puede leer\n");
		exit_cub3d(0);
	}
	// TODO serparar en otra funcion de validate extension
	len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][len - 4], ".cub", 4))
	{
		printf("Error\nExtension incorrecta\n");
		exit_cub3d(0);
	}
}
