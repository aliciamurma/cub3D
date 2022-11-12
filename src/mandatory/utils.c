/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:05:38 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/12 17:38:51 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static size_t	ft_len_word(char *str, int start)
{
	while (str[start] && str[start] != ' '
		&& str[start] != '\t' && str[start] != ',')
		start++;
	return (start);
}

static char	*ft_bidimensional(char *str, int start)
{
	int		cont;
	int		len;
	char	*word;

	cont = 0;
	len = ft_len_word(str, start);
	word = (char *)malloc(sizeof(char) * len + 1);
	while (start < len)
	{
		word[cont] = str[start];
		cont++;
		start++;
	}
	word[start] = '\0';
	return (word);
}

static char	**ft_refile(char **array, char *str)
{
	size_t	cont;
	size_t	cont_w;

	cont = 0;
	cont_w = 0;
	while (str[cont] == ' ' || str[cont] == '\t' || str[cont] == ',')
		cont++;
	while (str[cont] != '\0')
	{
		array[cont_w] = ft_bidimensional(str, cont);
		cont_w++;
		while (str[cont] && str[cont] != ' '
			&& str[cont] != '\t' && str[cont] != ',')
			cont++;
		while (str[cont] == ' ' || str[cont] == '\t' || str[cont] == ',')
			cont++;
	}
	return (array);
}

static size_t	ft_count_words(char *str)
{
	size_t	words;
	size_t	cont;

	words = 0;
	cont = 0;
	while (str[cont] == ' ' || str[cont] == '\t' || str[cont] == ',')
		cont++;
	while (str[cont])
	{
		while (str[cont] && str[cont] != ' '
			&& str[cont] != '\t' && str[cont] != ',')
			cont++;
		while (str[cont] == ' ' || str[cont] == '\t' || str[cont] == ',')
			cont++;
		words++;
	}
	return (words);
}

char	**ft_my_split(char *str)
{
	char	**array;
	size_t	words;

	words = ft_count_words(str);
	array = malloc(sizeof(char *) * (words + 1));
	if (!array || !str)
		return (NULL);
	array[words] = NULL;
	array = ft_refile(array, str);
	return (array);
}


int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}	
	else
	{
		return (0);
	}
}

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	while ((unsigned char)str[i] == ' ' || (unsigned char)str[i] == '\t'
		|| (unsigned char)str[i] == '\n' || (unsigned char)str[i] == '\f'
		|| (unsigned char)str[i] == '\r' || (unsigned char)str[i] == '\v')
		i++;
	if (str[i] == '-')
		sign = -1;
	else
		sign = 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (ft_isdigit(str[i]))
	{
		n = 10 * n + (str[i] - '0');
		i++;
	}
	return (sign * n);
}

void	free_matrix(char **str)
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

int	empty_line(t_game *game, int c1)
{
	int	c2;

	c2 = 0;
	while (game->cub[c1][c2] == ' ' || game->cub[c1][c2] == '\t'
		||game->cub[c1][c2] == '\n')
	{
		while (game->cub[c1][c2] == ' ' || game->cub[c1][c2] == '\t')
			c2++;
		c1++;
	}
	return (c1);
}

int	ft_strlen_map(char **str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
