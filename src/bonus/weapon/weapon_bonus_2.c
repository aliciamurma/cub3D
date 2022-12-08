/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_bonus_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:26:28 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/08 13:26:43 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapon_bonus.h"

t_weapon	ft_init_stouker(void)
{
	t_weapon	weapon;

	weapon.damage = 8;
	weapon.have = false;
	weapon.is_active = false;
	weapon.quantity = 50;
	return (weapon);
}

t_weapon	ft_init_detonator(void)
{
	t_weapon	weapon;

	weapon.damage = 5;
	weapon.have = false;
	weapon.is_active = false;
	weapon.quantity = 1;
	return (weapon);
}

t_weapon_list	ft_init_weapons(void)
{
	t_weapon_list	weapons;

	weapons.fist = ft_init_fist();
	return (weapons);
}
