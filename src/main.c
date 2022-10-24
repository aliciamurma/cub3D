/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:03:35 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/24 20:24:28 by amurcia-         ###   ########.fr       */
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
	return (0);
}