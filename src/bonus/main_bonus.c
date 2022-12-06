/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:51:11 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/06 14:12:31 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub_bonus.h"
#include "game_bonus.h"
#include "inputs_bonus.h"
#include "validators_bonus.h"
#include "window_bonus.h"
#include "exit_bonus.h"
#include <stdio.h>

// la funcion comand() asses the command name or program name specified 
//by command to the host environment to be executed by the command 
//processor and returns after the command has been completed
// le ponemos afplay para poner a musica
int	main(int argc, char **argv)
{
	t_game	game;

	ft_check_parameters(argc, argv);
	game.mlx = ft_new_window();
	game.map = ft_parse_cub(game.mlx.mlx_ptr, argv[1]);
	game.player = ft_new_player(game.map.map);
	// system("afplay ./src/assets/sounds/wall.wav -c 2");
	mlx_loop_hook(game.mlx.mlx_ptr, &ft_game_loop, &game);
	mlx_hook(game.mlx.win_ptr, 2, 0, handle_keydown, &game);
	mlx_hook(game.mlx.win_ptr, 3, 0, handle_keyup, &game);
	mlx_hook(game.mlx.win_ptr, 17, 0, handle_close, &game);
	mlx_hook(game.mlx.win_ptr, 6, 0, handle_mouse_move, &game);
	mlx_loop(game.mlx.mlx_ptr);
	return (0);
}
