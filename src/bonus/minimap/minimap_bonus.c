/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:24:44 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/07 10:08:47 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_bonus.h"
#include "window_bonus.h"
#include "cub_bonus.h"
#include "images_bonus.h"
#include "mlx.h"
#include "helpers_bonus.h"
#include "render_bonus.h"
#include <stdio.h>
// void	ft_render_minimap(t_window mlx, t_cub cub, t_vector pos)
// {
// 	int	x;
// 	int	y;
// 	(void)pos;
// 	t_image img1;
// 	t_image img2;

// 	img1 = ft_create_img(mlx.mlx_ptr, "./src/assets/maps/bonus/minimap1_n.xpm");
// 	img2 = ft_create_img(mlx.mlx_ptr, "./src/assets/maps/bonus/minimap2.xpm");
// 		y = 0;
// 	while (cub.map[y])
// 	{
// 		x = 0;
// 		while (cub.map[y][x])
// 		{
// 			if (cub.map[y][x] == '0' || ft_is_player(cub.map[y][x]))
// 				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr,
// 					img2.pointer, 20 * x, 20 * y);
// 			else if (cub.map[y][x] != ' ')
// 				mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr,
// 					img1.pointer, 20 * x, 20 * y);
// 			x++;
// 		}
// 		y++;
// 	}
// 	for (int i = 0; i < 5; i++)
// 	{
// 		for (int j = 0; j < 5; j++)
// 		{
// 			mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, pos.y * 20 + i, pos.x * 20 + j, 0xFF0000);
// 		}
		
// 	}
// 	mlx_destroy_image(mlx.mlx_ptr, img1.pointer);
// 	mlx_destroy_image(mlx.mlx_ptr, img2.pointer);
// }

void	ft_render_minimap(t_window mlx, t_cub cub, t_vector pos)
{
	int		x;
	int		y;
	int		c;
	t_image	img;
	t_image	img1;
	t_image	img2;

	(void)pos;
	y = 0;
	img1 = ft_create_img(mlx.mlx_ptr, "./src/assets/maps/bonus/minimap1_n.xpm");
	img2 = ft_create_img(mlx.mlx_ptr, "./src/assets/maps/bonus/minimap2.xpm");
	img = ft_create_new_img(mlx.mlx_ptr, 200, 200);
	while (cub.map[y])
	{
		x = 0;
		while (cub.map[y][x])
		{
			if (cub.map[y][x] == '0' || ft_is_player(cub.map[y][x]))
			{
				c = *(unsigned int *)(img.pixels
					+ (y * 20 * img1.line_size + x
						* 20 * (img1.bits_per_pixel / 8)));
				ft_render_pixel(&img1, x, y, c);
			}
			else if (cub.map[y][x] != ' ')
			{
				c = *(unsigned int *)(img2.pixels
					+ (y * 20 * img2.line_size + x
						* 20 * (img2.bits_per_pixel / 8)));
				ft_render_pixel(&img2, x, y, c);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr,
		img.pointer, 20 * x, 20 * y);
	mlx_destroy_image(mlx.mlx_ptr, img.pointer);
}
