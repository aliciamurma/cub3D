/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:51:17 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/27 17:53:49 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "textures.h"

typedef enum e_texture_types
{
	NO = 1,
	SO = 2,
	WE = 3,
	EA = 4,
	F = 5,
	C = 6
}	t_texture_types;

typedef struct s_cub
{
	int			width;
	int			height;
	char		**map;
	t_texture	textures;
}	t_cub;

// void	ft_check_map(t_cub *map);
// void	ft_get_cub(t_cub *map, t_player *player);

char		**ft_get_cub(char *cub_raw);
t_cub		ft_parse_cub(void *mlx, char *cub_raw);
t_texture	ft_parse_cub_textures(void *mlx, char **cub);

#endif
