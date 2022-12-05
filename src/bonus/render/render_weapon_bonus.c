/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_weapon_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:59:11 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/05 18:08:57 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include "window_bonus.h"
#include "render_bonus.h"
#include "images_bonus.h"

void	ft_render_weapon(void *mlx, void *win)
{
	t_image	img;
	static int n = 0;
	// t_int_vector v;


	n++;
	img = ft_create_img(mlx, "./src/assets/weapons/new_weapon.xpm");
	printf("img: %i\n", img.width/2);
	printf("wind: %i\n", WIDTH/2);
	printf("start: %i\n", WIDTH/2 - img.width/2);

	mlx_put_image_to_window(mlx, win,
		img.pointer, WIDTH / 2 - img.width / 2, HEIGHT - img.height);
}
