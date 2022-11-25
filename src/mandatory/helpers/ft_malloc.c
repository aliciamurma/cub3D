/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:39:48 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/14 20:11:48 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "errors.h"

void    *ft_malloc(size_t size, unsigned int q)
{
    void    *pointer;

    pointer = malloc(sizeof(size) * q);
    if (!pointer)
        close_cub3d(0);
	return (pointer);
}