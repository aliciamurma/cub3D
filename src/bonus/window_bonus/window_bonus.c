/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 23:56:32 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/05 17:18:01 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "window_bonus.h"

/**
 * @brief Crea una ventana a partir de la libreria mlx
 * 
 * @return t_window 
 */
t_window	ft_new_window(void)
{
	t_window	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr,
			WIDTH, HEIGHT, NAME_WIN);
	return (mlx);
}
