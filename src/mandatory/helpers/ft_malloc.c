/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:39:48 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/26 17:37:49 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "exit.h"

void    *ft_malloc(size_t size, unsigned int q)
{
    void    *pointer;

    pointer = malloc(sizeof(size) * q);
    if (!pointer)
        ft_exit_cub3d(0);
	return (pointer);
}
