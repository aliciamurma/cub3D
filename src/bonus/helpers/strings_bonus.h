/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:10:12 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/05 17:18:37 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRINGS_BONUS_H
# define STRINGS_BONUS_H

# include <stdbool.h>

char	**ft_push_str(char **arr, char *str);
int		ft_strlen_arr(char	**arr);
bool	ft_strcmp(const char *s1, const char *s2, bool strict);
bool	ft_str_includes(const char *haystack, const char *needle);

#endif