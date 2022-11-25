/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:08:30 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/25 13:47:46 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "cub3d.h"

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
void get_player_pos(t_game *game)
{
	int c1;
	int c2;

	c1 = 0;
	c2 = 0;
	while (game->map[c1])
	{
		c2 = 0;
		while (game->map[c1][c2])
		{
			if (ft_check_dir(game->map[c1][c2]))
			{
				game->player_x = c1;
				game->player_y = c2;
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
void get_width(t_game *game, char **map)
{
	int c1;

	c1 = 0;
	game->width = 0;
	while (map[c1])
	{
		if (ft_strlen(map[c1]) > game->width)
			game->width = ft_strlen(map[c1]);
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
void create_empty_map(t_game *game, char **map)
{
	int c1;
	int c2;

	c1 = 0;
	c2 = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	while (c1 < game->height)
	{
		game->map[c1] = (char *)malloc(sizeof(char) * game->width + 1);
		c2 = 0;
		while (c2 < game->width)
		{
			game->map[c1][c2] = ' ';
			c2++;
		}
		c1++;
	}
}

/**
 * @brief Refile a new bidimensional array with only the map (1, 0 and player)
 *
 * @param game
 * @param map
 */
void refile_map(t_game *game, char **map)
{
	int c1;
	int c2;

	c1 = 0;
	c2 = 0;
	while (map[c1])
	{
		c2 = 0;
		while (map[c1][c2])
		{
			game->map[c1][c2] = map[c1][c2];
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
void get_map(t_game *game)
{
	int count;
	int countmap;
	char **map;

	count = 6;
	countmap = 0;
	map = (char **)malloc(sizeof(char *) * ft_strlen_map(game->cub) + 1);
	map[ft_strlen_map(game->cub)] = NULL;
	while (game->cub[count])
	{
		map[countmap] = malloc(sizeof(char) * ft_strlen(game->cub[count]));
		map[countmap][ft_strlen(game->cub[count])] = '\0';
		map[countmap] = game->cub[count];
		count++;
		countmap++;
	}
	count = 0;
	get_width(game, map);
	game->height = ft_strlen_map(map) + 1;
	create_empty_map(game, map);
	refile_map(game, map);
}
