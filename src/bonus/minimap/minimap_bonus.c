/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:24:44 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/07 21:03:39 by amurcia-         ###   ########.fr       */
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

#define MARGING 200

void	ft_render_player(t_window mlx, t_vector pos, int ratio, int w, int h)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, w + (pos.y * ratio + i), h + (pos.x * ratio + j), 0xFF0000);
			j++;
		}
		i++;
	}
}

void	ft_render_pixel_image(t_image img, int x, int y, int c, int ratio)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ratio)
	{
		j = 0;
		while (j < ratio)
		{
			ft_render_pixel(&img, j + (x * ratio), (y * ratio) + i, c);
			j++;
		}
		i++;
	}
}

void	ft_refile_minimap(t_image img, t_cub cub, int x, int y)
{
	float	ratio;

	if (cub.width > cub.height)
		ratio = (WIDTH - MARGING) / cub.width;
	else
		ratio = (HEIGHT - MARGING) / cub.height;
	while (cub.map[y][x])
	{
		if (cub.map[y][x] == '0' || ft_is_player(cub.map[y][x]))
		{
			ft_render_pixel_image(img, x, y, 0x0abd1c, ratio);
		}
		else if (cub.map[y][x] != ' ')
		{
			ft_render_pixel_image(img, x, y, 0x02560b, ratio);
		}
		else
			ft_render_pixel_image(img, x, y, 0x02560b, ratio);
		x++;
	}
	while (x < cub.width)
	{
		ft_render_pixel_image(img, x, y, 0x02560b, ratio);
		x++;
	}
}

// TODO escalar de 200 a nuestro mapa con un define, un 20%
void	ft_render_minimap(t_window mlx, t_cub cub, t_vector pos)
{
	int		x;
	int		y;
	t_image	img;
	float	ratio;

	if (cub.width > cub.height)
		ratio = (WIDTH - MARGING) / cub.width;
	else
		ratio = (HEIGHT - MARGING) / cub.height;
	y = 0;
	img = ft_create_new_img(mlx.mlx_ptr, ratio * cub.width, ratio * cub.height);
	while (cub.map[y])
	{
		x = 0;
		ft_refile_minimap(img, cub, x, y);
		y++;
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.pointer, (WIDTH - ratio * cub.width)/2, (HEIGHT - ratio * cub.height)/2);
	ft_render_player(mlx, pos, ratio, (WIDTH - ratio * cub.width) / 2, (HEIGHT - ratio * cub.height) / 2);
	mlx_destroy_image(mlx.mlx_ptr, img.pointer);
}
