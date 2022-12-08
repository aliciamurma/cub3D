/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 12:05:34 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/08 13:00:41 by amurcia-         ###   ########.fr       */
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

static void	ft_render_static_player(t_window mlx, t_vector pos, int ratio)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < 2)
	{
		y = 0;
		while (y < 2)
		{
			mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, pos.y * ratio + x,
				pos.x * ratio + y, 0xFFFFFF);
			y++;
		}
		x++;
	}
}

static void	ft_refile_squares(t_window mlx, t_int_vector vect, int c, int ratio)
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
			mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, vect.x * ratio + i,
				vect.y * ratio + j, c);
			j++;
		}
		i++;
	}
}

static int	ft_get_ratio_mini(t_cub cub)
{
	if (cub.width > cub.height)
		return ((WIDTH / 3 - MARGING / 3) / cub.width);
	else
		return ((HEIGHT / 3 - MARGING / 3) / cub.height);
}

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
				ft_refile_squares(mlx, vector, 0xFF0000, ratio);
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
