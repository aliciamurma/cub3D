/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:53:04 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/28 16:00:27 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "vector.h"
#include "window.h"
#include "game.h"
#include "textures.h"

/**
 * @brief Obtiene la posicion en x de la textura donde queremos mirar el color
 * 
 * @param side 
 * @param position 
 * @param perp_wall_dist 
 * @param ray 
 * @return int 
 */
int	ft_get_texture_x(
	t_texture_x texture_x, t_vector position, t_vector ray, int text_height)
{
	double	wall_x;
	int		text_x;

	if (texture_x.side == 0)
		wall_x = position.y + texture_x.perp_wall_dist * ray.y;
	else
		wall_x = position.x + texture_x.perp_wall_dist * ray.x;
	wall_x -= floor(wall_x);
	text_x = (int)(wall_x * (double)text_height);
	if (texture_x.side == 0 && ray.x > 0)
		text_x = text_height - text_x - 1;
	if (texture_x.side == 1 && ray.y < 0)
		text_x = text_height - text_x - 1;
	return (text_x);
}

/**
 * @brief Obtiene cuanto avanza la posicion de la textura por paso
 * 
 * @param line_h 
 * @return double 
 */
double	ft_get_texture_steep(double line_h, int text_height)
{
	return (1.0 * text_height / line_h);
}

/**
 * @brief Obtiene la posicion que queremos pintar de la textura
 * 
 * @param start_draw 
 * @param line_h 
 * @param step 
 * @return double 
 */
double	ft_get_texture_position(int start_draw, double line_h, double step)
{
	return ((start_draw - WIDTH / 2 + line_h / 2) * step);
}

/**
 * @brief Obtenemos la posicion en y de la textura en el punto 
 * que queremos pintar
 * 
 * @param text_pos 
 * @return int 
 */
int	ft_get_texture_y(double text_pos, int text_height)
{
	return ((int)text_pos & (text_height - 1));
}

/**
 * @brief Obtenemos el color de la imagen en el punto que estamos buscando
 * 
 * @param img 
 * @param text 
 * @return int 
 */
int	ft_get_color_image(t_image img, t_int_vector text, int text_height)
{
	return (*(int *)(img.pixels
		+ ((text_height * text.y + text.x) * (img.bits_per_pixel / 8))));
}
