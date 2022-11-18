/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:12:26 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/17 12:44:49 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testing.h"

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
