/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:08:30 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/25 21:59:43 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "game.h"
#include "maps.h"
#include "player.h"

bool ft_check_dir(char pos)
{
	if (pos == 'N' || pos == 'S' || pos == 'E' || pos == 'W')
		return (true);
	return (false);
}

/**
 * @brief Get the player position
 *
 * @param game
 */
void ft_get_player_pos(t_map map, t_player player)
{
	int c1;
	int c2;

	c1 = 0;
	c2 = 0;
	while (map.map[c1])
	{
		c2 = 0;
		while (map.map[c1][c2])
		{
			if (ft_check_dir(map.map[c1][c2]))
			{
				player.pos.x = c1;
				player.pos.y = c2;
			}
			c2++;
		}
		c1++;
	}
}

/**
 * @brief Get the width of our map
 *
 * @param game
 * @param map
 */
void ft_get_map_width(t_map map)
{
	int c1;

	c1 = 0;
	map.width = 0;
	while (map.map[c1])
	{
		if (ft_strlen(map.map[c1]) > map.width)
			map.width = ft_strlen(map.map[c1]);
		c1++;
	}
}

/**
 * @brief Create a empty map
 * It is because we need to check if there is:
 * 111111
 * 11111110111
 * 11111
 * And if we don't have an space up and down the 0,
 * we won't check the uncorrect map
 *
 * @param game
 * @param map
 */
void ft_create_empty_map(t_map map)
{
	int c1;
	int c2;

	c1 = 0;
	c2 = 0;
	map.map = (char **)malloc(sizeof(char *) * (map.height + 1));
	while (c1 < map.height)
	{
		map.map[c1] = (char *)malloc(sizeof(char) * map.width + 1);
		c2 = 0;
		while (c2 < map.width)
		{
			map.map[c1][c2] = ' ';
			c2++;
		}
		c1++;
	}
}

/**
 * @brief Refile a new bidimensional array with only the map (1, 0 and player)
 *
 * @param map
 * @param e_map
 */
void ft_refile_map(t_map map, char **e_map)
{
	int c1;
	int c2;

	c1 = 0;
	c2 = 0;
	while (e_map[c1])
	{
		c2 = 0;
		while (e_map[c1][c2])
		{
			map.map[c1][c2] = e_map[c1][c2];
			c2++;
		}
		c1++;
	}
}

/**
 * @brief Get the map
 *
 * @param game
 */
void ft_get_map(t_game *game)
{
	int count;
	int countmap;
	char **map;

	count = 6;
	countmap = 0;
	map = (char **)malloc(sizeof(char *) * ft_strlen_map(game->cub) + 1);
	map[ft_strlen_map(game->map.cub)] = NULL;
	while (game->map.cub[count])
	{
		map[countmap] = malloc(sizeof(char) * ft_strlen(game->map.cub[count]));
		map[countmap][ft_strlen(game->map.cub[count])] = '\0';
		map[countmap] = game->map.cub[count];
		count++;
		countmap++;
	}
	count = 0;
	ft_get_map_width(game->map);
	game->map.height = ft_strlen_map(game->map.map) + 1;
	create_empty_map(game->map);
	ft_refile_map(game->map, map);
}
