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
#include "exit.h"

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
    if (key == ESC)
        exit_cub3d(3);
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
    exit_cub3d(3);
    return 0;
}