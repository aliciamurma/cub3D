/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:51:11 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/30 11:33:37 by amurcia-         ###   ########.fr       */
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
int	main(int argc, char **argv)
{
	t_game	game;

	ft_check_parameters(argc, argv);
	game.mlx = ft_new_window();
	game.map = ft_parse_cub(game.mlx.mlx_ptr, argv[1]);
	game.player = ft_new_player(game.map.map);
	mlx_loop_hook(game.mlx.mlx_ptr, &ft_game_loop, &game);
	mlx_hook(game.mlx.win_ptr, 2, 0, handle_keydown, &game);
	mlx_hook(game.mlx.win_ptr, 3, 0, handle_keyup, &game);
	mlx_hook(game.mlx.win_ptr, 17, 0, handle_close, &game);
	mlx_loop(game.mlx.mlx_ptr);
	return (0);
}
