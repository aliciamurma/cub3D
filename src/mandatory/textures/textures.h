/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:59:38 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/27 19:12:21 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "images.h"
# include "vector.h"

typedef struct s_texture
{
	t_image			north;
	t_image			south;
	t_image			east;
	t_image			west;
	unsigned int	floor;
	unsigned int	ceil;
}	t_texture;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

unsigned int	ft_parse_color(char *input);
int				ft_get_texture_x(double side, t_vector position, double perp_wall_dist, t_vector ray);
double			ft_get_texture_steep(double line_h);
double			ft_get_texture_position(int start_draw, double line_h, double step);
int				ft_get_texture_y(double text_pos);
int				ft_get_color_image(t_image img, t_int_vector text);

#endif
