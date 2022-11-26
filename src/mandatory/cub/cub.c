/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:13:32 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/26 20:27:08 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"
#include "game.h"
#include "helpers.h"
#include "exit.h"

/**
 * @brief Read the map and put it in a unidimentional array
 * 
 * @param game 
 * @param fd
 */
static char	*ft_read_cub(int height, int fd, char *cub_raw)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	cub_raw = NULL;
	cub_raw = malloc(sizeof(char) * 1);
	cub_raw[0] = '\0';
	height = ft_strlen(line) - 1;
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
static char **ft_open_cub(int height, char *cub)
{
	int		fd;
	char	*cub_raw;

	cub_raw = NULL;
	fd = open(cub, O_RDONLY);
	if (fd == -1)
		ft_exit_cub3d(1);
	cub_raw = ft_read_cub(height, fd, cub_raw);
	close(fd);
	return (ft_matrix_map(cub_raw));
}

/**
 * @brief Get the cub info: textures, colours and the map
 * 
 * @param game 
 * @param argv 
 */
void	ft_set_cub_info(t_game *game, char *cub)
{
	game->map.cub = ft_open_cub(game->map.height, cub);
	ft_get_textures(game->map, game->texture);
	ft_get_map(game);
}
