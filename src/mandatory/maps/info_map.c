/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:08:30 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/26 22:17:31 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "game.h"
#include "maps.h"
#include "helpers.h"

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
t_vector ft_get_player_pos(char **map)
{
	t_vector	vector_pos;
	int c1;
	int c2;

	c1 = 0;
	c2 = 0;
	while (map[c1])
	{
		c2 = 0;
		while (map[c1][c2])
		{
			if (ft_check_dir(map[c1][c2]))
			{
				vector_pos.x = c1;
				vector_pos.y = c2;
				break ;
			}
			c2++;
		}
		c1++;
	}
	return (vector_pos);
}

/**
 * @brief Get the width of our map
 *
 * @param game
 * @param map
 */
unsigned int ft_get_map_width(char **map)
{
	unsigned int c1;
	unsigned int width;

	c1 = 0;
	width = 0;
	while (map[c1])
	{
		if (ft_strlen(map[c1]) > width)
			width = ft_strlen(map[c1]);
		c1++;
	}
	return (width);
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
void ft_create_empty_map(t_map *map)
{
	int c1;
	int c2;

	c1 = 0;
	c2 = 0;
	map->map = (char **)malloc(sizeof(char *) * (map->height + 1));
	while (c1 < map->height)
	{
		map->map[c1] = (char *)malloc(sizeof(char) * map->width + 1);
		c2 = 0;
		while (c2 < map->width)
		{
			map->map[c1][c2] = ' ';
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
void ft_refile_map(char **map, char **e_map)
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
			map[c1][c2] = e_map[c1][c2];
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
void ft_get_map(t_map *map, t_player *player)
{
	int count;
	int countmap;
	char **bid_map;

	count = 6;
	countmap = 0;
	bid_map = (char **)malloc(sizeof(char *) * ft_strlen_map(map->cub) + 1);
	bid_map[ft_strlen_map(map->cub)] = NULL;
	while (map->cub[count])
	{
		bid_map[countmap] = malloc(sizeof(char) * ft_strlen(map->cub[count]));
		bid_map[countmap][ft_strlen(map->cub[count])] = '\0';
		bid_map[countmap] = map->cub[count];
		count++;
		countmap++;
	}
	count = 0;
	map->width = ft_get_map_width(bid_map);
	map->height = ft_strlen_map(bid_map) + 1;
	ft_create_empty_map(map);
	ft_refile_map(map->map, bid_map);
	player->pos = ft_get_player_pos(map->map);
}
