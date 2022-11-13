/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:03:35 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/12 17:36:44 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// Cub es el archivo que nos dan, con las texturas, los colores y el mapa

/**
 * @brief Calculate the ray position and direction
 * 
 * @param game 
 * @param x 
 */
void	init_ray(t_game *game, int x)
{
	game->pos.camera_x = 2 * x / (double) WIDTH -1;
	game->pos.ray_x = game->pos.dir_x + game->pos.plane_x * game->pos.camera_x;
	game->pos.ray_y = game->pos.dir_y + game->pos.plane_y * game->pos.camera_x;
	game->pos.map_x = (int)game->pos.pos_x;
	game->pos.map_y = (int)game->pos.pos_y;
	game->pos.delta_dist_x = fabs(1 / game->pos.ray_x);
	game->pos.delta_dist_y = fabs(1 / game->pos.ray_y);
}

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
	game->bits_per_pixel = 6;
	game->pos.speed_move = 0.04;
	game->pos.speed_rot = 0.04;
	game->pos.buffer = NULL;
	game->pos.dir_x = -1.0;
	game->pos.dir_y = 0.0;
	game->pos.plane_x = -1.0;
	game->pos.plane_y = 0.66;
	game->pos.time = 0;
	game->pos.old_time = 0;
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
int	main(void)
// int	main(int argc, char **argv)
{
	t_game	game;
	// int		x;

	// x = 0;
	// check_parameters(argc, argv);
	// get_cub_info(&game, argv);
	// check_map(&game);
	// init_data(&game);
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, HEIGHT, WIDTH, "ACABAMOS C");
	put_images(&game);
	// mlx_hook(game.win_ptr, 02, (0L << 0), movements, &game);
	mlx_hook(game.win_ptr, 17, 0, close_x, &game);
	// while (x < WIDTH)
	// {
	// 	init_ray(&game, x);
	// }
	mlx_loop(game.mlx_ptr);
	return (0);
}
