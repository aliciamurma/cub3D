/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:16:19 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/05 17:18:10 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_BONUS_H
# define HELPERS_BONUS_H

# include <stdlib.h>
# include <stdbool.h>
// # include "game.h"

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
