/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:39:48 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/17 13:03:22 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testing.h"

void    *ft_malloc(size_t size, unsigned int q)
{
    void    *pointer;

    pointer = malloc(sizeof(size) * q);
    if (!pointer)
        exit_cub3d(0);
	return (pointer);
}
