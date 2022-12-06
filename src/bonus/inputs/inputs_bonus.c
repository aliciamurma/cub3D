/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:51:09 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/06 18:23:04 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "mlx.h"
#include "game_bonus.h"
#include "player_bonus.h"
#include "inputs_bonus.h"
#include "exit_bonus.h"

#include <stdlib.h>
/**
 * @brief Evento que se ejecuta al pulsar una tecla
 * Identidica que tecla se ha pulsado y llama a su funcionalidad
 * 
 * @param key 
 * @param game 
 * @return int 
 */
int	handle_keydown(int key, t_game *game)
{
	if (key == UP)
		game->player.movement.forward = true;
	if (key == DOWN)
		game->player.movement.backward = true;
	if (key == RIGHT)
		game->player.movement.right = true;
	if (key == LEFT)
		game->player.movement.left = true;
	if (key == ROT_LEFT)
		game->player.rotation.left = true;
	if (key == ROT_RIGHT)
		game->player.rotation.right = true;
	if (key == SHOOT)
		game->player.is_shooting = true;
	if (key == ESC)
		ft_exit_cub3d(0);
	return (0);
}

/**
 * @brief Evento que se ejecuta al pulsar una tecla
 * Identidica que tecla se ha pulsado y llama a su funcionalidad
 * 
 * @param key 
 * @param game 
 * @return int 
 */
int	handle_keyup(int key, t_game *game)
{
	if (key == UP)
		game->player.movement.forward = false;
	if (key == DOWN)
		game->player.movement.backward = false;
	if (key == RIGHT)
		game->player.movement.right = false;
	if (key == LEFT)
		game->player.movement.left = false;
	if (key == ROT_LEFT)
		game->player.rotation.left = false;
	if (key == ROT_RIGHT)
		game->player.rotation.right = false;
	// else
	// 	system("afplay ./src/assets/sounds/intro.wav -t 5");
	return (0);
}

int	handle_mouse_move(int x, int y, t_game *game)
{
	static int	old_pos = 0;
	static bool	is_init = false;

	if (!is_init)
	{
		is_init = true;
		old_pos = x;
		return (0);
	}
	// mlx_mouse_hide(game->mlx.mlx_ptr, game->mlx.win_ptr);
	// mlx_mouse_move(game->mlx.win_ptr, x, y);
	mlx_mouse_get_pos(game->mlx.win_ptr, &x, &y);
	if (x > old_pos || x >= WIDTH)
		ft_rotate_left(&game->player);
	else if (x < old_pos || x <= 0)
		ft_rotate_right(&game->player);
	if ( x > WIDTH)
		old_pos = WIDTH;
	else
		old_pos = x;
	return (0);
}

int	handle_mouse_hook(int key, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (key == 1)
		game->player.is_shooting = true;
	return (0);
}

/**
 * @brief Evento que se ejecuta cuando se cierra la ventana 
 * del programa con el boton
 * 
 * @param game 
 * @return int 
 */
int	handle_close(t_game *game)
{
	(void)game;
	ft_exit_cub3d(0);
	return (0);
}
