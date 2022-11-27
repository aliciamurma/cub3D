/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:51:11 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/27 18:52:30 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "game.h"
#include "mlx.h"
#include "validators.h"
#include "window.h"
#include "cub.h"
#include "inputs.h"

/**
 * @brief
 * mlx_init --> Inicializamos mlx
 * mlx_new_window --> Abrimos la ventana
 * mlx_new_image --> PARA QUE??
 * mlx_xpm_file_to_image y mlx_get_data_addr --> Carga la imagen
 * mlx_loop --> Crea un bucle para que no se cierre el juego
 * mlx_put_image_to_window --> Pone la imagen en la ventana
 *
 *  FOV = 2 * atan(0.66/1.0)=66.8 es adecuado para tiradores en primera persona
 * @return int
 */
// int main(void)
int	main(int argc, char **argv)
{
	t_game	game;

	ft_check_parameters(argc, argv);
	game.mlx.mlx_ptr = mlx_init();
	ft_parse_cub(game.mlx.mlx_ptr, argv[1]);
	game.player.pos.x = 12;
	game.player.pos.y = 5;
	game.player.dir.x = -1;
	game.player.dir.y = 0;
	game.player.plane.x = 0;
	game.player.plane.y = 0.66;
	game.mlx.win_ptr = mlx_new_window(game.mlx.mlx_ptr, WIDTH, HEIGHT, NAME_WIN);
	game.player.movement.forward = false;
	game.player.movement.backward = false;
	game.player.movement.right = false;
	game.player.movement.left = false;
	game.player.rotation.right = false;
	game.player.rotation.left = false;
	mlx_loop_hook(game.mlx.mlx_ptr, &ft_game_loop, &game);
	mlx_hook(game.mlx.win_ptr, 2, 0, handle_keydown, &game);
	mlx_hook(game.mlx.win_ptr, 3, 0, handle_keyup, &game);
	mlx_hook(game.mlx.win_ptr, 17, 0, handle_close, &game);
	mlx_loop(game.mlx.mlx_ptr);
	return (0);
}
