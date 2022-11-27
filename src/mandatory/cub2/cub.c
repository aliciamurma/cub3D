/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:13:32 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/27 12:49:04 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include "libft.h"
#include "cub.h"
#include "game.h"
#include "helpers.h"
#include "exit.h"

/**
 * @brief Read the map and put it in a unidimentional array
 *
 * @param game
 * @param fd
 */
static char	*ft_read_cub2(int height, int fd)
{
	char	*line;
	char	*cub_raw;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	cub_raw = malloc(sizeof(char) * 1);
	cub_raw[0] = '\0';
	// height = ft_strlen(line) - 1;
	(void)height;
	while (line)
	{
		cub_raw = ft_strjoin(cub_raw, line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (cub_raw);
}

/**
 * @brief Change from unidimensional to bidimensional map
 *
 * @param game
 */
static char **ft_matrix_map(char *cub_raw)
{
    return (ft_split(cub_raw, '\n'));
}

/**
 * @brief Open the .cub and check if it can be opened
 *
 * @param game
 * @param argv
 */
char **ft_open_cub(int height, char *cub)
{
    int fd;
    char *cub_raw;

    fd = open(cub, O_RDONLY);
    if (fd == -1)
        ft_exit_cub3d(1);
    cub_raw = ft_read_cub2(height, fd);
    close(fd);
    return (ft_matrix_map(cub_raw));
    // TODO podria ser en una unica funcion con un realloc para ir guardando en la array las nuevas lineas si tienen contenido
    // TODO tambien se podria comprobar al leer la linea el tipo del que son
    // TODO una funcion tipo parseo
}

/**
 * @brief Get the cub info: textures, colours and the map
 *
 * @param game
 * @param argv
 */
void	ft_set_cub_info(t_game *game, char *cub)
{
	(void)game;
	(void)cub;
    // game->map.cub = ft_open_cub(game->cub.height, cub);
    // ft_get_textures(&game->map, &game->texture);
    // ft_get_cub(&game->map, &game->player);
}
