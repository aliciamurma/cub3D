/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:40:00 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/12 17:36:03 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Keycode of movements
 * 
 * @param keycode 
 * @param game 
 * @return int 
 */
int	movements(int keycode, t_game *game)
{
	if (keycode == 53)
	{
		mlx_clear_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		close_cub3d(0);
	}
	return (0);
}
