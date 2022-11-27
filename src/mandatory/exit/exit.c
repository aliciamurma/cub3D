/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:29:44 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/27 11:20:36 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "exit.h"
#include "errors.h"

void	ft_print_error(t_errors code)
{
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
