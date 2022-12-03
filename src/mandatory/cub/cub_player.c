/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:08:30 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/03 17:15:42 by amurcia-         ###   ########.fr       */
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
 * Añadimos el + 0.0001 para que no se encuentre con el negro absoluto
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
				vector_pos.y = c2 + 0.5;
				vector_pos.x = c1 + 0.5;
				break ;
			}
			c2++;
		}
		c1++;
	}
	return (vector_pos);
}

void	ft_get_player_dir(t_player *player, char **map)
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
			if (ft_is_player(map[c1][c2]))
				ft_get_direction(player, map[c1][c2]);
			c2++;
		}
		c1++;
	}
}
