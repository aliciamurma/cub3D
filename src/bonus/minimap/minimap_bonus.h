/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:24:04 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/06 18:48:01 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMAP_BONUS_H
# define MINIMAP_BONUS_H

# include "vector_bonus.h"
# include "window_bonus.h"
# include "cub_bonus.h"

void	ft_render_minimap(t_window mlx, t_cub cub, t_vector pos);

#endif