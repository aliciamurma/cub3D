#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include "exit.h"
#include "cub3d.h"

typedef struct s_image
{
    void *pointer;
    // t_vector  size;
    char *pixels;
    int bits_per_pixel;
    int line_size;
    int endian;
} t_image;

void ft_porfin_printamos(t_window win, int x, int start_draw, int end_draw, int colour)
{
    int y;

    y = start_draw;
    while (y <= end_draw)
    {
        mlx_pixel_put(win.mlx_ptr, win.win_ptr, x, y, colour);
        y++;
    }
}

// void ft_print(t_game *game, int x, int start_draw, int end_draw, int colour)
// {
//     int y;

//     y = start_draw;
//     while (y <= end_draw)
//     {
//         mlx_pixel_put(pos->mlx_ptr, pos->win_ptr, x, y, colour);
//         y++;
//     }
// }

/**
 * @brief Recogemos la dirección del rayo
 *
 * @param game
 * @param x
 * @return t_vector
 */
t_vector ft_get_ray_dir(t_player player, int x)
{
    double camera_x;
    t_vector ray;

    camera_x = 2 * x / (double)WIDTH - 1;
    ray.x = player.dir.x + player.plane.x * camera_x;
    ray.y = player.dir.y + player.plane.y * camera_x;
    return (ray);
}

t_vector ft_get_ray_abs_distance(t_vector ray)
{
    t_vector delta;

    delta.x = fabs(1 / ray.x);
    delta.y = fabs(1 / ray.y);
    return (delta);
}

// 0 - step
// 1 - side
t_vector *ft_get_real_distance(t_player player, t_vector ray, t_vector delta, t_vector map)
{
    t_vector *distance;

    distance = malloc(sizeof(t_vector) * 2);
    if (ray.x < 0)
    {
        distance[0].x = -1;
        distance[1].x = (player.pos.x - map.x) * delta.x;
    }
    else
    {
        distance[0].x = 1;
        distance[1].x = (map.x + 1.0 - player.pos.x) * delta.x;
    }
    if (ray.y < 0)
    {
        distance[0].y = -1;
        distance[1].y = (player.pos.y - map.y) * delta.y;
    }
    else
    {
        distance[0].y = 1;
        distance[1].y = (map.y + 1.0 - player.pos.y) * delta.y;
    }
    return (distance);
}

// TODO crear struct raycast para esta funcion
int ft_render_map(t_game2 *game)
{
    int x;
    t_vector delta;
    t_vector ray;
    t_vector *distance;
    t_vector map;

    int hit;
    int side;
    double perp_wall_dist;
    int start_draw;
    int end_draw;
    int line_h;
    int colour;
    x = 1;
    mlx_clear_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
    while (x < WIDTH)
    {
        ray = ft_get_ray_dir(game->player, x);
        delta = ft_get_ray_abs_distance(ray);
        map.x = (int)game->player.pos.x;
        map.y = (int)game->player.pos.y;
        distance = ft_get_real_distance(game->player, ray, delta, map);

        // TODO apartir de aqui hay que refactorizar
        hit = 0;
        while (hit == 0)
        {
            if (distance[1].x < distance[1].y)
            {
                distance[1].x += delta.x;
                map.x += distance[0].x;
                side = 0;
            }
            else
            {
                distance[1].y += delta.y;
                map.y += distance[0].y;
                side = 1;
            }

            // NUESTRO JUGADOR SE HA CHOCADO CONTRA UNA PARED?
            // SI LA RESPUESTA ES SÍ, NO PUEDE MOVERSE, NO PUEDE ENTRAR EN EL BUCLE
            if (game->map.map[(int)map.x][(int)map.y] == '1')
                hit = 1;
        }
        hit = 1;
        // vamos a indicar la distancia a la que el jugador se va a quedar de una pared
        if (side == 0)
            perp_wall_dist = (map.x - game->player.pos.x + (1 - distance[0].x) / 2) / ray.x;
        else
            perp_wall_dist = (map.y - game->player.pos.y + (1 - distance[0].y) / 2) / ray.y;

        // TODO cambiar 800 por height ventana
        line_h = (int)(800 / perp_wall_dist);

        // Calculamos desde qué pixel hasta qué otro tenemos que pintar
        // Es como coger un trapecio y decir de dónde a dónde va
        start_draw = -line_h / 2 + 800 / 2;
        if (start_draw < 0)
            start_draw = 0;
        end_draw = line_h / 2 + 800 / 2;

        if (end_draw >= 800)
            end_draw = 800 - 1;

        if (game->map.map[(int)map.x][(int)map.y] == '1')
            colour = 0xFF0000;
        else
            colour = 0xFFFF00;
        // EL SIDE = 1 ES HACIA QUE LADO HA ENCONTRADO EL MURO
        // ES DECIR, NOS VAMOS A ENCONTRAR EL MURO EN DIRECCION X O EN DIRECCION Y?
        if (side == 1)
            colour = 0xCC0000;
        // PARA CADA X VAMOS A PRINTAR TODOS LOS ESPACIOS DE LA Y
        ft_porfin_printamos(game->mlx, x, start_draw, end_draw, colour);
        free(distance);
        x++;
    }
    return (0);
}

