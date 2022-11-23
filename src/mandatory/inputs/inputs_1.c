/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 20:40:00 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/18 15:31:50 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	handle_keydown(int keycode, t_game *game)
{
	// 1 Cerrar ventana
	
	// 2 Movimiento personaje
	
	// 3 Rotacion de la camara
}

void	handle_keyup(int keycode, t_game *game)
{

}

void	handle_mousemove(int keycode, t_game *game)
{

}

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

void	escape(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	close_cub3d(0);
}

void	move_forward(t_game *game)
{

}

void	move_backward(t_game *game)
{

}

void	move_left(t_game *game)
{
	
}

void	move_right(t_game *game)
{
	
}

void	rotate_right(t_game *game)
{
	
}

void	rotate_left(t_game *game)
{
	
}
