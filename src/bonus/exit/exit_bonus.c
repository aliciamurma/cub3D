/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:29:44 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/05 17:15:22 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "exit_bonus.h"
#include "errors_bonus.h"

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
	exit(code);
}
