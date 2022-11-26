
#include "game.h"
#include "raycast.h"
#include "window.h"
#include <math.h>
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

# define HEI_TEX 64
# define WID_TEX 64

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

static t_vector ft_get_side_distance(t_player player, t_vector ray,
                                     t_vector delta, t_int_vector map)
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
    return ((map - pos + (1 - step) / 2) / ray);
}

static int ft_get_start_draw(int line_h)
{
    int start_draw;

    start_draw = -line_h / 2 + WIDTH / 2;
    if (start_draw < 0)
        return (0);
    return (start_draw);
}

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
    // EL SIDE = 1 ES HACIA QUE LADO HA ENCONTRADO EL MURO
    // ES DECIR, NOS VAMOS A ENCONTRAR EL MURO EN DIRECCION X O EN DIRECCION Y?
    if (side_2 == 1)
        colour = 0xAA0000;
    return (colour);
}

t_raycast ft_get_ray(t_game *game, int x)
{
    t_raycast raycast;

    raycast.ray = ft_get_ray_dir(game->player, x);
    raycast.delta = ft_get_ray_abs_distance(raycast.ray);
    raycast.map.x = (int)game->player.pos.x;
    raycast.map.y = (int)game->player.pos.y;
    raycast.step = ft_get_step_distance(raycast.ray);
    raycast.side = ft_get_side_distance(game->player, raycast.ray,
                                        raycast.delta, raycast.map);
    ft_set_distance(game, &raycast);
    if (raycast.side_2 == 0)
        raycast.perp_wall_dist = ft_calc_perp_wall_dist(game->player.pos.x,
                                                        raycast.map.x,
                                                        raycast.step.x,
                                                        raycast.ray.x);
    else
        raycast.perp_wall_dist = ft_calc_perp_wall_dist(game->player.pos.y,
                                                        raycast.map.y,
                                                        raycast.step.y,
                                                        raycast.ray.y);
    raycast.line_h = (int)(WIDTH / raycast.perp_wall_dist);
    raycast.start_draw = ft_get_start_draw(raycast.line_h);
    raycast.end_draw = ft_get_end_draw(raycast.line_h);
    raycast.colour = ft_get_color(game->map.map[raycast.map.x][raycast.map.y],
                                  raycast.side_2);
    return (raycast);
}

void ft_print_ray(t_window win, int x, int start_draw, int end_draw,
                  int colour, t_game *game, t_raycast raycast)
{
    int y;
    int pixel;
    int d;
    void *img_r;
    t_image img2;

    d = 64;
    img_r = mlx_xpm_file_to_image(game->mlx.mlx_ptr,//cargamos la textur ay la guardamos en img2
        "./src/assets/textures/west.xpm", &d, &d);
    img2.pixels = mlx_get_data_addr(img_r, &img2.bits_per_pixel,
        &img2.line_size, &img2.endian);
    (void)win;
    (void)colour;
    (void)raycast;
    y = 0;
    double wallX;
    if(raycast.side_2 == 0) wallX = game->player.pos.y + raycast.perp_wall_dist * raycast.ray.y;
    else wallX = game->player.pos.x + raycast.perp_wall_dist * raycast.ray.x;
    wallX -= floor((wallX));
    int textX = (int)(wallX * (double)64);
    if (raycast.side_2 == 0 && raycast.ray.x > 0) textX = 64 - textX -1;
    if (raycast.side_2 == 1 && raycast.ray.y < 0) textX = 64 - textX -1;
    while (y < start_draw)
    {
        pixel = (y * game->img.line_size) + (x * 4);
        game->img.pixels[pixel + 0] = (unsigned int)(0x0000FF) & 0xFF;
        game->img.pixels[pixel + 1] = (unsigned int)(0x0000FF >> 8) & 0xFF;
        game->img.pixels[pixel + 2] = (unsigned int)(0x0000FF >> 16) & 0xFF;
        game->img.pixels[pixel + 3] = (unsigned int)(0x0000FF >> 24);
        // mlx_pixel_put(win.mlx_ptr, win.win_ptr, x, y, 0x0000FF);
        y++;
    }
    // y = start_draw;
   //int line_height = (int)(HEIGHT / raycast.perp_wall_dist);
    double step = 1.0 * 64 / raycast.line_h;
    double textPos = (start_draw - WIDTH / 2 + raycast.line_h / 2) * step;
    while (y < end_draw)
    {
        if (y >= HEIGHT)
            return;
        // colour = (WIDTH * HEIGHT + 64);
        int textY = (int)textPos & (64 - 1);
        textPos += step;
     
        colour = *(int *)(img2.pixels + ((64 * textY + textX) * (img2.bits_per_pixel / 8)));
        pixel = (y * game->img.line_size) + (x * 4);
        game->img.pixels[pixel + 0] = (int)(colour);
        game->img.pixels[pixel + 1] = (int)(colour >> 8);
        game->img.pixels[pixel + 2] = (int)(colour >> 16);
        game->img.pixels[pixel + 3] = (int)(colour >> 24);

        // game->img.pixels[pixel + 0] = (unsigned int)(colour);
        // game->img.pixels[pixel + 1] = (unsigned int)(colour >> 8);
        // game->img.pixels[pixel + 2] = (unsigned int)(colour >> 16);
        // game->img.pixels[pixel + 3] = (unsigned int)(colour >> 24);
        // mlx_pixel_put(img2.mlx_ptr, win.win_ptr, x, y, colour);
        y++;
    }
    while (y < HEIGHT)
    {
        pixel = (y * game->img.line_size) + (x * 4);
        game->img.pixels[pixel + 0] = (unsigned int)(0x00FF00) & 0xFF;
        game->img.pixels[pixel + 1] = (unsigned int)(0x00FF00 >> 8) & 0xFF;
        game->img.pixels[pixel + 2] = (unsigned int)(0x00FF00 >> 16) & 0xFF;
        game->img.pixels[pixel + 3] = (unsigned int)(0x00FF00 >> 24);
        // mlx_pixel_put(win.mlx_ptr, win.win_ptr, x, y, 0x00FF00);
        y++;
    }
    // free(img_r);
}

// void	ft_create_image(void)
// {
// 	t_image	img;

// 	img.pointer = mlx_new_image(mlx, HEIGHT, WIDTH);
// 	img.pixels = mlx_get_data_addr(img.pointer, &img.bits_per_pixel,
// 			&img.line_size, &img.endian);
//     return ();
// }

int ft_render_map(t_game *game)
{
    int x;
    t_raycast raycast;
    static int a;

    a = 0;
    if (a != 0)
        mlx_destroy_image(game->mlx.mlx_ptr, game->img.pointer);
    mlx_clear_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
    game->img.pointer = mlx_new_image(game->mlx.mlx_ptr, WIDTH, HEIGHT);
    game->img.pixels = mlx_get_data_addr(game->img.pointer,
                                         &game->img.bits_per_pixel,
                                         &game->img.line_size,
                                         &game->img.endian);
    x = 1;
    while (x < WIDTH)
    {
        raycast = ft_get_ray(game, x);
        ft_print_ray(game->mlx, x, raycast.start_draw, raycast.end_draw,
                     raycast.colour, game, raycast);
        x++;
    }
    mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
                            game->img.pointer, 0, 0);
    a = 1;
    return (0);
}
