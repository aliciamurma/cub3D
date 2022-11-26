/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:59:39 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/26 18:34:21 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "player.h"
# include "maps.h"
# include "window.h"
# include "textures.h"
# include "helpers.h"

typedef struct s_image
{
	void	*pointer;
	// t_vector  size;
	char	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}			t_image;

typedef struct s_game
{
    t_player    player;
    t_map       map;
    t_window    mlx;
    t_image     img;
	t_texture	texture;
}	t_game;

int		ft_game_loop(t_game *game);


// READ
void	ft_get_textures_colours(t_map map, t_texture texture);
void	ft_get_map(t_game *game);
void	ft_set_cub_info(t_game *game, char *cub);
void	ft_check_map(t_map map);

// HELPERS
void	*ft_malloc(size_t size, unsigned int q);
char	*get_next_line(int fd);
char	**ft_colour_split(char *str);
void	ft_free_matrix(char **str);
int		ft_strlen_map(char **str);
char	**ft_words_split(char *str);

#endif