/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:16:19 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/27 13:20:13 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H
# define BUFFER_SIZE 1000

# include <stdlib.h>
# include <stdbool.h>
// # include "game.h"

char	*get_next_line(int fd);
char	**ft_colour_split(char *str);
void	ft_free_matrix(char **str);
int		ft_strlen_map(char **str);
char	**ft_words_split(char *str);

#endif
