/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:42:49 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/29 00:44:44 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "window.h"
#include "images.h"
#include "exit.h"
#include "errors.h"

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
