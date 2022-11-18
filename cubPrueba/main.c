/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:56:01 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/18 08:30:39 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testing.h"


void    ft_porfin_printamos(t_pos *pos, int x, int start_draw, int end_draw, int colour)
{
    int y;
 
    printf("START DRAW IS %d\nAND END DRAW %d\n", start_draw, end_draw);
    y = start_draw;
    while (y <= end_draw)
    {
        printf("entro\n");
        mlx_pixel_put(pos->mlx_ptr, pos->win , x, y, colour);
        y++;
    }
}  

/**
 * @brief 
 * side_dist_x es la distancia del rayo desde la posición del jugador hasta lo que se ha chocado
 * 
 * @param pos 
 */
int  my_loop(t_pos *pos)
{
    double camera_x;
    double ray_dir_x;
    double ray_dir_y;
        
    // distancia del rayo desde la posición del jugador hasta lo que se ha chocado
    double side_dist_x;
    double side_dist_y;

    int map_x;
    int map_y;

    // longitud del rayo de una posición a otra
    double delta_dist_x;
    double delta_dist_y;
    
    // es la distancia a la que se queda el personaje de una pared
    double perp_wall_dist;

    // la dirección en la que se va a mover el jugador
    int step_x;
    int step_y;

    // Para saber si nos estamos chocando contra una pared
    int hit;
    // Para saber si mira a N, S, W, E
    int side;

    // Altura de la línea que se imprime por pantalla
    int line_h;

    // El sitio en el que vamos a comenzar y acabar de rellenar de píxeles
    int start_draw;
    int end_draw;

    int colour;
    int colour_n;
    int colour_s;
    int colour_e;
    int colour_w;


    int x;
 
    x = 0 ;
    colour_n = 0xFF000;
    colour_s = 0x0FF00;
    colour_e = 0x00FF0;
    colour_w = 0xFFFFF;
    while (x < pos->wid)
    {
        // Cogemos la dirección del rayo
        camera_x = 2 * x / (double)pos->wid - 1 ;
        ray_dir_x = pos->dir_x + pos->plane_x * camera_x;
        ray_dir_y = pos->dir_y + pos->plane_y * camera_x;

        map_x = (int)pos->pos_x;
        map_y = (int)pos->pos_y;

        // fabs devuelve el valor absoluto de lo que le pasamos, porque no puede ser una distancia negativa
        delta_dist_x = fabs(1 / ray_dir_x);
        delta_dist_y = fabs(1 / ray_dir_y);
        hit = 0;
        if (ray_dir_x < 0 )
        {
            step_x = - 1 ;
            side_dist_x = (pos->pos_x - map_x) * delta_dist_x;
        }
        else
        {
            step_x = 1 ;
            side_dist_x = (map_x + 1.0 - pos->pos_x) * delta_dist_x;
        }
        // si la dirección del rayo en el eje Y es MENOR a 0, significa que nuestro personaje ha tirado un paso para atrás
        if (ray_dir_y < 0 )
        {
            step_y = - 1 ;
            side_dist_y = (pos->pos_y - map_y) * delta_dist_y;
        }
        // si la dirección del rayo en el eje Y es MAYOR a 0, significa que nuestro personaje ha tirado un paso para adelante
        else
        {
            step_y = 1 ;
            side_dist_y = (map_y + 1.0 - pos->pos_y) * delta_dist_y;
        }

    // LO QUE VAMOS A HACER AHORA ES SOLAMENTE EN CASO DE QUE CUANDO NUESTRO
    // PERSONAJE SE MUEVA, NO SE CHOQUE CONTRA LA PARED. SI NO, NO LE VAMOS A PERMITIR MOVERSE
    // ESTE BUCLE SIRVE PARA MOVERTE A OTRA POSICIÓN DEL MAPA, TANTO EN X COMO EN Y
    // ES COMO COGER TU X Y SUMARLE LA DISTANCIA QUE TE HAS MOVIDO
        while (hit == 0 )
        {
            if (side_dist_x < side_dist_y)
            {
                side_dist_x += side_dist_x;
                map_x += step_x;
                side = 0;
            }
            else
            {
                side_dist_y += side_dist_y;
                map_y += step_y;
                side = 1;
            }

            // NUESTRO JUGADOR SE HA CHOCADO CONTRA UNA PARED?
            // SI LA RESPUESTA ES SÍ, NO PUEDE MOVERSE, NO PUEDE ENTRAR EN EL BUCLE
            if (pos->map[map_x][map_y] > 1)
                hit = 1;
        }
        // vamos a indicar la distancia a la que el jugador se va a quedar de una pared
        if (side == 0)
            perp_wall_dist = (map_x - pos->pos_x + (1 - step_x) / 2) / ray_dir_x;
        else
            perp_wall_dist = (map_y - pos->pos_y + (1 - step_y) / 2) / ray_dir_y;
        line_h = ( int )(pos->hei/ perp_wall_dist);
        printf("perp_wall_dist is %f\n", perp_wall_dist);

        // Calculamos desde qué pixel hasta qué otro tenemos que pintar
        // Es como coger un trapecio y decir de dónde a dónde va
        start_draw = -line_h / 2 + pos->hei / 2;
        if (start_draw < 0)
            start_draw = 0 ;
        end_draw = line_h / 2 + pos->hei / 2;
        printf("END DRAW IS %d\n", end_draw);
        printf("LINE_H IS %d\n", line_h);
        printf("HEIGHT IS %d\n", pos->hei);
        if (end_draw >= pos->hei)
            end_draw = pos->hei - 1;
        
        if (pos->map[map_x][map_y] == 1)
            colour = 0xFF0000;
        if (side == 1)
            colour = colour / 2 ;
        // PARA CADA X VAMOS A PRINTAR TODOS LOS ESPACIOS DE LA Y
        ft_porfin_printamos(pos, x, start_draw, end_draw, colour);        
        x++;
    }
    return (0);
}
int  main (int argc, char **argv)
{
    t_pos   pos;
    t_game  game;

	check_parameters(argc, argv);
	get_cub_info(&game, argv);
	check_map(&game);
    pos.pos_x = game.player_x;
    pos.pos_y = game.player_y;
    pos.dir_x = -1;
    pos.dir_y = 0;
    pos.move_speed = 0.05 ;
    pos.rot_speed = 0.05 ;
    pos.wid = game.width;
    pos.hei = game.height;
    pos.map = game.map;
    pos.mlx_ptr = mlx_init();
    // printf(" WIDTH IS %d\n AND H IS %d\n", game.width, game.height);
    pos.win_ptr = mlx_new_window(pos.mlx_ptr , game.width * 50, game.height * 50, "MYCUB3D");
    mlx_loop_hook(pos.mlx_ptr, &my_loop, &pos);
    mlx_loop(pos.mlx_ptr);
    return (0);
}
