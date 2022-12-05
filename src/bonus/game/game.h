/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:59:39 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/27 17:28:33 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "player.h"
# include "cub.h"
# include "window.h"
# include "textures.h"

typedef struct s_game
{
	t_player	player;
	t_cub		map;
	t_window	mlx;
	t_image		img;
	t_texture	texture;
}	t_game;

int		ft_game_loop(t_game *game);

#endif