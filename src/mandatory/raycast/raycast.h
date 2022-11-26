#ifndef RAYCAST_H
# define RAYCAST_H

# include "vector.h"
# include "game.h"


// TODO -> poner una variable con el objeto que impacta(actor)
typedef struct s_raycast
{
    int             side_2;
    int             start_draw;
    int             end_draw;
    int             line_h;
    int             colour;
    double          perp_wall_dist;
    t_vector        delta;
    t_vector        ray;
    t_vector        step;
    t_vector        side;
    t_int_vector    map;

}	t_raycast;

t_raycast	ft_get_ray(t_game *game, int x);

#endif