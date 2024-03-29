/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:49:54 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/07 09:59:59 by amurcia-         ###   ########.fr       */
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

int		ft_render_map(t_game *game);
void	ft_render_ray(t_game *game, t_raycast_pos raycast_pos);
void	ft_render_pixel(t_image *img, int x, int y, int color);

#endif