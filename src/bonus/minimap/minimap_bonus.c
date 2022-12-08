/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:24:44 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/08 13:01:17 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "cub_bonus.h"
#include "helpers_bonus.h"
#include "images_bonus.h"
#include "minimap_bonus.h"
#include "render_bonus.h"
#include "vector_bonus.h"
#include "window_bonus.h"

/**
 * @brief Printa el personaje en el mapa grande
 * 
 * @param mlx 
 * @param pos 
 * @param ratio 
 * @param dim es la dimensión, ancho y largo
 */
static void	ft_render_player(t_window mlx, t_vector pos, int rat, t_vector dim)
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
			mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, dim.x + (pos.y * rat + i),
				dim.y + (pos.x * rat + j), 0xFF0000);
			j++;
		}
		i++;
	}
}

/**
 * @brief Printamos los píxeles en función del ratio
 * 
 * @param img 
 * @param vec 
 * @param c 
 * @param ratio 
 */
static void	ft_render_pixel_image(t_image img, t_int_vector vec, int c, int ratio)
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
			ft_render_pixel(&img, j + (vec.x * ratio), (vec.y * ratio) + i, c);
			j++;
		}
		i++;
	}
}

/**
 * @brief Rellenamos la nueva imagen de píxeles
 * 
 * @param img 
 * @param cub 
 * @param vec 
 */
static void	ft_refile_minimap(t_image img, t_cub cub, t_int_vector vec)
{
	float	ratio;

	if (cub.width > cub.height)
		ratio = (WIDTH - MARGING) / cub.width;
	else
		ratio = (HEIGHT - MARGING) / cub.height;
	while (cub.map[vec.y][vec.x])
	{
		if (cub.map[vec.y][vec.x] == '0' || ft_is_player(cub.map[vec.y][vec.x]))
			ft_render_pixel_image(img, vec, 0x0abd1c, ratio);
		else
			ft_render_pixel_image(img, vec, 0x02560b, ratio);
		vec.x++;
	}
	while (vec.x < cub.width)
	{
		ft_render_pixel_image(img, vec, 0x02560b, ratio);
		vec.x++;
	}
}

/**
 * @brief Obtenemos el ratio del minimapa
 * 
 * @param cub 
 * @return int 
 */
static int	ft_get_ratio(t_cub cub)
{
	if (cub.width > cub.height)
		return ((WIDTH - MARGING) / cub.width);
	else
		return ((HEIGHT - MARGING) / cub.height);
}

/**
 * @brief Printamos el minimapa
 * Primero obtenemos una nueva imagen y la rellenamos de píxeles
 * Y luego printamos la nueva imagen
 * 
 * @param mlx 
 * @param cub 
 * @param pos 
 */
void	ft_render_minimap(t_window mlx, t_cub cub, t_vector pos)
{
	int				ratio;
	t_vector		dimension;
	t_int_vector	vector;
	t_image			img;

	vector.y = 0;
	ratio = ft_get_ratio(cub);
	dimension.x = (WIDTH - ratio * cub.width) / 2;
	dimension.y = (HEIGHT - ratio * cub.height) / 2;
	img = ft_create_new_img(mlx.mlx_ptr, ratio * cub.width, ratio * cub.height);
	while (cub.map[vector.y])
	{
		vector.x = 0;
		ft_refile_minimap(img, cub, vector);
		vector.y++;
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.pointer,
		dimension.x, dimension.y);
	ft_render_player(mlx, pos, ratio, dimension);
	mlx_destroy_image(mlx.mlx_ptr, img.pointer);
}
