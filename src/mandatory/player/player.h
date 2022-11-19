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

typedef struct t_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_player
{
	t_vector	dir;
	t_vector	pos;
	t_vector	plane;
}	t_player;

#endif
