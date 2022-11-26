#ifndef TEXTURES_H
# define TEXTURES_H

# include "vector.h"
# include "game.h"

int ft_get_texture_x(double side, t_vector position, double perp_wall_dist, t_vector ray);
double ft_get_texture_steep(double line_h);
double ft_get_texture_position(int start_draw, double line_h, double step);
int ft_get_texture_y(double text_pos);
int ft_get_color_image(t_image img, t_int_vector text);

#endif