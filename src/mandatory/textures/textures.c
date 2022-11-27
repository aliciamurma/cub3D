/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:05:45 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/27 19:06:22 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "textures.h"
#include "helpers.h"
#include <stdio.h>

#include <math.h>
#include "vector.h"
#include "window.h"
#include "game.h"

unsigned int	create_rgb(t_color color)
{
	return (((color.r & 0xff) << 16) + ((color.g & 0xff) << 8) + (color.b & 0xff));
}

// TODO valorar si seria necesario que el atoi mirase si no enviamos un numero y dar un error
unsigned int	ft_parse_color(char *input)
{
	char	**color_arr;
	char	*aux;
	t_color	color;
	int		i;

	color_arr = ft_split(input, ',');
	i = 0;
	while (color_arr[i])
	{
		aux = ft_strtrim(color_arr[i], " ");
		if (i == 0)
			color.r = ft_atoi(aux);
		if (i == 1)
			color.g = ft_atoi(aux);
		if (i == 2)
			color.b = ft_atoi(aux);
		free(aux);
		i++;
	}
	ft_free_matrix(color_arr);
	return (create_rgb(color));
}

int ft_get_texture_x(double side, t_vector position, double perp_wall_dist, t_vector ray)
{
    double wall_x;
    int text_x;

    if (side == 0)
        wall_x = position.y + perp_wall_dist * ray.y;
    else
        wall_x = position.x + perp_wall_dist * ray.x;
    wall_x -= floor(wall_x);
    text_x = (int)(wall_x * (double)64);
    if (side == 0 && ray.x > 0)
        text_x = 64 - text_x - 1;
    if (side == 1 && ray.y < 0)
        text_x = 64 - text_x - 1;
    return (text_x);
}
// En textures
double ft_get_texture_steep(double line_h)
{
    return (1.0 * 64 / line_h);
}
// En textures
double ft_get_texture_position(int start_draw, double line_h, double step)
{
    return ((start_draw - WIDTH / 2 + line_h / 2) * step);
}
// En textures
int ft_get_texture_y(double text_pos)
{
    return ((int)text_pos & (64 - 1));
}

int ft_get_color_image(t_image img, t_int_vector text)
{
    return (*(int *)(img.pixels + ((64 * text.y + text.x) * (img.bits_per_pixel / 8))));
}
