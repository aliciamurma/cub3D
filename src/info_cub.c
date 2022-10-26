/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:08:30 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/25 17:47:59 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "../inc/cub3d.h"

void	check_colours(t_game *game)
{
	char	**nbrs;
	char	**raw_nbrs;

	nbrs = ft_my_split(game->floor);
	if (!nbrs)
		close_cub3d(-1);
	if ((ft_atoi(nbrs[3]) < 0 || ft_atoi(nbrs[3]) > 255)
		|| (ft_atoi(nbrs[1]) < 0 || ft_atoi(nbrs[1]) > 255)
		|| (ft_atoi(nbrs[2]) < 0 || ft_atoi(nbrs[2]) > 255))
		close_cub3d(-2);
	free (nbrs);
	nbrs = ft_my_split(game->ceiling);
	if (!nbrs)
		close_cub3d(-2);
	if ((ft_atoi(nbrs[3]) < 0 || ft_atoi(nbrs[3]) > 255)
		|| (ft_atoi(nbrs[1]) < 0 || ft_atoi(nbrs[1]) > 255)
		|| (ft_atoi(nbrs[2]) < 0 || ft_atoi(nbrs[2]) > 255))
		close_cub3d(-2);
	free (nbrs);
}

void	check_textures(char *str)
{
	int		fd;
	char	**texture;

	texture = ft_split(str, ' ');
	fd = open(texture[1], R_OK);
	if (fd == -1)
	{
		printf("aun no tengo textura\n");
		free_matrix(texture);
		close_cub3d(-2);
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
	while (count1 < 6)
	{
		while (game->cub[count1][count2])
		{
			if (game->cub[count1][count2] == ' ' || game->cub[count1][count2] == '\t')
				count2++;
			else if (ft_strnstr(game->cub[count1], "NO", 2))
			{
				game->tnorth = game->cub[count1];
				break ;
			}
			else if (ft_strnstr(game->cub[count1], "SO", 2))
			{
				game->tsouth = game->cub[count1];
				break ;
			}
			else if (ft_strnstr(game->cub[count1], "WE", 2))
			{
				game->twest = game->cub[count1];
				break ;
			}
			else if (ft_strnstr(game->cub[count1], "EA", 2))
			{
				game->teast = game->cub[count1];
				break ;
			}
			else if (ft_strnstr(game->cub[count1], "F", 2))
			{
				game->floor = game->cub[count1];
				break ;
			}
			else if (ft_strnstr(game->cub[count1], "C", 2))
			{
				game->ceiling = game->cub[count1];
				break ;
			}
			else
				close_cub3d(-2);
		}
		count1++;
	}
}

void	get_height(t_game *game, char **map)
{
	int	c1;
	int	c2;
	int	c2_old;

	c1 = 0;
	c2 = 0;
	c2_old = 0;
	while (map[c1])
	{
		c2 = 0;
		while (map[c1][c2])
		{
			c2++;
		}
		if (c2_old < c2)
			c2_old = c2;
		c1++;
	}
	game->height = c2_old;
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
}

void	create_map(t_game *game, char **map)
{
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	game->map = (char **)malloc(sizeof(char *) * (game->height + 1));
	game->map[game->height] = NULL;
	while (c1 < game->height)
	{
		game->map[c1] = (char *)malloc(sizeof(char) * game->width + 1);
		game->map[c1][game->width] = '\0';
		c2 = 0;
		while (c2 < game->width)
		{
			game->map[c1][c2] = ' ';
			c2++;
		}
		c1++;
	}
}

void	refile_spaces(t_game *game, char **map)
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
	int	count;
	int	countmap;
	char	**map;

	count = 6;
	countmap = 0;
	map = (char **)malloc(sizeof(char *) * ft_strlen_map(game->cub) + 1);
	while (game->cub[count])
	{
		map[countmap] = malloc(sizeof(char) * ft_strlen(game->cub[count]));
		map[countmap] = game->cub[count];
		count++;
		countmap++;
	}
	count = 0;
	get_width(game, map);
	get_height(game, map);
	create_map(game, map);
	refile_spaces(game, map);
}