int handle_keydown(int key, t_game2 *game)
{
    // 13 - arriba
    if (key == 13)
    {
        game->player.pos.x -= 0.1;
    }
    // 2 - derecha
    if (key == 2)
    {
        game->player.pos.y += 0.1;
    }
    // 0 - izquierda
    if (key == 0)
    {
        game->player.pos.y -= 0.1;
    }
    // 1 - abajo
    if (key == 1)
    {
        game->player.pos.x += 0.1;
    }
    // Rotar dereacha
    if (key == 124)
    {
        if (game->player.plane.x > -1 && game->player.plane.x < 1)
            game->player.plane.x += 0.1;
        else
            game->player.plane.x -= 0.1;

        if (game->player.plane.y > -1 && game->player.plane.x < 1)
            game->player.plane.y += 0.1;
        else
            game->player.plane.y -= 0.1;
    }
    // Rotar izquierda
    if (key == 123)
    {
        if (game->player.plane.x > 0)
            game->player.plane.x -= 0.1;
        else
            game->player.plane.x += 0.1;
        if (game->player.plane.y > 0)
            game->player.plane.y -= 0.1;
        else
            game->player.plane.y += 0.1;
    }
    // printf("input: %i\n", key);
    return 1;
}

/**
 * @brief
 * mlx_init --> Inicializamos mlx
 * mlx_new_window --> Abrimos la ventana
 * mlx_new_image --> PARA QUE??
 * mlx_xpm_file_to_image y mlx_get_data_addr --> Carga la imagen
 * mlx_loop --> Crea un bucle para que no se cierre el juego
 * mlx_put_image_to_window --> Pone la imagen en la ventana
 *
 *  FOV = 2 * atan(0.66/1.0)=66.8 es adecuado para tiradores en primera persona
 * @return int
 */
int main(void)
{
    t_game2 game;

    game.map.map = malloc(sizeof(char *) * 25);

    game.map.map[0] = "111111111111111111111111";
    game.map.map[1] = "100000000000000000000001";
    game.map.map[2] = "100000000000000000000001";
    game.map.map[3] = "100000000011000000000001";
    game.map.map[4] = "100000000010000000010001";
    game.map.map[5] = "1000000000100N0000010001";
    game.map.map[6] = "100000000010000000010001";
    game.map.map[7] = "100000000011000000000001";
    game.map.map[8] = "100000000000000000000001";
    game.map.map[9] = "100000000000000000000001";
    game.map.map[10] = "100000000111111100000001";
    game.map.map[11] = "100000000000000000000001";
    game.map.map[12] = "100000000000000000000001";
    game.map.map[13] = "100000000000000000000001";
    game.map.map[14] = "100000000000000000000001";
    game.map.map[15] = "100000000000000000000001";
    game.map.map[16] = "100000000000000000000001";
    game.map.map[17] = "100000000000000000000001";
    game.map.map[18] = "100000000000000000000001";
    game.map.map[19] = "100000000000000000000001";
    game.map.map[20] = "100000000000000000000001";
    game.map.map[21] = "100000000000000000000001";
    game.map.map[22] = "100000000000000000000001";
    game.map.map[23] = "111111111111111111111111";
    game.map.map[24] = NULL;
    game.player.pos.x = 12;
    game.player.pos.y = 5;
    game.player.dir.x = -1;
    game.player.dir.y = 0;
    game.player.plane.x = 0;
    game.player.plane.y = 0.66;
    game.mlx.mlx_ptr = mlx_init();
    game.mlx.win_ptr = mlx_new_window(game.mlx.mlx_ptr, 800, 800, "MYCUB3D");
    mlx_loop_hook(game.mlx.mlx_ptr, &ft_render_map, &game);
    mlx_hook(game.mlx.win_ptr, 2, 0, handle_keydown, &game);
    mlx_loop(game.mlx.mlx_ptr);
    return (0);
}

// int	main(int argc, char **argv)
// {
// 	void	*mlx;
// 	t_game	game;

// 	check_parameters(argc, argv);
// 	get_cub_info(&game, argv);
// 	check_map(&game);
// 	mlx = mlx_init();
// 	mlx_new_window(mlx, 500, 500, "Hello world!");
// 	mlx_loop(mlx);
//     return (0);
// }
