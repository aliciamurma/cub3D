/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:42:49 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/06 01:40:51 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "window_bonus.h"
#include "images_bonus.h"
#include "exit_bonus.h"
#include "errors_bonus.h"
#include "render_bonus.h"
#include <stdio.h>

/**
 * @brief Crea una imagen a partir del path
 * 
 * @param mlx 
 * @param path 
 * @return t_image 
 */
t_image	ft_create_img(void *mlx, char *path)
{
	t_image	img;

	img.pointer = mlx_xpm_file_to_image(mlx, path, &img.width, &img.height);
	if (!img.pointer)
		ft_exit_cub3d(TEXT_NOTFOUND);
	img.pixels = mlx_get_data_addr(img.pointer, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}

/**
 * @brief Crea una imagen vacia
 * 
 * @param mlx 
 * @param path 
 * @return t_image 
 */
t_image	ft_create_new_img(void *mlx, int width, int height)
{
	t_image	img;

	img.pointer = mlx_new_image(mlx, width, height);
	img.pixels = mlx_get_data_addr(img.pointer, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}

t_image	ft_resize_img(void *mlx, t_image img, int ratio)
{
	t_image	img_e;
	int		x;
	int		y;
	int		c;

	x = 0;
	img_e = ft_create_new_img(mlx, ratio, ratio);
	while (x < ratio)
	{
		y = 0;
		while (y < ratio)
		{
			c = *(unsigned int *)(img.pixels
					+ (y * img.width / ratio * img.line_size + x
						* img.width / ratio * (img.bits_per_pixel / 8)));
			ft_render_pixel(&img_e, x, y, c);
			y++;
		}
		x++;
	}
	return (img_e);
}
