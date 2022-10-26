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
