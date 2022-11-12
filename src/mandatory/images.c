/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 19:05:03 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/12 17:36:15 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief Charge the texture images
 * 
 * @param game 
 */
void	put_images(t_game *game)
{
	int	i;

	i = 0;
	game->img_ptr = mlx_new_image(game->mlx_ptr, HEIGHT, WIDTH);
	game->data_addr = mlx_get_data_addr(game->img_ptr, &game->bits_per_pixel, &game->width, &game->endian);
	while (i < 4)
	{
		game->texture[i].texture = mlx_xpm_file_to_image(game->mlx_ptr, game->texture[i].path, &game->texture[i].tex_width, &game->texture[i].tex_height);
		i++;
	}
}
