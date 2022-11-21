#include "game.h"
#include <stdio.h>
#include <stdlib.h>

int handle_keydown(int key, t_game *game)
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