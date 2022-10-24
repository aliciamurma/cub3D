/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:36:20 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/24 20:32:54 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
 * @brief Check if there is a letter different from 1, 0, N, S, E, W, \n o NULL
 * 
 * @param game 
 */
void	check_map_letters(t_game *game)
{
	int	cont1;
	int	cont2;

	cont1 = 0;
	cont2 = 0;
	while (game->map[cont1])
	{
		cont2 = 0;
		while (game->map[cont1][cont2])
		{
			if (game->map[cont1][cont2] != '1' && game->map[cont1][cont2] != '0'
				&& game->map[cont1][cont2] != 'N'
				&& game->map[cont1][cont2] != 'S'
				&& game->map[cont1][cont2] != 'E'
				&& game->map[cont1][cont2] != 'W'
				&& game->map[cont1][cont2] != '\0'
				&& game->map[cont1][cont2] != ' '
				&& game->map[cont1][cont2] != '\t'
				&& game->map[cont1][cont2] != '\n')
			{
				close_cub3d(-1);
			}
			cont2++;
		}
		cont1++;
	}
}

void	check_map(t_game *game)
{
	check_map_letters(game);
}
