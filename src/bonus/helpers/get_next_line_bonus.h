/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 15:57:53 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/05 17:17:45 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_SIZE 1000

int		contain_line(char *str);
int		get_len(char *str);
char	*concat_str(char *storage, char *buffer, int len_b);
int		count_line_words(char *str);
void	clean_storage(char *storage);
char	*get_next_line(int fd);
char	*free_malloc(char *str);

#endif