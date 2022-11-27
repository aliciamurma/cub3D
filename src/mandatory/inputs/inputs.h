/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:45:55 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/27 23:46:32 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

# include "game.h"

typedef enum e_inputs
{
	UP = 13,
	RIGHT = 2,
	LEFT = 0,
	DOWN = 1,
	ROT_LEFT = 124,
	ROT_RIGHT = 123,
	ESC = 53
}	t_inputs;

int	handle_keydown(int key, t_game *game);
int	handle_keyup(int key, t_game *game);
int	handle_close(t_game *game);

#endif