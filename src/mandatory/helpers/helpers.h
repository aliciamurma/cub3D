/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 17:16:19 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/26 19:08:48 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H
# define BUFFER_SIZE 1

#include <stdio.h>
#include "game.h"

void	*ft_malloc(size_t size, unsigned int q);
char	*get_next_line(int fd);
char	**ft_colour_split(char *str);
void	ft_free_matrix(char **str);
int		ft_strlen_map(char **str);
char	**ft_words_split(char *str);

#endif
