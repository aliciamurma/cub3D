/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:36:20 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/25 20:32:57 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "exit.h"
#include "maps.h"

/**
 * @brief Check if there is only 1 player
 * Remember that the player can be N, S, E or W
 * 
 * @param game 
 */
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
		ft_exit_cub3d(-2);
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
				ft_exit_cub3d(2);
			}
			cont2++;
		}
		cont1++;
	}
}

/**
 * @brief Check if the map is surrounded by 1 - x axis
 * 
 * @param game 
 */
void	check_surrounded_x(t_game *game)
{
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	while (game->map[c1])
	{
		if (game->map[c1][0] == '0')
			close_cub3d(-2);
		c2 = 0;
		while (game->map[c1][c2])
		{
			if (game->map[c1][c2] == ' ' && game->map[c1][c2 +1] == '0')
				close_cub3d(-2);
			if (game->map[c1][c2] == '0' && (game->map[c1][c2 +1] == ' '
			|| game->map[c1][c2 +1] == '\n' || game->map[c1][c2 +1] == '\0'))
			{
				ft_exit_cub3d(2);
			}
			c2++;
		}
		c1++;
	}
}

/**
 * @brief Check if the map is surrounded by 1 - y axis
 * 
 * @param game 
 */
void	check_surrounded_y(t_game *game)
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
			if (game->map[c1][c2] == '0' && (game->map[c1 +1][c2] == ' '
			|| game->map[c1 -1][c2] == ' '))
				ft_exit_cub3d(2);
			c2++;
		}
		c1++;
	}
}

/**
 * @brief Check the inside of the map
 * 
 * @param game 
 */
void	check_map(t_game *game)
{
	check_map_letters(game);
	check_one_player(game);
	check_surrounded_x(game);
	check_surrounded_y(game);
}
