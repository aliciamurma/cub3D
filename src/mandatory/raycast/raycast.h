#ifndef RAYCAST_H
# define RAYCAST_H

# include "vector.h"
# include "cub3d.h"

typedef struct s_raycast
{
    t_vector    delta;
    t_vector    ray;
    t_vector    step;
    t_vector    side;
    t_vector    map;

    int         side_2;
    int         start_draw;
    int         end_draw;
    int         line_h;
    int         colour;
    double      perp_wall_dist;

}	t_raycast;

int         ft_render_map(t_game2 *game);
#endif