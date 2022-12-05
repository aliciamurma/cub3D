/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 19:57:10 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/02 20:05:38 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	ft_check_comas(char *input)
{
	int	c;
	int	coma;

	c = 0;
	coma = 0;
	while (input[c] != '\0')
	{
		if (input[c] == ',')
			coma++;
		c++;
	}
	if (coma != 2)
		return (false);
	return (true);
}
