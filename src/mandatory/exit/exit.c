/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:29:44 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/03 18:04:18 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "exit.h"
#include "errors.h"

/**
 * @brief Pinta el error y su descripcio
 * 
 * @param code 
 */
void	ft_print_error(t_errors code)
{
	if (code != 0)
		printf("Error\n");
	printf("%s\n", ft_get_error(code));
}

/**
 * @brief Close Cub3D
 * 
 * @param value 
 */
void	ft_exit_cub3d(t_errors code)
{
	ft_print_error(code);
	// mlx_destroy_window();
	exit(code);
}
