
#include <math.h>
#include <mlx.h>
#include "raycast.h"
#include "window.h"
#include "game.h"

/**
 * @brief Recogemos la dirección del rayo
 *
 * @param game
 * @param x
 * @return t_vector
 */
static t_vector ft_get_ray_dir(t_player player, int x)
{
    double camera_x;
    t_vector ray;

    camera_x = 2 * x / (double)WIDTH - 1;
    ray.x = player.dir.x + player.plane.x * camera_x;
    ray.y = player.dir.y + player.plane.y * camera_x;
    return (ray);
}

static t_vector ft_get_ray_abs_distance(t_vector ray)
{
    t_vector delta;

    delta.x = fabs(1 / ray.x);
    delta.y = fabs(1 / ray.y);
    return (delta);
}

static t_vector ft_get_step_distance(t_vector ray)
{
    t_vector distance;

    if (ray.x < 0)
        distance.x = -1;
    else
        distance.x = 1;
    if (ray.y < 0)
        distance.y = -1;
    else
        distance.y = 1;
    return (distance);
}

static t_vector ft_get_side_distance(t_player player, t_vector ray, t_vector delta, t_int_vector map)
{
    t_vector distance;

    if (ray.x < 0)
        distance.x = (player.pos.x - map.x) * delta.x;
    else
        distance.x = (map.x + 1.0 - player.pos.x) * delta.x;
    if (ray.y < 0)
        distance.y = (player.pos.y - map.y) * delta.y;
    else
        distance.y = (map.y + 1.0 - player.pos.y) * delta.y;
    return (distance);
}

static void ft_set_distance(t_game *game, t_raycast *raycast)
{
    int hit;

    hit = 0;
    while (hit == 0)
    {
        if (raycast->side.x < raycast->side.y)
        {
            raycast->side.x += raycast->delta.x;
            raycast->map.x += raycast->step.x;
            raycast->side_2 = 0;
        }
        else
        {
            raycast->side.y += raycast->delta.y;
            raycast->map.y += raycast->step.y;
            raycast->side_2 = 1;
        }

        // NUESTRO JUGADOR SE HA CHOCADO CONTRA UNA PARED?
        // SI LA RESPUESTA ES SÍ, NO PUEDE MOVERSE, NO PUEDE ENTRAR EN EL BUCLE
        if (game->map.map[raycast->map.x][raycast->map.y] == '1')
            hit = 1;
    }
}

double ft_calc_perp_wall_dist(double pos, int map, double step, double ray)
{
    return (map - pos + (1 - step) / 2) / ray;
}

static int ft_get_start_draw(int line_h)
{
    int start_draw;

    start_draw = -line_h / 2 + WIDTH / 2;
    if (start_draw < 0)
        return (0);
    return (start_draw);
}

// TODO cambiar 800 por height ventana
static int ft_get_end_draw(int line_h)
{
    int end_draw;

    end_draw = line_h / 2 + WIDTH / 2;
    if (end_draw >= WIDTH)
        return (WIDTH - 1);
    return (end_draw);
}

static int ft_get_color(char object, int side_2)
{
    int colour;

    if (object == '1')
        colour = 0xFF0000;
    else
        colour = 0xFFFF00;
    // EL SIDE = 1 ES HACIA QUE LADO HA ENCONTRADO EL MURO
    // ES DECIR, NOS VAMOS A ENCONTRAR EL MURO EN DIRECCION X O EN DIRECCION Y?
    if (side_2 == 1)
        colour = 0xCC0000;
    return (colour);
}

t_raycast ft_get_ray(t_game *game, int x)
{
    t_raycast raycast;

    raycast.ray = ft_get_ray_dir(game->player, x);
    raycast.delta = ft_get_ray_abs_distance(raycast.ray);
    // TODO refactorizar a struct vector int o dos variables
    raycast.map.x = (int)game->player.pos.x;
    raycast.map.y = (int)game->player.pos.y;
    raycast.step = ft_get_step_distance(raycast.ray);
    raycast.side = ft_get_side_distance(game->player, raycast.ray, raycast.delta, raycast.map);
    ft_set_distance(game, &raycast);
    if (raycast.side_2 == 0)
        raycast.perp_wall_dist = ft_calc_perp_wall_dist(game->player.pos.x, raycast.map.x, raycast.step.x, raycast.ray.x);
    else
        raycast.perp_wall_dist = ft_calc_perp_wall_dist(game->player.pos.y, raycast.map.y, raycast.step.y, raycast.ray.y);
    raycast.line_h = (int)(WIDTH / raycast.perp_wall_dist);
    raycast.start_draw = ft_get_start_draw(raycast.line_h);
    raycast.end_draw = ft_get_end_draw(raycast.line_h);
    raycast.colour = ft_get_color(game->map.map[raycast.map.x][raycast.map.y], raycast.side_2);
    return (raycast);
}

void ft_print_ray(t_window win, int x, int start_draw, int end_draw, int colour)
{
    int y;

    y = start_draw;
    while (y <= end_draw)
    {
        mlx_pixel_put(win.mlx_ptr, win.win_ptr, x, y, colour);
        y++;
    }
}

int ft_render_map(t_game *game)
{
    int         x;
    t_raycast   raycast;

    mlx_clear_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
    x = 1;
    while (x < WIDTH)
    {
        raycast = ft_get_ray(game, x);
        ft_print_ray(game->mlx, x, raycast.start_draw, raycast.end_draw, raycast.colour);
        x++;
    }
    return (0);
}
