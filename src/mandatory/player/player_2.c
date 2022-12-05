/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:26:15 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/03 17:14:26 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include "game.h"
#include "player.h"

/**
 * @brief Mueve el personaje hacia la izquierda
 * 
 * @param player 
 * @param map 
 */
void	ft_move_left(t_player *player, char **map)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = ft_get_new_position(player->plane.x);
	new_pos_y = ft_get_new_position(player->plane.y);
	if (ft_can_move(map, player->pos.x - new_pos_x, player->pos.y))
		player->pos.x -= new_pos_x;
	if (ft_can_move(map, player->pos.x, player->pos.y - new_pos_y))
		player->pos.y -= new_pos_y;
}

/**
 * @brief Mueve el personaje hacia la derecha
 * 
 * @param player 
 * @param map 
 */
void	ft_move_right(t_player *player, char **map)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = ft_get_new_position(player->plane.x);
	new_pos_y = ft_get_new_position(player->plane.y);
	if (ft_can_move(map, new_pos_x + player->pos.x, player->pos.y))
		player->pos.x += new_pos_x;
	if (ft_can_move(map, player->pos.x, new_pos_y + player->pos.y))
		player->pos.y += new_pos_y;
}

/**
 * @brief Obtiene la nueva rotacion
 * 
 * @param dir_x 
 * @param dir_y 
 * @param rot_speed 
 * @return t_vector 
 */
static t_vector	ft_get_new_rotation(float dir_x, float dir_y, float rot_speed)
{
	t_vector	dir;

	dir.x = dir_x * cos(rot_speed) - dir_y * sin(rot_speed);
	dir.y = dir_x * sin(rot_speed) + dir_y * cos(rot_speed);
	return (dir);
}

/**
 * @brief Rota la camara hacia la izquierda
 * 
 * @param player 
 */
void	ft_rotate_left(t_player *player)
{
	player->dir = ft_get_new_rotation(player->dir.x, player->dir.y, -ROT_SPEED);
	player->plane = ft_get_new_rotation(
			player->plane.x, player->plane.y, -ROT_SPEED);
}

/**
 * @brief Rota la camara hacia la derecha
 * 
 * @param player 
 */
void	ft_rotate_right(t_player *player)
{
	player->dir = ft_get_new_rotation(player->dir.x, player->dir.y, ROT_SPEED);
	player->plane = ft_get_new_rotation(
			player->plane.x, player->plane.y, ROT_SPEED);
}
