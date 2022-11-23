/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:29:44 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/18 15:53:11 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"
// TODO ver donde ponemos la estructura del juego para incluir
#include "cub3d.h"
#include <stdlib.h>

/**
 * @brief Close Cub3D
 * 
 * @param value 
 */
void	exit_cub3d(int value)
{
	print_error(value);
	exit(value);
}

void	close_cub3d(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit_cub3d(0);
}
