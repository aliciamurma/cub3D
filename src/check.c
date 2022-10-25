/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:04:11 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/25 17:47:31 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
 * @brief Check if the given parameters are correct
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	check_parameters(int argc, char **argv)
{
	int		fd;
	size_t	len;

	len = 0;
	if (argc != 2)
		close_cub3d(-1);
	fd = open(argv[0], O_RDONLY);
	if (fd < 0)
	{
		printf("Error\nNo se puede leer\n");
		exit (-1);
	}
	len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][len - 4], ".cub", 4))
	{
		printf("Error\nExtension incorrecta\n");
		exit (-1);
	}
	return (0);
}
