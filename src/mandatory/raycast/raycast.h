/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:29:10 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/26 18:14:31 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "game.h"
# include "vector.h"


// TODO -> poner una variable con el objeto que impacta(actor)
typedef struct s_raycast
{
    int             side_2;
    int             start_draw;
    int             end_draw;
    int             line_h;
    int             colour;
    double          perp_wall_dist;
    t_vector        delta;
    t_vector        ray;
    t_vector        step;
    t_vector        side;
    t_int_vector    map;

}	t_raycast;

t_raycast	ft_get_ray(t_game *game, int x);

#endif