/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _info_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:08:30 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/29 11:06:39 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include "game.h"
#include "cub.h"
#include "helpers.h"

bool	ft_check_dir(char pos)
{
	if (pos == 'N' || pos == 'S' || pos == 'E' || pos == 'W')
		return (true);
	return (false);
}

/**
 * @brief Get the player position
 *
 * @param game
 */
t_vector ft_get_player_pos(char **map)
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
			if (ft_check_dir(map[c1][c2]))
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

