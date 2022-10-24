/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:08:30 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/24 20:25:54 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
 * @brief Get the textures object
 * 
 * @param game 
 */
void	get_textures(t_game *game)
{
	game->tnorth = game->cub[0];
	game->tsouth = game->cub[1];
	game->teast = game->cub[2];
	game->twest = game->cub[3];
}

/**
 * @brief Get the colours object
 * 
 * @param game 
 */
void	get_colours(t_game *game)
{
	game->floor = game->cub[4];
	game->ceiling = game->cub[5];
}

/**
 * @brief Get the map object
 * 
 * @param game 
 */
void	get_map(t_game *game)
{
	int	count;
	int	countmap;

	count = 6;
	countmap = 0;
	game->map = (char **)malloc(sizeof(char *) * ft_strlen_map(game->cub) + 1);
	while (game->cub[count])
	{
		game->map[countmap] = malloc(sizeof(char) * ft_strlen(game->cub[count]));
		game->map[countmap] = game->cub[count];
		count++;
		countmap++;
	}
}
