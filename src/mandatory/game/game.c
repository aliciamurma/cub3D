/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:53:25 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/27 18:55:25 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "game.h"
#include "cub.h"
#include "player.h"
#include "render.h"

int	ft_game_loop(t_game *game)
{
	if (game->player.movement.forward)
		ft_move_forward(&game->player, game->map.map);
	if (game->player.movement.backward)
		ft_move_backward(&game->player, game->map.map);
	if (game->player.movement.right)
		ft_move_right(&game->player, game->map.map);
	if (game->player.movement.left)
		ft_move_left(&game->player, game->map.map);
	if (game->player.rotation.right)
		ft_rotate_right(&game->player);
	if (game->player.rotation.left)
		ft_rotate_left(&game->player);
	ft_render_map(game);
	return (0);
}
