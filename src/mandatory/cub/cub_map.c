/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:36:20 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/30 11:12:26 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "game.h"
#include "cub.h"
#include "exit.h"
#include "helpers.h"

/**
 * @brief Check if there is only 1 player
 * Remember that the player can be N, S, E or W
 * 
 * @param game 
 */
void	ft_check_one_player(char **map)
{
	int	player;
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	player = 0;
	while (map[c1])
	{
		c2 = 0;
		while (map[c1][c2])
		{
			if (ft_is_player(map[c1][c2]))
				player++;
			c2++;
		}
		c1++;
	}
	if (player != 1)
		ft_exit_cub3d(CUB_FORMAT);
}

/**
 * @brief Check if there is a letter different from 
 * 1, 0, N, S, E, W, espacio, \n o NULL
 * 
 * @param game 
 */
void	ft_check_map_letters(char **map)
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
			if (map[c1][c2] != '1' && map[c1][c2] != '0'
				&& map[c1][c2] != 'N' && map[c1][c2] != 'S'
				&& map[c1][c2] != 'E' && map[c1][c2] != 'W'
				&& map[c1][c2] != '\0' && map[c1][c2] != ' '
				&& map[c1][c2] != '\t' && map[c1][c2] != '\n')
			{
				ft_exit_cub3d(CUB_FORMAT);
			}
			c2++;
		}
		c1++;
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
			ft_exit_cub3d(CUB_FORMAT);
		c2 = 0;
		while (map[c1][c2])
		{
			if (map[c1][c2] == ' ' && map[c1][c2 +1] == '0')
				ft_exit_cub3d(CUB_FORMAT);
			if (map[c1][c2] == '0' && (map[c1][c2 +1] == ' '
			|| map[c1][c2 +1] == '\n' || map[c1][c2 +1] == '\0'))
			{
				printf("IM IN POS %d\n %d\n", c1, c2);
				ft_exit_cub3d(CUB_FORMAT);
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
				ft_exit_cub3d(CUB_FORMAT);
			c2++;
		}
		c1++;
	}
}

char	**ft_create_spaces_map(char **map, int height, int width)
{
	char	**empty_map;

	empty_map = ft_create_empty_map(height, width);
	return (ft_refile_map(map, empty_map));
}

/**
 * @brief Check the inside of the map
 * 
 * @param game 
 */
void	ft_parse_map(char **map, int height, int width)
{
	char	**spaces_map;

	ft_check_map_letters(map);
	ft_check_one_player(map);
	spaces_map = ft_create_spaces_map(map, height, width);
	ft_check_surrounded_x(spaces_map);
	ft_check_surrounded_y(spaces_map);
	ft_free_matrix(spaces_map);
}
