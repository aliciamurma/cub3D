/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:13:16 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/26 20:21:37 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

#include "game.h"
#include "maps.h"
#include "textures.h"

void	ft_set_cub_info(t_game *game, char *cub);
void	ft_get_textures(t_map map, t_texture texture);

#endif