/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:25:32 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/25 22:06:43 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "game.h"
#include "maps.h"
#include "exit.h"

/**
 * @brief Read the map and put it in a unidimentional array
 * 
 * @param game 
 * @param fd
 */
static char	*ft_read_cub(t_map map, int fd, char *cub_raw)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return ;
	cub_raw = NULL;
	cub_raw = malloc(sizeof(char) * 1);
	cub_raw[0] = '\0';
	map.height = ft_strlen(line) - 1;
	while (line)
	{
		cub_raw = ft_strjoin(cub_raw, line);
		free (line);
		line = get_next_line(fd);
	}
	free (line);
	return (cub_raw);
}

/**
 * @brief Change from unidimensional to bidimensional map
 * 
 * @param game 
 */
static char	**ft_matrix_map(char *cub_raw)
{
	return (ft_split(cub_raw, '\n'));
}

/**
 * @brief Open the .cub and check if it can be opened
 * 
 * @param game 
 * @param argv 
 */
static void	ft_open_cub(t_map map, char *cub)
{
	int		fd;
	char	*cub_raw;

	fd = open(cub, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nNo se puede abrir\n");
		ft_exit_cub3d(1);
	}
	cub_raw = ft_read_cub(map, fd, cub_raw);
	map.cub = ft_matrix_map(cub_raw);
	close(fd);
}

/**
 * @brief Get the cub info: textures, colours and the map
 * 
 * @param game 
 * @param argv 
 */
void	ft_set_cub_info(t_game *game, char *cub)
{

	ft_open_cub(game->map, cub);
	ft_get_textures_colours(game->map, game->texture);
	ft_get_map(game);
}
