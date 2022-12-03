/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:51:11 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/03 21:16:14 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub.h"
#include "game.h"
#include "inputs.h"
#include "validators.h"
#include "window.h"
#include "exit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_game	game;

	ft_check_parameters(argc, argv);
	game.mlx = ft_new_window();
	game.map = ft_parse_cub(game.mlx.mlx_ptr, argv[1]);
	mlx_destroy_window(game.mlx.mlx_ptr, game.mlx.win_ptr);
	game.player = ft_new_player(game.map.map);
	mlx_loop_hook(game.mlx.mlx_ptr, &ft_game_loop, &game);
	mlx_hook(game.mlx.win_ptr, 2, 0, handle_keydown, &game);
	mlx_hook(game.mlx.win_ptr, 3, 0, handle_keyup, &game);
	mlx_hook(game.mlx.win_ptr, 17, 0, handle_close, &game);
	mlx_loop(game.mlx.mlx_ptr);
	return (0);
}

// TODO
// tenemos floor and ceiling al reves