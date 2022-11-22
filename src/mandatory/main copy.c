/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:03:35 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/22 20:49:25 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_image
{
	void	*pointer;
	// t_vector  size;
	char	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}			t_image;

void	ft_put_image(void)
{
	t_image	img;

	img.pointer = mlx_new_image(mlx, HEIGHT, WIDTH);
	img.pixels = mlx_get_data_addr(img.pointer, &img.bits_per_pixel,
			&img.line_size, &img.endian);
}
