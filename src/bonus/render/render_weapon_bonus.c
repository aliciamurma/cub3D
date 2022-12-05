/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_weapon_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:59:11 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/05 19:20:38 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "window_bonus.h"
#include "render_bonus.h"
#include "images_bonus.h"

void ft_render_weapon(void *mlx, void *win)
{
	t_image img;
	t_image img_w;
	int count = WIDTH / 3;

	img.pointer = mlx_new_image(mlx, count, count);
	img.pixels = mlx_get_data_addr(img.pointer, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	img_w = ft_create_img(mlx, "./src/assets/weapons/new_weapon.xpm");

	// mlx_put_image_to_window(mlx, win,
	// 	img.pointer, WIDTH / 2 - img.width / 2, HEIGHT - img.height);

	for (int x = 0; x < count; x++)
	{
		for (int y = 0; y < count; y++)
		{
			// printf("r: %i\n", y * img_w.width/count);
			int c = *(unsigned int *)(img_w.pixels + (y * img_w.width/count * img_w.line_size + x * img_w.width/count * (img_w.bits_per_pixel / 8)));

			// OPCION 2 con la imagen
			int pixel = (y * img.line_size) + (x * 4);
			int color = 0xFFFFFF;						 // ignoramos esto
			if (img.bits_per_pixel != 32)				 // ignoramos esto
				color = mlx_get_color_value(mlx, color); // ignoramos esto

			if (img.endian == 1) // Most significant (Alpha) byte first
			{
				img.pixels[pixel + 0] = (c >> 24);
				img.pixels[pixel + 1] = (c >> 16) & 0xFF;
				img.pixels[pixel + 2] = (c >> 8) & 0xFF;
				img.pixels[pixel + 3] = (c)&0xFF;
			}
			else if (img.endian == 0) // Least significant (Blue) byte first
			{
				img.pixels[pixel + 0] = (c)&0xFF;
				img.pixels[pixel + 1] = (c >> 8) & 0xFF;
				img.pixels[pixel + 2] = (c >> 16) & 0xFF;
				img.pixels[pixel + 3] = (c >> 24);
			}
		}
	}
		mlx_put_image_to_window(mlx, win, img.pointer, (WIDTH / 2 - count / 2), HEIGHT - count);
}
