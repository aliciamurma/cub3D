/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:05:34 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/08 20:24:55 by aramirez         ###   ########.fr       */
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

#define MARGIN_MIN 10

/**
 * @brief Printamos el personaje
 * 
 * @param mlx 
 * @param pos 
 * @param ratio 
 */
static void	ft_render_static_player(t_window mlx, t_vector pos, int ratio)
{
	int	x;
	int	y;

	x = MARGIN_MIN;
	y = MARGIN_MIN;
	while (x < 2 + MARGIN_MIN)
	{
		y = MARGIN_MIN;
		while (y < 2 + MARGIN_MIN)
		{
			mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, pos.y * ratio + x,
				pos.x * ratio + y, 0xFF0000);
			y++;
		}
		x++;
	}
}

/**
 * @brief Rellenamos los cuadrados con color
 * 
 * @param mlx 
 * @param vect 
 * @param c 
 * @param ratio 
 */
static void	ft_refile_squares(t_window mlx, t_int_vector vect, int c, int ratio)
{
	int	i;
	int	j;

	i = MARGIN_MIN;
	j = MARGIN_MIN;
	while (i < ratio + MARGIN_MIN)
	{
		j = MARGIN_MIN;
		while (j < ratio + MARGIN_MIN)
		{
			mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, vect.x * ratio + i,
				vect.y * ratio + j, c);
			j++;
		}
		i++;
	}
}

/**
 * @brief Obtenemos el ratio para el mini-minimapa
 * 
 * @param cub 
 * @return int 
 */
static int	ft_get_ratio_mini(t_cub cub)
{
	if (cub.width > cub.height)
		return ((WIDTH / 3 - MARGING / 3) / cub.width);
	else
		return ((HEIGHT / 3 - MARGING / 3) / cub.height);
}

/**
 * @brief Creamos el minimapa más pequeño
 * 
 * @param mlx 
 * @param cub 
 * @param pos 
 */
void	ft_render_static_minimap(t_window mlx, t_cub cub, t_vector pos)
{
	int				ratio;
	t_int_vector	vector;

	vector.y = 0;
	ratio = ft_get_ratio_mini(cub);
	while (cub.map[vector.y])
	{
		vector.x = 0;
		while (cub.map[vector.y][vector.x])
		{
			if (cub.map[vector.y][vector.x] == '0'
				|| ft_is_player(cub.map[vector.y][vector.x]))
				ft_refile_squares(mlx, vector, 0x0abd1c, ratio);
			else
				ft_refile_squares(mlx, vector, 0x02560b, ratio);
			vector.x++;
		}
		while (vector.x < cub.width)
		{
			ft_refile_squares(mlx, vector, 0x02560b, ratio);
			vector.x++;
		}
		vector.y++;
	}
	ft_render_static_player(mlx, pos, ratio);
}
