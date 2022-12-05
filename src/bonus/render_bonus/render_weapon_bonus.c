/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_weapon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:59:11 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/05 17:06:27 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "window.h"
#include "render.h"
#include "images.h"

void	ft_render_weapon(void *mlx)
{
	t_image	img;

	printf("1\n");
	img = ft_create_img(mlx, "./src/assets/weapons/weapon.xpm");
	printf("%i\n", img.width);
}
