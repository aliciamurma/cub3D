/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:36:20 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/25 22:03:30 by amurcia-         ###   ########.fr       */
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
void	ft_check_one_player(t_map map)
{
	int	player;
	int	cont1;
	int	cont2;

	cont1 = 0;
	cont2 = 0;
	player = 0;
	while (map.map[cont1])
	{
		cont2 = 0;
		while (map.map[cont1][cont2])
		{
			if (map.map[cont1][cont2] == 'N' || map.map[cont1][cont2] == 'S'
				|| map.map[cont1][cont2] == 'E'
				|| map.map[cont1][cont2] == 'W')
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
void	ft_check_map_letters(t_map map)
{
	int	cont1;
	int	cont2;

	cont1 = 0;
	cont2 = 0;
	while (map.map[cont1])
	{
		cont2 = 0;
		while (map.map[cont1][cont2])
		{
			if (map.map[cont1][cont2] != '1' && map.map[cont1][cont2] != '0'
				&& map.map[cont1][cont2] != 'N'
				&& map.map[cont1][cont2] != 'S'
				&& map.map[cont1][cont2] != 'E'
				&& map.map[cont1][cont2] != 'W'
				&& map.map[cont1][cont2] != '\0'
				&& map.map[cont1][cont2] != ' '
				&& map.map[cont1][cont2] != '\t'
				&& map.map[cont1][cont2] != '\n')
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
void	ft_check_surrounded_x(t_map map)
{
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	while (map.map[c1])
	{
		if (map.map[c1][0] == '0')
			close_cub3d(-2);
		c2 = 0;
		while (map.map[c1][c2])
		{
			if (map.map[c1][c2] == ' ' && map.map[c1][c2 +1] == '0')
				close_cub3d(-2);
			if (map.map[c1][c2] == '0' && (map.map[c1][c2 +1] == ' '
			|| map.map[c1][c2 +1] == '\n' || map.map[c1][c2 +1] == '\0'))
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
void	ft_check_surrounded_y(t_map map)
{
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	while (map.map[c1])
	{
		c2 = 0;
		while (map.map[c1][c2])
		{
			if (map.map[c1][c2] == '0' && (map.map[c1 +1][c2] == ' '
			|| map.map[c1 -1][c2] == ' '))
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
void	ft_check_map(t_map map)
{
	ft_check_map_letters(map);
	ft_check_one_player(map);
	ft_check_surrounded_x(map);
	ft_check_surrounded_y(map);
}
