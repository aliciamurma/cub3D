/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 13:13:08 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/05 17:18:16 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "exit_bonus.h"

void	*ft_malloc(size_t size)
{
	void	*pointer;

	pointer = malloc(size);
	if (!pointer)
		ft_exit_cub3d(0);
	return (pointer);
}

/**
 * @brief Reasigna un espacio de memoria
 * 
 * @param ptr puntero con la memoria reservada
 * @param size nuevo size a reservar
 * @return void* nuevo puntero con la memoria reasignada
 */
void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	if (ptr == NULL)
		return (ft_malloc(size));
	if (!size)
		return (ptr);
	new_ptr = ft_malloc(size);
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}

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
