/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:03:35 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/28 18:04:28 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// Cub es el archivo que nos dan, con las texturas, los colores y el mapa

// void	init_ray(t_game game, int x)
// {

// 	pos = malloc(sizeof(t_position));
// 	pos.camera_x = 2 * x / (double)WIDTH -1;

// 	ray_dirx;
// 	ray_diry;
// }

// void	init_raycasting(t_game game)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	y = 0;
// 	while (x < WIDTH)
// 	{
// 		init_ray(game, x);
// 		x++;
// 	}
// }

void	init_data(t_game *game)
{
	// game.pos = malloc(sizeof(t_position));
	// game->pos.speed_move = 1;
	(void) game;
}

/**
 * @brief 
 * Check if the parameters are correct
 * Extract the info from the given .cub (argv[1])
 * Init the game
 * Create a new window
 * Charge the images
 * Make a hook for the movements
 * Make a hook for the X botton
 * Create a loop for the window
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */
int	main(int argc, char **argv)
{
	t_game	game;
	game.bits_per_pixel = 6;

	check_parameters(argc, argv);
	get_cub_info(&game, argv);
	check_map(&game);
	init_data(&game);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, HEIGHT, WIDTH, "ACABAMOS C");
	put_images(&game);
	mlx_hook(game.win_ptr, 02, (0L << 0), movements, &game);
	// mlx_hook(game.win_ptr, 02, (0L << 0), movements, &game);
	mlx_hook(game.win_ptr, 17, 0, close_x, &game);
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
	mlx_loop(game.mlx_ptr);
	return (0);
}
