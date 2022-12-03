/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:29:04 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/03 17:31:06 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "mlx.h"
#include "cub.h"
#include "game.h"
#include "raycast.h"
#include "window.h"

/**
 * @brief Calcula la distancia perpendicular a el muro
 * 
 * @param pos 
 * @param map 
 * @param step 
 * @param ray 
 * @return double 
 */
static double	ft_calc_perp_wall_dist(
	double pos, int map, double step, double ray)
{
	return ((map - pos + (1 - step) / 2) / ray);
}

/**
 * @brief Obtiene la posicion donde empieza a dibujar el rayo
 * 
 * @param line_h 
 * @return int 
 */
static int	ft_get_start_draw(int line_h)
{
	int	start_draw;

	start_draw = -line_h / 2 + WIDTH / 2;
	if (start_draw < 0)
		return (0);
	return (start_draw);
}

/**
 * @brief Obtiene la posicion donde termina de dibuar el rayo
 * 
 * @param line_h 
 * @return int 
 */
static int	ft_get_end_draw(int line_h)
{
	int	end_draw;

	end_draw = line_h / 2 + WIDTH / 2;
	if (end_draw >= WIDTH)
		return (WIDTH - 1);
	return (end_draw);
}

/**
 * @brief Lanza un raycast y obtiene la informacion del rayo
 * 
 * @param game 
 * @param x 
 * @return t_raycast 
 */
t_raycast	ft_get_ray(t_game *game, int x)
{
	t_raycast	raycast;

	raycast.ray = ft_get_ray_dir(game->player, x);
	raycast.delta = ft_get_ray_abs_distance(raycast.ray);
	raycast.map.x = (int)game->player.pos.x;
	raycast.map.y = (int)game->player.pos.y;
	raycast.step = ft_get_step_distance(raycast.ray);
	raycast.side = ft_get_side_distance(game->player, raycast.ray,
			raycast.delta, raycast.map);
	ft_set_distance(game, &raycast);
	if (raycast.side_2 == 0)
		raycast.perp_wall_dist = ft_calc_perp_wall_dist(game->player.pos.x,
				raycast.map.x, raycast.step.x, raycast.ray.x);
	else
		raycast.perp_wall_dist = ft_calc_perp_wall_dist(game->player.pos.y,
				raycast.map.y, raycast.step.y, raycast.ray.y);
	raycast.line_h = (int)(WIDTH / raycast.perp_wall_dist);
	raycast.start_draw = ft_get_start_draw(raycast.line_h);
	raycast.end_draw = ft_get_end_draw(raycast.line_h);
	return (raycast);
}
