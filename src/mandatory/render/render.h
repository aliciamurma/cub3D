/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:49:54 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/28 15:36:59 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "game.h"
# include "raycast.h"

typedef struct s_raycast_pos
{
	int			x;
	t_raycast	raycast;
}	t_raycast_pos;

int	ft_render_map(t_game *game);

#endif