/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:29:31 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/19 11:58:36 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H
# define SPEED 0.05
# define ROT_SPEED 0.02

# include <stdbool.h>
# include "vector.h"

typedef struct s_movement
{
    bool forward;
    bool backward;
    bool left;
    bool right;
} t_movement;

typedef struct s_rotation
{
    bool left;
    bool right;
} t_rotation;

typedef struct s_player
{
    t_vector dir;
    t_vector pos;
    t_vector plane;
    t_movement movement;
    t_rotation rotation;
} t_player;

void ft_move_forward(t_player *player, char **map);
void ft_move_backward(t_player *player, char **map);
void ft_move_left(t_player *player, char **map);
void ft_move_right(t_player *player, char **map);
void ft_rotate_left(t_player *player);
void ft_rotate_right(t_player *player);
#endif
