/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:25:32 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/25 16:12:40 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
 * @brief Read the map and put it in a unidimentional array
 * 
 * @param game 
 * @param fd 
 * @param i 
 */
static void	read_cub(t_game *game, int fd, int i)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return ;
	game->cub_raw = NULL;
	game->cub_raw = malloc(sizeof(char) * 8888);
	game->height = ft_strlen(line) - 1;
	while (line)
	{
		game->cub_raw = ft_strjoin(game->cub_raw, line);
		free (line);
		line = get_next_line(fd);
		i++;
	}
	free (line);
}

/**
 * @brief Change from unidimensional to bidimensional map
 * 
 * @param game 
 */
static void	matrix_map(t_game *game)
{
	game->cub = ft_split(game->cub_raw, '\n');
}

/**
 * @brief Open the map and check if it can be opened
 * 
 * @param game 
 * @param argv 
 */
static void	open_cub(t_game *game, char **argv)
{
	int		fd;
	size_t	i;

	i = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nNo se puede abrir\n");
		exit(1);
	}
	read_cub(game, fd, i);
	matrix_map(game);
	close(fd);
}

/**
 * @brief Get the cub info: textures, colours and the map
 * 
 * @param game 
 * @param argv 
 */
void	get_cub_info(t_game *game, char **argv)
{
	open_cub(game, argv);
	get_textures_colours(game);
	check_colours(game);
	// check_textures(game->twest);
	// check_textures(game->tsouth);
	// check_textures(game->tnorth);
	// check_textures(game->teast);
	get_map(game);
}
