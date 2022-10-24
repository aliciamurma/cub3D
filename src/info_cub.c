/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:08:30 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/24 18:26:45 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	get_textures(t_game *game)
{
	int	cont1;

	cont1 = empty_line(game, 0);
	game->textures[0] = game->cub[cont1];
	game->textures[1] = game->cub[cont1 + 1];
	game->textures[2] = game->cub[cont1 + 2];
	game->textures[3] = game->cub[cont1 + 3];
}

void	get_colours(t_game *game)
{
	int	cont1;

	cont1 = empty_line(game, cont1) + 4;
	cont1 = empty_line(game, cont1);
	game->colours[0] = game->cub[cont1];
	game->colours[1] = game->cub[cont1 + 1];
}

void	get_map(t_game *game)
{
	int	cont1;
	int	cont2;
	int	cmap;

	cont2 = 0;
	cmap = 0;
	cont1 = empty_line(game, cont1) + 4;
	cont1 = empty_line(game, cont1) + 2;
	cont1 = empty_line(game, cont1);
	while (game->cub[cont1][cont2])
	{
		cont2 = 0;
		while (game->cub[cont1][cont2])
		{
			game->map[cmap][cont2] = game->cub[cont1][cont2];
			cont2++;
		}
		cont1++;
		cmap++;
	}
}
