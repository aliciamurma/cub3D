/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:33:17 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/06 16:45:09 by aramirez         ###   ########.fr       */
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
