/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_weapon_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:59:11 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/06 17:49:54 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "window_bonus.h"
#include "render_bonus.h"
#include "images_bonus.h"

void	ft_render_weapon(t_window mlx, char *path)
{
	int		ratio;
	t_image	img_w;
	t_image	img;

	ratio = WIDTH / 2;
	img_w = ft_create_img(mlx.mlx_ptr, path);
	img = ft_resize_img(mlx.mlx_ptr, img_w, ratio);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.pointer,
		(WIDTH / 2 - ratio / 2), HEIGHT - ratio);
}
