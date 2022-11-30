/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:08:30 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/30 21:38:59 by amurcia-         ###   ########.fr       */
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

void	ft_parse_dir_north(t_player player)
{
	player.dir.x = -1;
	player.dir.y = 0;
	player.plane.x = 0;
	player.plane.y = 0.66;
	printf("im in north\n");
}

void	ft_parse_dir_south(t_player player)
{
	player.dir.x = 1;
	player.dir.y = 0;
	player.plane.x = 0;
	player.plane.y = -0.66;
	printf("im in south\n");
}

void	ft_parse_dir_east(t_player player)
{
	player.dir.x = 0;
	player.dir.y = 1;
	player.plane.x = 0.66;
	player.plane.y = 0;
	printf("im in east\n");
}

void	ft_parse_dir_west(t_player player)
{
	player.dir.x = 0;
	player.dir.y = -1;
	player.plane.x = -0.66;
	player.plane.y = 0;
	printf("im in west\n");
}

void	ft_get_direction(t_player player, char pos)
{
	if (pos == 'N')
		ft_parse_dir_north(player);
	if (pos == 'S')
		ft_parse_dir_south(player);
	if (pos == 'W')
		ft_parse_dir_west(player);
	if (pos == 'E')
		ft_parse_dir_east(player);
}

void	ft_get_player_dir(t_player player, char **map)
{
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
				ft_get_direction(player, map[c1][c2]);
			c2++;
		}
		c1++;
	}
}
