/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:59:17 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/02 19:53:52 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include "game.h"
#include "player.h"

/**
 * @brief Crea la variable del jugador
 * 
 * @return t_player 
 */
t_player	ft_new_player(char **map)
{
	t_player	player;

	player.pos = ft_get_player_pos(map);
	// printf("my pos is x: %d y: %d\n", player.pos.x, player.pos.y);
	ft_get_player_dir(&player, map);
	// printf("my dir is x: %f y: %f\n", player.dir.x, player.dir.y);
	// player.pos.x = 6;
	// player.pos.y = 9;
	// player.dir.x = -1;
	// player.dir.y = 0;
	// player.plane.x = 0;
	// player.plane.y = 0.66;
	player.movement.forward = false;
	player.movement.backward = false;
	player.movement.right = false;
	player.movement.left = false;
	player.rotation.right = false;
	player.rotation.left = false;
	return (player);
}

/**
 * @brief Comprueba si el jugador se puede mover a la posicion indicada
 * 
 * @param map 
 * @param pos_x 
 * @param pos_y 
 * @return true 
 * @return false 
 */
bool	ft_can_move(char **map, double pos_x, double pos_y)
{
	if (map[(int)pos_x][(int)pos_y] == '0')
		return (true);
	return (false);
}

/**
 * @brief Obtiene la nueva posicion del personaje
 * 
 * @param dir 
 * @return double 
 */
double	ft_get_new_position(double dir)
{
	return (dir * SPEED);
}

/**
 * @brief Mueve el personaje hacia adelante
 * 
 * @param player 
 * @param map 
 */
void	ft_move_forward(t_player *player, char **map)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = ft_get_new_position(player->dir.x);
	new_pos_y = ft_get_new_position(player->dir.y);
	if (ft_can_move(map, new_pos_x + player->pos.x, player->pos.y))
		player->pos.x += new_pos_x;
	if (ft_can_move(map, player->pos.x, new_pos_y + player->pos.y))
		player->pos.y += new_pos_y;
}

/**
 * @brief Mueve el personaje hacia atras
 * 
 * @param player 
 * @param map 
 */
void	ft_move_backward(t_player *player, char **map)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = ft_get_new_position(player->dir.x);
	new_pos_y = ft_get_new_position(player->dir.y);
	if (ft_can_move(map, new_pos_x + player->pos.x, player->pos.y))
		player->pos.x -= new_pos_x;
	if (ft_can_move(map, player->pos.x, new_pos_y + player->pos.y))
		player->pos.y -= new_pos_y;
}
