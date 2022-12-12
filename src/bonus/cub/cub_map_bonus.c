/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:36:20 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/11 16:11:44 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub_bonus.h"
#include "exit_bonus.h"
#include "game_bonus.h"
#include "helpers_bonus.h"

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
				&& map[c1][c2] != '\t'
				&& map[c1][c2] != '\0' && map[c1][c2] != ' '
				&& map[c1][c2] != '\n')
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
				ft_exit_cub3d(CUB_FORMAT);
			if (map[ft_strlen_map(map) - 1][c2]
				&& (map[ft_strlen_map(map) - 1][c2] != '1'
				&& map[ft_strlen_map(map) - 1][c2] != ' '))
				ft_exit_cub3d(CUB_FORMAT);
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
			if ((map[c1][c2] == '0' || ft_is_player(map[c1][c2]))
			&& (map[c1 +1][c2] == ' ' || map[c1 -1][c2] == ' '))
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
