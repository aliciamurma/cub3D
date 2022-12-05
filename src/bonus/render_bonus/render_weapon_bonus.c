/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_weapon_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:59:11 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/05 17:19:14 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "window_bonus.h"
#include "render_bonus.h"
#include "images_bonus.h"

void	ft_render_weapon(void *mlx)
{
	t_image	img;

	printf("1\n");
	img = ft_create_img(mlx, "./src/assets/weapons/weapon.xpm");
	printf("%i\n", img.width);
}
