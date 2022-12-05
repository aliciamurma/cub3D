/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:29:10 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/05 17:19:48 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_BONUS_H
# define RAYCAST_BONUS_H

# include "game_bonus.h"
# include "vector_bonus.h"

// TODO -> poner una variable con el objeto que impacta(actor)
typedef struct s_raycast
{
	int				side_2;
	int				start_draw;
	int				end_draw;
	int				line_h;
	int				colour;
	double			perp_wall_dist;
	t_vector		delta;
	t_vector		ray;
	t_vector		step;
	t_vector		side;
	t_int_vector	map;

}	t_raycast;

t_raycast	ft_get_ray(t_game *game, int x);
t_vector	ft_get_ray_dir(t_player player, int x);
t_vector	ft_get_ray_abs_distance(t_vector ray);
t_vector	ft_get_step_distance(t_vector ray);
t_vector	ft_get_side_distance(t_player player, t_vector ray,
				t_vector delta, t_int_vector map);
void		ft_set_distance(t_game *game, t_raycast *raycast);

#endif