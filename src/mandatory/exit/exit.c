/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:29:44 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/26 17:02:42 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"
#include <stdlib.h>

/**
 * @brief Close Cub3D
 * 
 * @param value 
 */
void	ft_exit_cub3d(int value)
{
	ft_print_error(value);
	exit(value);
}
