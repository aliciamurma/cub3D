/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 20:51:09 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/21 21:05:09 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int handle_keydown(int key, t_game *game)
{
 // 13 - arriba
    if (key == 13)
    {
        if (game->map.map[(int)(game->player.pos.x + game->player.dir.x * 0.1)][(int)(game->player.pos.y)] == '0')
            game->player.pos.x += game->player.dir.x * 0.1;
        if (game->map.map[(int)(game->player.pos.x)][(int)(game->player.pos.y + game->player.dir.y * 0.1)] == '0')
            game->player.pos.y += game->player.dir.y * 0.1;
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
        if (game->map.map[(int)(game->player.pos.x + game->player.dir.x * 0.1)][(int)(game->player.pos.y)] == '0')
            game->player.pos.x -= game->player.dir.x * 0.1;
        if (game->map.map[(int)(game->player.pos.x)][(int)(game->player.pos.y + game->player.dir.y * 0.1)] == '0')
            game->player.pos.y -= game->player.dir.y * 0.1;
    }

/**
 * @brief Rotamos derecha
 * Cambiar 0.1 por speed rotation
 * 
 */
    if (key == 124)
    {
        double  actual_dir_x;
        double  actual_plane_x;

        actual_dir_x = game->player.dir.x;
        actual_plane_x = game->player.plane.x;
        game->player.dir.x = game->player.dir.x * cos(-0.1) - game->player.dir.y * sin (-0.1);
        game->player.dir.y = actual_dir_x * sin(-0.1) + game->player.dir.y * cos (-0.1);
        game->player.plane.x = game->player.plane.x * cos(-0.1) - game->player.plane.y * sin(-0.1);
        game->player.plane.y = actual_plane_x * sin(-0.1) + game->player.plane.y * cos(-0.1);
    }

/**
 * @brief Rotamos izquierda
 * Cambiar 0.1 por speed rotation
 * 
 */
    if (key == 123)
    {
        double  actual_dir_x;
        double  actual_plane_x;

        actual_dir_x = game->player.dir.x;
        actual_plane_x = game->player.plane.x;
        game->player.dir.x = game->player.dir.x * cos(0.1) - game->player.dir.y * sin (0.1);
        game->player.dir.y = actual_dir_x * sin(0.1) + game->player.dir.y * cos (0.1);
        game->player.plane.x = game->player.plane.x * cos(0.1) - game->player.plane.y * sin(0.1);
        game->player.plane.y = actual_plane_x * sin(0.1) + game->player.plane.y * cos(0.1);
    }
    if (key == 53) exit(0);
    // printf("input: %i\n", key);
    return 0;
}

int handle_keyup(int key, t_game *game)
{
    (void)game;
    printf("key: %i\n", key);
    return 0;
}

int handle_close(t_game *game)
{
    (void)game;
    exit(1);
    return 0;
}