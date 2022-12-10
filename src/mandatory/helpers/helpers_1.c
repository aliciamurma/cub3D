/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:12:26 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/10 16:54:28 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include "helpers.h"

int	ft_strlen_map(char **str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}
