/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:24:44 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/06 19:59:47 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_bonus.h"
#include "window_bonus.h"
#include "cub_bonus.h"
#include "images_bonus.h"
#include "mlx.h"
#include "helpers.h"
#include <stdio.h>
void	ft_render_minimap(t_window mlx, t_cub cub, t_vector pos)
{
	int	x;
	int	y;
	(void)pos;
	t_image img1;
	t_image img2;

	img1 = ft_create_img(mlx.mlx_ptr, "./src/assets/maps/bonus/minimap1_n.xpm");
	img2 = ft_create_img(mlx.mlx_ptr, "./src/assets/maps/bonus/minimap2.xpm");
		y = 0;
	while (cub.map[y])
	{
		x = 0;
		while (cub.map[y][x])
		{
			if (cub.map[y][x] == '0' || ft_is_player(cub.map[y][x]))
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr,
					img2.pointer, 20 * x, 20 * y);
			else if (cub.map[y][x] != ' ')
				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr,
					img1.pointer, 20 * x, 20 * y);
			x++;
		}
		y++;
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, pos.y * 20 + i, pos.x * 20 + j, 0xFF0000);
		}
		
	}
	mlx_destroy_image(mlx.mlx_ptr, img1.pointer);
	mlx_destroy_image(mlx.mlx_ptr, img2.pointer);
}
