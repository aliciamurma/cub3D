/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:12:24 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/17 13:09:14 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testing.h"

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

int ft_strlen(char *str)
{
	int c = 0;

	while (str[c])
		c++;
	return (c);
}


static size_t	ft_count_words(char const *s, char c)
{
	size_t	cont;
	size_t	word;

	cont = 0;
	word = 0;
	while (s[cont])
	{
		if (s[cont] != c && (s[cont + 1] == c || s[cont + 1] == '\0'))
			word++;
		cont++;
	}
	return (word);
}

static void	ft_free(char **d, size_t cont_d)
{
	while (cont_d > 0)
	{
		cont_d--;
		free(d[cont_d]);
	}
	free(d);
}

static char	**ft_refile(char const *s, char c, char **d)
{
	size_t	cont;
	size_t	start;
	size_t	cont_d;

	cont = 0;
	start = 0;
	cont_d = 0;
	while (s[cont])
	{
		if (s[cont] == c && s[cont + 1] != c)
			start = cont + 1;
		if (s[cont] != c && (s[cont + 1] == c || s[cont + 1] == '\0'))
		{
			d[cont_d] = ft_substr(s, start, cont - start + 1);
			if (!d[cont_d])
			{
				ft_free(d, cont_d);
				return (NULL);
			}
			cont_d++;
		}
		cont++;
	}
	d[cont_d] = NULL;
	return (d);
}

char	**ft_split(char const *s, char c)
{
	char	**d;
	size_t	words;

	words = ft_count_words(s, c);
	d = malloc(sizeof(char *) * (words + 1));
	if (!d || !s)
		return (NULL);
	d = ft_refile(s, c, d);
	return (d);
}


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	int		cont;
	int		conts3;

	cont = 0;
	conts3 = 0;
	s3 = malloc(sizeof(char) * ((ft_strlen((char *)(s1)))
				+ ((ft_strlen((char *)(s2))) + 1)));
	if (!s3)
		return (0);
	while (s1[cont] != '\0')
	{
		s3[conts3] = s1[cont];
		cont++;
		conts3++;
	}
	cont = 0;
	while (s2[cont] != '\0')
	{
		s3[conts3] = s2[cont];
		cont++;
		conts3++;
	}
	s3[conts3] = '\0';
	return (s3);
}


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*d;
	size_t	cont;
	size_t	len_s;

	cont = 0;
	len_s = ft_strlen((char *)s);
	if (len >= len_s - start && start < len_s)
		len = len_s - start;
	else if (start >= len_s)
		len = 0;
	else if (len > len_s)
		len = len_s;
	d = malloc(sizeof(char) * (len + 1));
	if (!d)
		return (NULL);
	while (cont < len)
	{
		d[cont] = s[start];
		cont++;
		start++;
	}
	d[cont] = '\0';
	return (d);
}

char	*ft_strchr(const char *s, int c)
{
	int	cont;

	cont = 0;
	while (s[cont] != '\0')
	{
		if (s[cont] == (char)c)
			return ((char *)(s + cont));
		cont++;
	}
	if ((char)c == '\0')
		return ((char *)(s + cont));
	return (0);
}

static int	ft_len(const char *s1)
{
	int	len;

	len = 0;
	while (s1[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	int		cont;
	char	*s2;
	int		len;

	cont = 0;
	len = ft_len(s1);
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s2)
		return (NULL);
	while (s1[cont] != '\0')
	{
		s2[cont] = *((char *)(s1 + cont));
		cont++;
	}
	s2[cont] = '\0';
	return (s2);
}
