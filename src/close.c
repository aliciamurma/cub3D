/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:29:44 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/25 17:47:03 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
 * @brief Close Cub3D
 * 
 * -1 para errores en los argumentos
 * -2 para errores en el mapa
 * 
 * @param value 
 */
void	close_cub3d(int value)
{
	if (value == -1)
		printf("Error\nNumber of arguments incorrect\n");
	if (value == -2)
		printf("Error\nMap invalid\n");
	exit (value);
}
