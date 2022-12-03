/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:34:47 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/03 17:31:31 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include "mlx.h"
#include "game.h"
#include "cub.h"
#include "raycast.h"
#include "window.h"

/**
 * @brief Recogemos la dirección del rayo
 *
 * @param game
 * @param x
 * @return t_vector
 */
t_vector	ft_get_ray_dir(t_player player, int x)
{
	double		camera_x;
	t_vector	ray;

	camera_x = 2 * x / (double)WIDTH - 1;
	ray.x = player.dir.x + player.plane.x * camera_x;
	ray.y = player.dir.y + player.plane.y * camera_x;
	return (ray);
}

/**
 * @brief Calcula la distancia absoluta del rayo
 * 
 * @param ray 
 * @return t_vector 
 */
t_vector	ft_get_ray_abs_distance(t_vector ray)
{
	t_vector	delta;

	delta.x = fabs(1 / ray.x);
	delta.y = fabs(1 / ray.y);
	return (delta);
}

/**
 * @brief Calcula la distancia por cada paso
 * 
 * @param ray 
 * @return t_vector 
 */
t_vector	ft_get_step_distance(t_vector ray)
{
	t_vector	distance;

	if (ray.x < 0)
		distance.x = -1;
	else
		distance.x = 1;
	if (ray.y < 0)
		distance.y = -1;
	else
		distance.y = 1;
	return (distance);
}

/**
 * @brief Obtiene la distancia del lado
 * 
 * @param player 
 * @param ray 
 * @param delta 
 * @param map 
 * @return t_vector 
 */
t_vector	ft_get_side_distance(t_player player, t_vector ray,
		t_vector delta, t_int_vector map)
{
	t_vector	distance;

	if (ray.x < 0)
		distance.x = (player.pos.x - map.x) * delta.x;
	else
		distance.x = (map.x + 1.0 - player.pos.x) * delta.x;
	if (ray.y < 0)
		distance.y = (player.pos.y - map.y) * delta.y;
	else
		distance.y = (map.y + 1.0 - player.pos.y) * delta.y;
	return (distance);
}

/**
 * @brief Obtiene la distancia hasta el objeto en el que impacta
 * 
 * @param game 
 * @param raycast 
 */
// TODO comprobar con que impacta y retornar el tipo
void	ft_set_distance(t_game *game, t_raycast *raycast)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (raycast->side.x < raycast->side.y)
		{
			raycast->side.x += raycast->delta.x;
			raycast->map.x += raycast->step.x;
			raycast->side_2 = 0;
		}
		else
		{
			raycast->side.y += raycast->delta.y;
			raycast->map.y += raycast->step.y;
			raycast->side_2 = 1;
		}
		if (game->map.map[raycast->map.x][raycast->map.y] == '1')
			hit = 1;
	}
}
