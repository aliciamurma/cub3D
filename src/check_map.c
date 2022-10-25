/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:36:20 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/25 17:47:15 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	check_one_player(t_game *game)
{
	int	player;
	int	cont1;
	int	cont2;

	cont1 = 0;
	cont2 = 0;
	player = 0;
	while (game->map[cont1])
	{
		cont2 = 0;
		while (game->map[cont1][cont2])
		{
			if (game->map[cont1][cont2] == 'N' || game->map[cont1][cont2] == 'S'
				|| game->map[cont1][cont2] == 'E'
				|| game->map[cont1][cont2] == 'W')
				player++;
			cont2++;
		}
		cont1++;
	}
	if (player != 1)
		close_cub3d(-2);
}

/**
 * @brief Check if there is a letter different from 1, 0, N, S, E, W, espacio, \n o NULL
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
				close_cub3d(-2);
			}
			cont2++;
		}
		cont1++;
	}
}

void	check_surrounded(t_game *game)
{
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	while (game->map[c1])
	{
		c2 = 0;
		while (game->map[c1][c2])
		{
			if (game->map[c1][c2] == '0' && (game->map[c1][c2 + 1] == ' '
			|| game->map[c1][c2 + 1] == '\n' || game->map[c1][c2 +1] == '\0'))
				close_cub3d(-2);
			c2++;
		}
		c1++;
	}
}

void	check_map(t_game *game)
{
	check_map_letters(game);
	check_one_player(game);
	check_surrounded(game);
}
