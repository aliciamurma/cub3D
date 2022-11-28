/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:36:20 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/27 12:49:04 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "game.h"
#include "cub.h"
#include "exit.h"

/**
 * @brief Check if there is only 1 player
 * Remember that the player can be N, S, E or W
 * 
 * @param game 
 */
void	ft_check_one_player(char **map)
{
	int	player;
	int	cont1;
	int	cont2;

	cont1 = 0;
	cont2 = 0;
	player = 0;
	while (map[cont1])
	{
		cont2 = 0;
		while (map[cont1][cont2])
		{
			if (map[cont1][cont2] == 'N' || map[cont1][cont2] == 'S'
				|| map[cont1][cont2] == 'E'
				|| map[cont1][cont2] == 'W')
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
void	ft_check_map_letters(char **map)
{
	int	cont1;
	int	cont2;

	cont1 = 0;
	cont2 = 0;
	while (map[cont1])
	{
		cont2 = 0;
		while (map[cont1][cont2])
		{
			if (map[cont1][cont2] != '1' && map[cont1][cont2] != '0'
				&& map[cont1][cont2] != 'N'
				&& map[cont1][cont2] != 'S'
				&& map[cont1][cont2] != 'E'
				&& map[cont1][cont2] != 'W'
				&& map[cont1][cont2] != '\0'
				&& map[cont1][cont2] != ' '
				&& map[cont1][cont2] != '\t'
				&& map[cont1][cont2] != '\n')
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
void	ft_check_surrounded_x(char **map)
{
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	while (map[c1])
	{
		if (map[c1][0] == '0')
			ft_exit_cub3d(2);
		c2 = 0;
		while (map[c1][c2])
		{
			if (map[c1][c2] == ' ' && map[c1][c2 +1] == '0')
				ft_exit_cub3d(2);
			if (map[c1][c2] == '0' && (map[c1][c2 +1] == ' '
			|| map[c1][c2 +1] == '\n' || map[c1][c2 +1] == '\0'))
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
void	ft_check_surrounded_y(char **map)
{
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	while (map[c1])
	{
		c2 = 0;
		while (map[c1][c2])
		{
			if (map[c1][c2] == '0' && (map[c1 +1][c2] == ' '
			|| map[c1 -1][c2] == ' '))
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
void	ft_check_map(t_cub *map)
{
	ft_check_map_letters(map->map);
	ft_check_one_player(map->map);
	ft_check_surrounded_x(map->map);
	ft_check_surrounded_y(map->map);
}
