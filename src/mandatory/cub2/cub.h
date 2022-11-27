/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:13:16 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/27 12:49:04 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

#include "game.h"
#include "cub.h"
#include "textures.h"

void	ft_set_cub_info(t_game *game, char *cub);
void	ft_get_textures(t_cub *map, t_texture *texture);

#endif