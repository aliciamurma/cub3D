/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   code_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:33:43 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/14 20:52:20 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"
#include <stdio.h>

char	*get_error(int code)
{
	char	*errors[4];

	errors[0] = "Number of arguments incorrect\n";
	errors[1] = "Not enough memory\n";
	errors[2] = "Map invalid\n";
	errors[3] = "";
	return (errors[code]);
}

void	print_error(int code)
{
	printf("Error\n");
	printf("%s", get_error(code));
}
