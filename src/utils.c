/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:05:38 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/24 18:41:27 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		l_s1;
	int		l_s2;
	int		c;

	l_s1 = ft_strlen((char *)s1);
	l_s2 = ft_strlen((char *)s2);
	str = malloc(sizeof(char) * (l_s1 + l_s2 + 1));
	if (str == NULL)
		return (NULL);
	c = 0;
	while (c < l_s2 || c < l_s1)
	{
		if (c < l_s1)
			str[c] = s1[c];
		if (c < l_s2)
			str[l_s1 + c] = s2[c];
		c++;
	}
	str[l_s1 + l_s2] = '\0';
	return (str);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	str_l;
	size_t	l;

	str_l = ft_strlen(s);
	if (str_l - start >= len)
		l = len + 1;
	else
		l = str_l - start + 1;
	if (len == 0 || str_l == 0 || start > str_l)
	{
		str = malloc(sizeof(char));
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = malloc(sizeof(char) * l);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, (s + start), l);
	return (str);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	unsigned long	d;
	unsigned long	s;

	d = 0;
	s = 0;
	while (src[s] != '\0')
	{
		s++;
	}
	if (dstsize != 0)
	{
		while (d < dstsize - 1 && src[d] != '\0')
		{
			dst[d] = src[d];
			d++;
		}
		dst[d] = '\0';
	}
	return (s);
}

char	*ft_strdup(char *s1)
{
	int		len;
	char	*str;

	len = ft_strlen((char *)s1) + 1;
	str = (malloc(sizeof(char) * len));
	if (str == 0)
		return (NULL);
	str = ft_memcpy(str, s1, len);
	return (str);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	char	*s;
	char	*d;

	s = (char *)src;
	d = (char *)dst;
	if (!dst && !src)
		return (NULL);
	while (n > 0)
	{
		*d = *s;
		s++;
		d++;
		n--;
	}
	return (dst);
}

static int	ft_searchstr(char *str1, char *str2, size_t i, size_t len)
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

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	char	*str;
	size_t	i;
	int		f;

	if (ft_strlen((char *)needle) == 0)
		return ((char *)haystack);
	str = (char *)haystack;
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
		return (str + i);
	else
		return (NULL);
}

char	*ft_strchr(char *s, int c)
{
	char	*p;
	int		find;

	find = 0;
	p = (char *)s;
	if (*p == (unsigned char)c)
	{
		find = 1;
	}
	else
	{
		while (*p != (unsigned char)c && *p != '\0')
		{
			p++;
			if (*p == (unsigned char)c)
				find = 1;
		}
	}
	if (find == 1)
		return (p);
	else
		return (0);
}

static int	words_count(char *s, char c)
{
	int		words;
	char	last_char;
	int		i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if ((last_char == c || !last_char) && s[i] != c)
		{
			words++;
		}
		last_char = s[i];
		i++;
	}
	return (words);
}

static char	*extract_word(char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	ft_memmove(str, s, i);
	str[i] = '\0';
	return (str);
}

static void	free_arr(char **arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static char	*move_pointer(char *str, char c, int i)
{
	if (i == 0)
	{
		while (*str == c && *str)
			str++;
		return (str);
	}
	else
	{
		while (*str != c && *str)
			str++;
		return (move_pointer(str, c, 0));
	}
}

char	**ft_split(char *s, char c)
{
	char	**arr;
	char	*str;
	int		words;
	int		i;
	char	*res;

	str = (char *)s;
	words = words_count(str, c);
	arr = ft_calloc(sizeof(char *), (words + 1));
	if (arr == NULL)
		return (NULL);
	i = 0;
	str = move_pointer(str, c, 0);
	while (i < words)
	{
		res = extract_word(str, c);
		if (res == NULL)
		{
			free_arr(arr, i);
			return (NULL);
		}
		arr[i++] = res;
		str = move_pointer(str, c, 1);
	}
	return (arr);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

void	ft_bzero(void *str, size_t n)
{
	char	*s;

	s = (char *)str;
	while (n > 0)
	{
		*s = '\0';
		s++;
		n--;
	}
}

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, len));
}
