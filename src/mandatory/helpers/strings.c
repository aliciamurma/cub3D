/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:10:06 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/27 16:49:51 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"
#include "memory.h"

int	ft_strlen_arr(char	**arr)
{
	int	i;

	i = 0;
	while (arr && arr[i])
		i++;
	return (i);
}

char	**ft_push_str(char **arr, char *str)
{
	int	len;

	len = ft_strlen_arr(arr);
	arr = ft_realloc(arr, sizeof(char *) * (len + 2));
	arr[len] = str;
	arr[len + 1] = NULL;
	return (arr);
}

bool	ft_strcmp(const char *s1, const char *s2, bool strict)
{
	size_t	cont;

	cont = 0;
	if (s1 == NULL && s2 == NULL)
		return (true);
	if (s1 == NULL || s2 == NULL)
		return (false);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (false);
	while (s1[cont] != '\0' || s2[cont] != '\0')
	{
		if (strict)
		{
			if (s1[cont] != s2[cont])
				return (false);
		}
		else
		{
			if (ft_tolower(s1[cont]) != ft_tolower(s2[cont]))
				return (false);
		}
		cont++;
	}
	return (true);
}

static int	ft_searchstr(char *str1, const char *str2, size_t i, size_t len)
{
	size_t	j;
	int		find;

	j = 0;
	find = 1;
	while (str2[j] != '\0')
	{
		if (str1[i + j] != str2[j])
			find = 0;
		j++;
	}
	if ((i + j) > len)
		find = 0;
	return (find);
}

bool	ft_str_includes(const char *haystack, const char *needle)
{
	char	*str;
	size_t	i;
	int		f;
	size_t	len;

	if (ft_strlen((char *)needle) == 0)
		return ((char *)haystack);
	str = (char *)haystack;
	len = ft_strlen(haystack);
	i = 0;
	f = 0;
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
		{
			f = ft_searchstr(str, needle, i, len);
			if (f == 1)
				break ;
		}
		i++;
	}
	if (f == 1)
		return (true);
	return (false);
}
