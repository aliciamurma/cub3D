/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_bonus_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:33:17 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/08 13:26:34 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapon_bonus.h"

t_weapon	ft_init_fist(void)
{
	t_weapon	weapon;

	weapon.damage = 1;
	weapon.have = true;
	weapon.is_active = false;
	weapon.quantity = -1;
	return (weapon);
}

t_weapon	ft_init_pistol(void)
{
	t_weapon	weapon;

	weapon.damage = 2;
	weapon.have = true;
	weapon.is_active = true;
	weapon.quantity = 25;
	return (weapon);
}

t_weapon	ft_init_rifle(void)
{
	t_weapon	weapon;

	weapon.damage = 3;
	weapon.have = false;
	weapon.is_active = false;
	weapon.quantity = 0;
	return (weapon);
}

t_weapon	ft_init_packered(void)
{
	t_weapon	weapon;

	weapon.damage = 3;
	weapon.have = false;
	weapon.is_active = false;
	weapon.quantity = 50;
	return (weapon);
}

t_weapon	ft_init_repeater(void)
{
	t_weapon	weapon;

	weapon.damage = 5;
	weapon.have = false;
	weapon.is_active = false;
	weapon.quantity = 50;
	return (weapon);
}
