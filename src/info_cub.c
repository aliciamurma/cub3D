/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:08:30 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/27 20:35:44 by amurcia-         ###   ########.fr       */
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

	fd = open(str, R_OK);
	if (fd == -1)
		close_cub3d(-2);
	close(fd);
}

void	get_texture_path(t_game *game, int index, int pos)
{
	char	**path;

	path = ft_split(game->cub[pos], ' ');
	game->texture[index].path = malloc(sizeof(char) * ft_strlen(path[1]));
	game->texture[index].path = path[1];
}

/**
 * @brief Get the textures and colours object
 * 
 * @param game 
 */
void	get_textures_colours(t_game *game)
{
	int		count1;
	int		count2;

	game->texture = malloc(sizeof(t_texture));
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
				get_texture_path(game, 0, count1);
				break ;
			}
			else if (ft_strnstr(game->cub[count1], "SO", 2))
			{
				get_texture_path(game, 1, count1);
				break ;
			}
			else if (ft_strnstr(game->cub[count1], "WE", 2))
			{
				get_texture_path(game, 2, count1);
				break ;
			}
			else if (ft_strnstr(game->cub[count1], "EA", 2))
			{
				get_texture_path(game, 3, count1);
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
