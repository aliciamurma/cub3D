/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:59:39 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/06 19:32:07 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_BONUS_H
# define GAME_BONUS_H

# include <stdbool.h>
# include "player_bonus.h"
# include "cub_bonus.h"
# include "window_bonus.h"
# include "textures_bonus.h"

typedef struct s_game
{
	t_player	player;
	t_cub		map;
	t_window	mlx;
	t_image		img;
	t_texture	texture;
	bool		minimap;
}	t_game;

int		ft_game_loop(t_game *game);

#endif