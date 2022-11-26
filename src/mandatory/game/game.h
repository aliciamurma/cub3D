/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:59:39 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/26 17:24:06 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "maps.h"
# include "player.h"
# include "window.h"
# include "textures.h"

typedef struct s_image
{
	void	*pointer;
	// t_vector  size;
	char	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}			t_image;

typedef struct s_game
{
    t_player    player;
    t_map       map;
    t_window    mlx;
    t_image     img;
	t_texture	texture;
}	t_game;

int		ft_game_loop(t_game *game);

#endif