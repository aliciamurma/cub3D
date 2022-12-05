/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:59:38 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/05 17:19:03 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_BONUS_H
# define TEXTURES_BONUS_H

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

typedef struct s_texture_x
{
	double	side;
	double	perp_wall_dist;
}	t_texture_x;

unsigned int	ft_parse_color(char *input);
int				ft_get_texture_x(
					t_texture_x texture_x,
					t_vector position,
					t_vector ray, int text_height);
int				ft_get_texture_y(double text_pos, int text_height);
double			ft_get_texture_steep(double line_h, int text_height,
					int line_size);
double			ft_get_texture_position(
					int start_draw, double line_h, double step);
int				ft_get_color_image(
					t_image img, t_int_vector text, int text_height);
#endif
