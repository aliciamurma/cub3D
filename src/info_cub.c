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

void	check_colours(t_game *game)
{
	char	**nbrs;

	nbrs = ft_split(game->floor, ' ');
	nbrs = ft_split(nbrs[1], ',');
	if (!nbrs || nbrs[4] != NULL)
		close_cub3d(-1);
	if ((nbrs[0] < 0 && nbrs[0] > 255) || (nbrs[1] < 0 && nbrs[1] > 255) || (nbrs[2] < 0 && nbrs[2] > 255))
		close_cub3d(-1);
	floor_nbr = ft_split(game->ceiling, ' ');
	floor_nbr = ft_split(floor_nbr[1], ',');
	if (!nbrs || nbrs[4] != NULL)
		close_cub3d(-1);
	if ((nbrs[0] < 0 && nbrs[0] > 255) || (nbrs[1] < 0 && nbrs[1] > 255) || (nbrs[2] < 0 && nbrs[2] > 255))
		close_cub3d(-1);
	free (floor_nbr);
}

void	check_textures(char *str)
{
	int fd;

	char	**texture;

	texture = ft_split(str, ' ');
	fd = open(texture[1], R_OK);
	if (fd == -1)
	{
		free_matrix(texture);
		close_cub3d(-1);
	}
	close(fd);
	free_matrix(texture);
}

/**
 * @brief Get the textures and colours object
 * 
 * @param game 
 */
void	get_textures_colours(t_game *game)
{
	int	count1;
	int	count2;
	
	count1 = 0;
	count2 = 0;
	while (game->cub[count1])
	{
		while (game->cub[count1][count2])
		{
			if (game->cub[count1][count2] == ' ' || game->cub[count1][count2] == '\t')
				count2++;
			if (ft_strnstr(game->cub[count1], "NO", 2))
				game->tnorth = game->cub[count1];
			if (ft_strnstr(game->cub[count1], "SO", 2))
				game->tsouth = game->cub[count1];
			if (ft_strnstr(game->cub[count1], "WE", 2))
				game->twest = game->cub[count1];
			if (ft_strnstr(game->cub[count1], "EA", 2))
				game->teast = game->cub[count1];
			if (ft_strnstr(game->cub[count1], "F", 2))
				game->floor = game->cub[count1];
			if (ft_strnstr(game->cub[count1], "C", 2))
				game->ceiling = game->cub[count1];
			else
				close_cub3d(-1);
		}
		count1++;
	}
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
