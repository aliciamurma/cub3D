/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:31:28 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/30 11:51:28 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define SPEED 0.06
# define ROT_SPEED 0.02

# include <stdbool.h>
# include "vector.h"

typedef struct s_movement
{
	bool	forward;
	bool	backward;
	bool	left;
	bool	right;
	float	speed;
}	t_movement;

typedef struct s_rotation
{
	bool	left;
	bool	right;
	float	speed;
}	t_rotation;

typedef struct s_player
{
	t_vector	dir;
	t_vector	pos;
	t_vector	plane;
	t_movement	movement;
	t_rotation	rotation;
}	t_player;

// t_player	ft_new_player(void);
t_player	ft_new_player(char **map);
bool		ft_can_move(char **map, double pos_x, double pos_y);
double		ft_get_new_position(double dir);
void		ft_move_forward(t_player *player, char **map);
void		ft_move_backward(t_player *player, char **map);
void		ft_move_left(t_player *player, char **map);
void		ft_move_right(t_player *player, char **map);
void		ft_rotate_left(t_player *player);
void		ft_rotate_right(t_player *player);

#endif