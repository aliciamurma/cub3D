/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 17:10:00 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/03 17:11:19 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	ft_parse_dir_north(t_player *player)
{
	player->dir.x = -1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0.66;
}

void	ft_parse_dir_south(t_player *player)
{
	player->dir.x = 1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = -0.66;
}

void	ft_parse_dir_east(t_player *player)
{
	player->dir.x = 0;
	player->dir.y = 1;
	player->plane.x = 0.66;
	player->plane.y = 0;
}

void	ft_parse_dir_west(t_player *player)
{
	player->dir.x = 0;
	player->dir.y = -1;
	player->plane.x = -0.66;
	player->plane.y = 0;
}

void	ft_get_direction(t_player *player, char pos)
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
