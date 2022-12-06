/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:49:54 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/06 01:44:46 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_BONUS_H
# define RENDER_BONUS_H

# include "game_bonus.h"
# include "raycast_bonus.h"

typedef struct s_raycast_pos
{
	int			x;
	t_raycast	raycast;
}	t_raycast_pos;

int		ft_render_map(t_game *game);
void	ft_render_ray(t_game *game, t_raycast_pos raycast_pos);
void	ft_render_pixel(t_image *img, int x, int y, int color);

void	ft_render_weapon(t_window mlx, char *path);

#endif