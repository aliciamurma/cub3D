/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:33:43 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/26 17:06:38 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"
#include <stdio.h>

char	*ft_get_error(int code)
{
	char	*errors[4];

	errors[0] = "ERROR 0\n";
	errors[1] = "ERROR 1\n";
	errors[2] = "ERROR 2\n";
	errors[3] = "ERROR 3\n";
	return (errors[code]);
}

void	ft_print_error(int code)
{
	printf("Error\n");
	printf("%s", ft_get_error(code));
}
