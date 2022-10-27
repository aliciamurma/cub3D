/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:03:35 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/27 18:12:41 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Cub es el archivo que nos dan, con las texturas, los colores y el mapa

int	main(int argc, char **argv)
{
	t_game	game;

	check_parameters(argc, argv);
	get_cub_info(&game, argv);
	check_map(&game);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, game.height, game.width, "ACABAMOS C");
	mlx_loop(game.mlx_ptr);
// 	double posX = 22, posY = 12;  //x and y start position
// 	double dirX = -1, dirY = 0; //initial direction vector
// 	double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

// 	double time = 0; //time of current frame
// 	double oldTime = 0; //time of previous frame
// 	screen(100, 100, 0, "Raycaster");
// 	while(1)
//   {
// 	for(int x = 0; x < 10; x++)
//     {
//       //calculate ray position and direction
//       double cameraX = 2 * x / double(10) - 1; //x-coordinate in camera space
//       double rayDirX = dirX + planeX * cameraX;
//       double rayDirY = dirY + planeY * cameraX;
// 	}
//   }
	return (0);
}
