/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 16:44:01 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/13 17:24:50 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "cub3d.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	// t_game	game;

	check_parameters(argc, argv);
	// get_cub_info(&game, argv);
	// check_map(&game);
	mlx = mlx_init();
	mlx_new_window(mlx, 500, 500, "Hello world!");
	mlx_loop(mlx);
    return (0);
}
