/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:35:43 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/25 13:51:10 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

typedef enum s_map_info {
	NO='NO',
	SO='SO',
	WE='WE',
	EA='EA',
	C='C',
	F='F'
}	t_map_info;

typedef struct s_map
{
	char	**map;
}	t_map;

#endif
