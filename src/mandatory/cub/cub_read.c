/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:48:38 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/05 19:27:40 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "helpers.h"
#include "errors.h"
#include "exit.h"
#include "libft.h"
#include "strings.h"
#include "memory.h"

/**
 * @brief Open the .cub and check if it can be opened
 * 
 * @param cub cub path
 * @return int
 */
static int	ft_open_cub(char *cub)
{
	int		fd;

	fd = open(cub, O_RDONLY);
	if (fd == -1)
		ft_exit_cub3d(OPEN_CUB);
	return (fd);
}

/**
 * @brief Comprueba si es una linea vacia
 * 
 * @param line 
 * @return bool 
 */
static bool	ft_is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

/**
 * @brief Lee el archivo .cub
 * 
 * @param fd 
 * @param is_reading_map 
 * @return char* 
 */
char	*ft_read_cub(int fd, bool is_reading_map)
{
	static bool	is_reading = false;
	static bool	is_end = false;
	char		*aux;
	char		*line;

	aux = get_next_line(fd);
	if (!aux)
		return (NULL);
	if (is_reading && ft_is_empty_line(aux))
		is_end = true;
	if (!is_reading_map || ft_is_empty_line(aux))
	{
		line = ft_strtrim(aux, " ");
		free(aux);
	}
	else
	{
		if (is_end)
			ft_exit_cub3d(MAP_FORMAT);
		is_reading = true;
		line = aux;
	}
	aux = ft_substr(line, 0, ft_strlen(line) - 1);
	free(line);
	return (aux);
}

/**
 * @brief Parsea la informacion del .cub y la guarda en una array de strings
 * 
 * @param cub_raw 
 * @return char** 
 */
char	**ft_get_cub(char *cub_raw)
{
	char	*line;
	int		fd;
	char	**cub;

	fd = ft_open_cub(cub_raw);
	line = "";
	cub = NULL;
	while (line)
	{
		line = ft_read_cub(fd, ft_strlen_arr(cub) >= 6);
		if (!line || ft_strcmp(line, "", false))
		{
			free(line);
			continue ;
		}
		cub = ft_push_str(cub, line);
	}
	if (!line && ft_strlen_arr(cub) == 0)
		ft_exit_cub3d(MAP_FORMAT);
	free(line);
	return (cub);
}
