/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:59:17 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/03 16:39:08 by aramirez         ###   ########.fr       */
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
	ft_get_player_dir(&player, map);
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
bool	ft_can_move(char **map, double pos_x, double pos_y, t_orientation ori)
{
	(void)ori;
	printf("x: %f y: %f\n", pos_x, pos_y);
	printf("%c\n", map[(int)trunc(pos_x)][(int)trunc(pos_y)]);
	if (map[(int)trunc(pos_x)][(int)trunc(pos_y)] != '1'
		&& map[(int)trunc(pos_x + 0.25)][(int)trunc(pos_y + 0.25)] != '1'
		&& map[(int)trunc(pos_x - 0.25)][(int)trunc(pos_y - 0.25)] != '1'
		&& map[(int)trunc(pos_x - 0.25)][(int)trunc(pos_y + 0.25)] != '1'
		&& map[(int)trunc(pos_x + 0.25)][(int)trunc(pos_y - 0.25)] != '1'
		)
		return (true);
	printf("NO\n");
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
	if (ft_can_move(map, new_pos_x + player->pos.x, player->pos.y, 1))
		player->pos.x += new_pos_x;
	if (ft_can_move(map, player->pos.x, new_pos_y + player->pos.y, 1))
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
	printf("1\n");
	printf("x: %f, y: %f\n", player->pos.x, player->pos.y);
	printf("dx: %f, dy: %f\n", player->dir.x, player->dir.y);
	printf("px: %f, py: %f\n", player->plane.x, player->plane.y);
	printf("nx: %f, ny: %f\n", new_pos_x, new_pos_y);
	printf("2\n");
	if (ft_can_move(map, player->pos.x - new_pos_x, player->pos.y, 1))
		player->pos.x -= new_pos_x;
	if (ft_can_move(map, player->pos.x, player->pos.y - new_pos_y, 1))
		player->pos.y -= new_pos_y;
}
