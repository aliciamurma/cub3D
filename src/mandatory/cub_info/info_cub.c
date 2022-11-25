/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:08:30 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/25 13:37:35 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Check if the given number for the colours is correct
 * 
 * @param game 
 */
void	check_colours(t_game *game)
{
	char	**nbrs;

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

/**
 * @brief Check if the texture path can be opened
 * 
 * @param str 
 */
void	check_textures(char *str)
{
	int		fd;

	fd = open(str, R_OK);
	if (fd == -1)
		close_cub3d(-2);
	close(fd);
}

/**
 * @brief Get the texture path
 * 
 * @param game 
 * @param index 
 * @param pos 
 */
void	ft_get_texture_path(t_game *game, int index, int pos)
{
	char	**path;

	path = ft_split(game->cub[pos], ' ');
	game->texture[index].path = malloc(sizeof(char) * ft_strlen(path[1]));
	game->texture[index].path = path[1];
}


// TODO 
// noth_texture
	// -get_path
	// -check_path
	// -load_texture
// south_texture
	// -get_path
	// -check_path
	// -load_texture
// east_texture
	// -get_path
	// -check_path
	// -load_texture
// west_texture
	// -get_path
	// -check_path
	// -load_texture
// ceil_color
	// -check_path
// floor_color
	// -check_path
	// -load_color
// 

/**
 * @brief Get the textures and colours object
 * 
 * @param game 
 */
void	ft_get_textures_colours(t_game *game)
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
				ft_get_texture_path(game, 0, count1);
				break ;
			}
			else if (ft_strnstr(game->cub[count1], "SO", 2))
			{
				ft_get_texture_path(game, 1, count1);
				break ;
			}
			else if (ft_strnstr(game->cub[count1], "WE", 2))
			{
				ft_get_texture_path(game, 2, count1);
				break ;
			}
			else if (ft_strnstr(game->cub[count1], "EA", 2))
			{
				ft_get_texture_path(game, 3, count1);
				break ;
			}
			else if (ft_strnstr(game->cub[count1], "F", 1))
			{
				game->floor = game->cub[count1];
				break ;
			}
			else if (ft_strnstr(game->cub[count1], "C", 1))
			{
				game->ceiling = game->cub[count1];
				break ;
			}
			else
				exit_cub3d(2);
		}
		count1++;
	}
}
