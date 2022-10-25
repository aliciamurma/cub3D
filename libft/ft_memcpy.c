/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:06:42 by aramirez          #+#    #+#             */
/*   Updated: 2022/01/25 14:01:28 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
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
