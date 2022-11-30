/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:08:30 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/30 11:51:22 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "player.h"
#include "helpers.h"

/**
 * @brief Get the player position
 * 
 * @param map 
 * @return t_vector 
 */
t_vector	ft_get_player_pos(char **map)
{
	t_vector	vector_pos;
	int			c1;
	int			c2;

	c1 = 0;
	c2 = 0;
	while (map[c1])
	{
		c2 = 0;
		while (map[c1][c2])
		{
			if (ft_is_player(map[c1][c2]))
			{
				vector_pos.x = c1;
				vector_pos.y = c2;
				break ;
			}
			c2++;
		}
		c1++;
	}
	return (vector_pos);
}

t_vector	ft_get_direction(char pos)
{
	t_vector	vector_dir;

	if (pos == 'N')
	{
		printf("ENTRO EN LA N\n");
		vector_dir.x = 0;
		vector_dir.y = 1;
	}
	if (pos == 'S')
	{
		vector_dir.x = 0;
		vector_dir.y = -1;
	}
	if (pos == 'W')
	{
		vector_dir.x = -1;
		vector_dir.y = 0;
	}
	if (pos == 'E')
	{
		vector_dir.x = 1;
		vector_dir.y = 0;
	}
	return (vector_dir);
}

t_vector	ft_get_player_dir(char **map)
{
	int			c1;
	int			c2;
	t_vector	vector_dir;

	c1 = 0;
	c2 = 0;
	while (map[c1])
	{
		c2 = 0;
		while (map[c1][c2])
		{
			if (ft_is_player(map[c1][c2]))
				vector_dir = ft_get_direction(map[c1][c2]);
			c2++;
		}
		c1++;
	}
	return (vector_dir);
}
