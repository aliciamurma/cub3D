
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include "game.h"
#include "player.h"

bool ft_can_move(char **map, double pos_x, double pos_y)
{
    if (map[(int)pos_x][(int)pos_y] == '0')
        return (true);
    return (false);
}

static double ft_get_new_position(double dir)
{
    return (dir * SPEED);
}

void ft_move_forward(t_player *player, char **map)
{
    double new_pos_x;
    double new_pos_y;

    new_pos_x = ft_get_new_position(player->dir.x);
    new_pos_y = ft_get_new_position(player->dir.y);
    if (ft_can_move(map, new_pos_x + player->pos.x, player->pos.y))
        player->pos.x += new_pos_x;
    if (ft_can_move(map, player->pos.x, new_pos_y + player->pos.y))
        player->pos.y += new_pos_y;
}

void ft_move_backward(t_player *player, char **map)
{
    double new_pos_x;
    double new_pos_y;

    new_pos_x = ft_get_new_position(player->dir.x);
    new_pos_y = ft_get_new_position(player->dir.y);
    if (ft_can_move(map, new_pos_x + player->pos.x, player->pos.y))
        player->pos.x -= new_pos_x;
    if (ft_can_move(map, player->pos.x, new_pos_y + player->pos.y))
        player->pos.y -= new_pos_y;
}

void ft_move_left(t_player *player, char **map)
{
    double new_pos_x;
    double new_pos_y;

    new_pos_x = ft_get_new_position(player->plane.x);
    new_pos_y = ft_get_new_position(player->plane.y);
    if (ft_can_move(map, new_pos_x + player->pos.x, player->pos.y))
        player->pos.x -= new_pos_x;
    if (ft_can_move(map, player->pos.x, new_pos_y + player->pos.y))
        player->pos.y -= new_pos_y;
}

void ft_move_right(t_player *player, char **map)
{
    double new_pos_x;
    double new_pos_y;

    new_pos_x = ft_get_new_position(player->plane.x);
    new_pos_y = ft_get_new_position(player->plane.y);
    if (ft_can_move(map, new_pos_x + player->pos.x, player->pos.y))
        player->pos.x += new_pos_x;
    if (ft_can_move(map, player->pos.x, new_pos_y + player->pos.y))
        player->pos.y += new_pos_y;
}

// static double ft_calc_dir_rotation()
// {

// }

// static double ft_calc_plane_rotation()
// {

// }
void ft_rotate_left(t_player *player)
{
    double actual_dir_x;
    double actual_plane_x;

    actual_dir_x = player->dir.x;
    actual_plane_x = player->plane.x;
    player->dir.x = player->dir.x * cos(-ROT_SPEED) - player->dir.y * sin(-ROT_SPEED);
    player->dir.y = actual_dir_x * sin(-ROT_SPEED) + player->dir.y * cos(-ROT_SPEED);
    player->plane.x = player->plane.x * cos(-ROT_SPEED) - player->plane.y * sin(-ROT_SPEED);
    player->plane.y = actual_plane_x * sin(-ROT_SPEED) + player->plane.y * cos(-ROT_SPEED);
}

void ft_rotate_right(t_player *player)
{
    double actual_dir_x;
    double actual_plane_x;

    actual_dir_x = player->dir.x;
    actual_plane_x = player->plane.x;
    player->dir.x = player->dir.x * cos(ROT_SPEED) - player->dir.y * sin(ROT_SPEED);
    player->dir.y = actual_dir_x * sin(ROT_SPEED) + player->dir.y * cos(ROT_SPEED);
    player->plane.x = player->plane.x * cos(ROT_SPEED) - player->plane.y * sin(ROT_SPEED);
    player->plane.y = actual_plane_x * sin(ROT_SPEED) + player->plane.y * cos(ROT_SPEED);
}