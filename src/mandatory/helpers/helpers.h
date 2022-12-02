/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:16:19 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/02 20:00:34 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include <stdlib.h>
# include <stdbool.h>
// # include "game.h"

char			**ft_colour_split(char *str);
void			ft_free_matrix(char **str);
int				ft_strlen_map(char **str);
char			**ft_words_split(char *str);

// AUX MAP
char			**ft_refile_map(char **map, char **empty_map);
char			**ft_create_empty_map(int height, int width);
unsigned int	ft_get_map_height(char **map);
unsigned int	ft_get_map_width(char **map);
bool			ft_is_player(char pos);

// CHECKERS
bool			ft_check_comas(char *input);

#endif
