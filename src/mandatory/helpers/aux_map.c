/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:34:15 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/03 17:23:32 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "helpers.h"
#include <stdio.h>

bool	ft_is_player(char pos)
{
	if (pos == 'N' || pos == 'S' || pos == 'E' || pos == 'W')
		return (true);
	return (false);
}

/**
 * @brief Get the width of our map
 * 
 * @param map 
 * @return unsigned int 
 */
unsigned int	ft_get_map_width(char **map)
{
	unsigned int	c1;
	unsigned int	width;

	c1 = 0;
	width = 0;
	while (map[c1])
	{
		if (ft_strlen(map[c1]) > width)
			width = ft_strlen(map[c1]);
		c1++;
	}
	return (width);
}

/**
 * @brief Get the height of our map
 * 
 * @param map 
 * @return unsigned int 
 */
unsigned int	ft_get_map_height(char **map)
{
	return (ft_strlen_map(map));
}

char	**ft_create_empty_map(int height, int width)
{
	char	**empty_map;
	int		c1;
	int		c2;

	c1 = 0;
	c2 = 0;
	empty_map = (char **)malloc(sizeof(char *) * (height + 1));
	while (c1 < height)
	{
		empty_map[c1] = (char *)malloc(sizeof(char) * width + 1);
		c2 = 0;
		while (c2 < width)
		{
			empty_map[c1][c2] = ' ';
			c2++;
		}
		empty_map[c1][c2] = '\0';
		c1++;
	}
	empty_map[c1] = NULL;
	return (empty_map);
}

/**
 * @brief Refile a new bidimensional array with only the map (1, 0 and player)
 *
 * @param map
 * @param e_map
 */
char	**ft_refile_map(char **map, char **empty_map)
{
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	while (map[c1])
	{
		c2 = 0;
		while (map[c1][c2])
		{
			empty_map[c1][c2] = map[c1][c2];
			c2++;
		}
		c1++;
	}
	return (empty_map);
}
