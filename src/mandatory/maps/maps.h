/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:35:43 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/26 18:05:52 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

# include "game.h"
# include "textures.h"

// typedef enum s_map_info {
// 	NO='NO',
// 	SO='SO',
// 	WE='WE',
// 	EA='EA',
// 	C='C',
// 	F='F'
// }	t_map_info;

typedef struct s_map
{
	char	**cub;
	char	**map;
	int		width;
	int		height;
}	t_map;

// CHECK
void	ft_check_parameters(int argc, char *map);


// READ
void	ft_get_textures_colours(t_map map, t_texture texture);
void	ft_get_map(t_game *game);
void	ft_set_cub_info(t_game *game, char *cub);
void	ft_check_map(t_map map);

#endif
