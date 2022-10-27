/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:08:30 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/27 17:41:55 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	get_player_pos(t_game *game)
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
			if (game->map[c1][c2] == 'N' || game->map[c1][c2] == 'S'
				|| game->map[c1][c2] == 'E' || game->map[c1][c2] == 'W')
			{
				game->player_x = c1;
				game->player_y = c2;
			}
			c2++;
		}
		c1++;
	}
}

void	get_width(t_game *game, char **map)
{
	int	c1;

	c1 = 0;
	while (map[c1] && map[c1 + 1])
	{
		if (ft_strlen(map[c1]) > ft_strlen(map[c1 + 1]))
			game->width = ft_strlen(map[c1]);
		c1++;
	}
	game->width++;
}

void	create_empty_map(t_game *game, char **map)
{
	int	c1;
	int	c2;

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

void	refile_map(t_game *game, char **map)
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
			game->map[c1][c2] = map[c1][c2];
			c2++;
		}
		c1++;
	}
}

/**
 * @brief Get the map object
 * 
 * @param game 
 */
void	get_map(t_game *game)
{
	int		count;
	int		countmap;
	char	**map;

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
