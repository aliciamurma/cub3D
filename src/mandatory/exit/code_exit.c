/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:33:43 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/26 17:05:32 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"
#include <stdio.h>

char	*ft_get_error(int code)
{
	char	*errors[4];

	errors[0] = "Number of arguments incorrect\n";
	errors[1] = "Not enough memory\n";
	errors[2] = "Map invalid\n";
	errors[3] = "";
	return (errors[code]);
}

void	ft_print_error(int code)
{
	printf("Error\n");
	printf("%s", ft_get_error(code));
}
