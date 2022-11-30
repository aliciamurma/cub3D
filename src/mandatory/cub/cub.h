/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:51:17 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/30 11:51:35 by amurcia-         ###   ########.fr       */
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

char			**ft_get_cub(char *cub_raw);
t_cub			ft_parse_cub(void *mlx, char *cub_raw);
t_texture		ft_parse_cub_textures(void *mlx, char **cub);
void			ft_parse_map(char **map, int height, int width);
t_vector		ft_get_player_pos(char **map);
t_vector		ft_get_player_dir(char **map);

#endif
