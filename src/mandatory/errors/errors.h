/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 10:57:55 by aramirez          #+#    #+#             */
/*   Updated: 2022/11/27 18:00:03 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORS_H
# define ERRORS_H

typedef enum e_errors
{
	INV_ARGS = 1,
	INV_CUB_EXT = 2,
	OPEN_CUB = 3,
	MAP_FORMAT = 4,
	CUB_FORMAT = 5,
	TEXT_NOTFOUND = 6
}	t_errors;

char	*ft_get_error(int code);

#endif