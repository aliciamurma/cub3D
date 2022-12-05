/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:58:09 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/05 17:15:12 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors_bonus.h"

/**
 * @brief Obtiene la informacion del error segun el code
 * 
 * @param code 
 * @return char* 
 */
char	*ft_get_error(int code)
{
	if (code == INV_ARGS)
		return ("Invalid number arguments");
	if (code == INV_CUB_EXT)
		return ("Invalid cub map extension");
	if (code == OPEN_CUB)
		return ("Can't open cub file");
	if (code == MAP_FORMAT)
		return ("Incorrect map format");
	if (code == CUB_FORMAT)
		return ("Incorrect cub format");
	if (code == TEXT_NOTFOUND)
		return ("Texture not found");
	if (code == COLOR_FORMAT)
		return ("Colour not found");
	return ("");
}
