/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 11:48:38 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/27 15:29:38 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include "helpers.h"
#include "errors.h"
#include "exit.h"
#include "libft.h"
// #include "helpers.h"
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
			ft_exit_cub3d(4);
		is_reading = true;
		line = aux;
	}
	aux = ft_substr(line, 0, ft_strlen(line) - 1);
	free(line);
	return (aux);
}

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
			continue ;
		cub = ft_push_str(cub, line);
	}
	return (cub);
}
