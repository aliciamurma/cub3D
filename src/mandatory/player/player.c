/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:49:20 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/25 18:01:18 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include "game.h"
#include "player.h"

bool	ft_can_move(char **map, double pos_x, double pos_y)
{
	if (map[(int)pos_x][(int)pos_y] == '0')
		return (true);
	return (false);
}

static double	ft_get_new_position(double dir)
{
	return (dir * SPEED);
}

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

void	ft_move_left(t_player *player, char **map)
{
	double	new_pos_x;
	double	new_pos_y;

	new_pos_x = ft_get_new_position(player->plane.x);
	new_pos_y = ft_get_new_position(player->plane.y);
	if (ft_can_move(map, new_pos_x + player->pos.x, player->pos.y))
		player->pos.x -= new_pos_x;
	if (ft_can_move(map, player->pos.x, new_pos_y + player->pos.y))
		player->pos.y -= new_pos_y;
}

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

t_vector	ft_get_new_rotation(float dir_x, float dir_y, float rot_speed)
{
	t_vector	dir;

	dir.x = dir_x * cos(rot_speed) - dir_y * sin(rot_speed);
	dir.y = dir_x * sin(rot_speed) + dir_y * cos(rot_speed);
	return (dir);
}

void	ft_rotate_left(t_player *player)
{
	player->dir = ft_get_new_rotation(player->dir.x, player->dir.y, -ROT_SPEED);
	player->plane = ft_get_new_rotation(
			player->plane.x, player->plane.y, -ROT_SPEED);
}

void	ft_rotate_right(t_player *player)
{
	player->dir = ft_get_new_rotation(player->dir.x, player->dir.y, ROT_SPEED);
	player->plane = ft_get_new_rotation(
			player->plane.x, player->plane.y, ROT_SPEED);
}
