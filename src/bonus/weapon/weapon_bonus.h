/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:17:35 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/06 16:38:03 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_BONUS_H
# define WEAPON_BONUS_H

# include <stdbool.h>
# include "images_bonus.h"

typedef enum e_weapon_t
{
	DETONATOR,
	FIST,
	PACKERED,
	PISTOL,
	REPEATER,
	RIFLE,
	STOUKER
}	t_weapon_t;

typedef struct s_weapon
{
	int		quantity;
	bool	have;
	bool	is_active;
	int		damage;
	t_image	sprite;
}	t_weapon;

typedef struct s_weapon_list
{
	t_weapon	fist;
	t_weapon	pistol;
	t_weapon	rifle;
	t_weapon	packered;
	t_weapon	repeater;
	t_weapon	stouker;
	t_weapon	detonator;
}	t_weapon_list;

#endif