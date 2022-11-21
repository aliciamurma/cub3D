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

#include <math.h>
#include "game.h"
#include "player.h"
#include "inputs.h"
#include <stdlib.h>
#include <stdio.h>

// TODO: implementar un sistema de movimento de direcciones con bool
int handle_keydown(int key, t_game *game)
{
    if (key == UP)
        game->player.movement.forward = true;
    if (key == DOWN)
        game->player.movement.backward = true;
    if (key == RIGHT)
        game->player.movement.right = true;
    if (key == LEFT)
        game->player.movement.left = true;
    if (key == ROT_LEFT)
        game->player.rotation.left = true;
    if (key == ROT_RIGHT)
        game->player.rotation.right = true;

    // if (key == UP)
    // {
    //     if (game->map.map[(int)(game->player.pos.x + game->player.dir.x * SPEED)][(int)(game->player.pos.y)] == '0')
    //         game->player.pos.x += game->player.dir.x * SPEED;
    //     if (game->map.map[(int)(game->player.pos.x)][(int)(game->player.pos.y + game->player.dir.y * SPEED)] == '0')
    //         game->player.pos.y += game->player.dir.y * SPEED;
    // }
    //     if (key == RIGHT)
    //     {
    //         if (game->map.map[(int)(game->player.pos.x + game->player.plane.x * SPEED)][(int)(game->player.pos.y)] == '0')
    //             game->player.pos.x += game->player.plane.x * SPEED;
    //         if (game->map.map[(int)(game->player.pos.x)][(int)(game->player.pos.y + game->player.plane.y * SPEED)] == '0')
    //             game->player.pos.y += game->player.plane.y * SPEED;
    //     }
    //     if (key == LEFT)
    //     {
    //         if (game->map.map[(int)(game->player.pos.x + game->player.plane.x * SPEED)][(int)(game->player.pos.y)] == '0')
    //             game->player.pos.x -= game->player.plane.x * SPEED;
    //         if (game->map.map[(int)(game->player.pos.x)][(int)(game->player.pos.y + game->player.plane.y * SPEED)] == '0')
    //             game->player.pos.y -= game->player.plane.y * SPEED;
    //     }
    //     if (key == DOWN)
    //     {
    //         if (game->map.map[(int)(game->player.pos.x + game->player.dir.x * SPEED)][(int)(game->player.pos.y)] == '0')
    //             game->player.pos.x -= game->player.dir.x * SPEED;
    //         if (game->map.map[(int)(game->player.pos.x)][(int)(game->player.pos.y + game->player.dir.y * SPEED)] == '0')
    //             game->player.pos.y -= game->player.dir.y * SPEED;
    //     }

    // /**
    //  * @brief Rotamos derecha
    //  * Cambiar 0.1 por speed rotation
    //  *
    //  */
    //     if (key == ROT_LEFT)
    //     {
    //         double  actual_dir_x;
    //         double  actual_plane_x;

    //         actual_dir_x = game->player.dir.x;
    //         actual_plane_x = game->player.plane.x;
    //         game->player.dir.x = game->player.dir.x * cos(-ROT_SPEED) - game->player.dir.y * sin (-ROT_SPEED);
    //         game->player.dir.y = actual_dir_x * sin(-ROT_SPEED) + game->player.dir.y * cos (-ROT_SPEED);
    //         game->player.plane.x = game->player.plane.x * cos(-ROT_SPEED) - game->player.plane.y * sin(-ROT_SPEED);
    //         game->player.plane.y = actual_plane_x * sin(-ROT_SPEED) + game->player.plane.y * cos(-ROT_SPEED);
    //     }

    // /**
    //  * @brief Rotamos izquierda
    //  * Cambiar 0.1 por speed rotation
    //  *
    //  */
    //     if (key == ROT_RIGHT)
    //     {
    //         double  actual_dir_x;
    //         double  actual_plane_x;

    //         actual_dir_x = game->player.dir.x;
    //         actual_plane_x = game->player.plane.x;
    //         game->player.dir.x = game->player.dir.x * cos(ROT_SPEED) - game->player.dir.y * sin (ROT_SPEED);
    //         game->player.dir.y = actual_dir_x * sin(ROT_SPEED) + game->player.dir.y * cos (ROT_SPEED);
    //         game->player.plane.x = game->player.plane.x * cos(ROT_SPEED) - game->player.plane.y * sin(ROT_SPEED);
    //         game->player.plane.y = actual_plane_x * sin(ROT_SPEED) + game->player.plane.y * cos(ROT_SPEED);
    //     }
    if (key == ESC)
        exit(0);
    return 0;
}

int handle_keyup(int key, t_game *game)
{
    if (key == UP)
        game->player.movement.forward = false;
    if (key == DOWN)
        game->player.movement.backward = false;
    if (key == RIGHT)
        game->player.movement.right = false;
    if (key == LEFT)
        game->player.movement.left = false;
    if (key == ROT_LEFT)
        game->player.rotation.left = false;
    if (key == ROT_RIGHT)
        game->player.rotation.right = false;

    return 0;
}

int handle_close(t_game *game)
{
    (void)game;
    exit(1);
    return 0;
}