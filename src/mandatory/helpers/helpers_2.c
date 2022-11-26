/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:12:24 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/26 18:01:08 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "cub3d.h"

// int	ft_isdigit(int c)
// {
// 	if (c >= '0' && c <= '9')
// 	{
// 		return (1);
// 	}	
// 	else
// 	{
// 		return (0);
// 	}
// }

// int	ft_atoi(char *str)
// {
// 	int	i;
// 	int	n;
// 	int	sign;

// 	i = 0;
// 	n = 0;
// 	while ((unsigned char)str[i] == ' ' || (unsigned char)str[i] == '\t'
// 		|| (unsigned char)str[i] == '\n' || (unsigned char)str[i] == '\f'
// 		|| (unsigned char)str[i] == '\r' || (unsigned char)str[i] == '\v')
// 		i++;
// 	if (str[i] == '-')
// 		sign = -1;
// 	else
// 		sign = 1;
// 	if (str[i] == '+' || str[i] == '-')
// 		i++;
// 	while (ft_isdigit(str[i]))
// 	{
// 		n = 10 * n + (str[i] - '0');
// 		i++;
// 	}
// 	return (sign * n);
// }

void	ft_free_matrix(char **str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		free(str[count]);
		count++;
	}
	free(str);
}

// int	ft_empty_line(t_game *game, int c1)
// {
// 	int	c2;

// 	c2 = 0;
// 	while (game->cub[c1][c2] == ' ' || game->cub[c1][c2] == '\t'
// 		||game->cub[c1][c2] == '\n')
// 	{
// 		while (game->cub[c1][c2] == ' ' || game->cub[c1][c2] == '\t')
// 			c2++;
// 		c1++;
// 	}
// 	return (c1);
// }

int	ft_strlen_map(char **str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
