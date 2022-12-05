/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:51:09 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/05 19:58:08 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "game_bonus.h"
#include "player_bonus.h"
#include "inputs_bonus.h"
#include "exit_bonus.h"

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
	return (0);
}

int	handle_mouse_move(int x, int y, t_game *game)
{
	printf("x: %i, y: %i\n", x, y);
	(void)game;
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
