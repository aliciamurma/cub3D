/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:25:32 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/25 13:25:57 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Read the map and put it in a unidimentional array
 * 
 * @param game 
 * @param fd 
 * @param i 
 */
static void	ft_read_cub(t_game *game, int fd, int i)
{
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return ;
	game->cub_raw = NULL;
	game->cub_raw = malloc(sizeof(char) * 1);
	game->cub_raw[0] = '\0';
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
static char	**ft_matrix_map(t_game *game)
{
	return (ft_split(game->cub_raw, '\n'));
}

/**
 * @brief Open the map and check if it can be opened
 * 
 * @param game 
 * @param argv 
 */
static void	ft_open_cub(t_game *game, char **argv)
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
	ft_read_cub(game, fd, i);
	game->map = ft_matrix_map(game);
	close(fd);
}

/**
 * @brief Get the cub info: textures, colours and the map
 * 
 * @param game 
 * @param argv 
 */
// TODO Change the name. SET
void	ft_get_cub_info(t_game *game, char **argv)
{
	ft_open_cub(game, argv);
	ft_get_textures_colours(game);
	ft_check_colours(game);
	ft_check_textures(game->texture[0].path);
	ft_check_textures(game->texture[1].path);
	ft_check_textures(game->texture[2].path);
	ft_check_textures(game->texture[3].path);
	ft_get_map(game);
}
