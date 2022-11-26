/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:35:43 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/26 20:47:37 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

# include "game.h"

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

void	ft_check_map(t_map map);
void	ft_get_map(t_game *game);

#endif
