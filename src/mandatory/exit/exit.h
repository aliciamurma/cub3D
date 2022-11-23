/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:16:51 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/18 15:52:34 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H
# include "cub3d.h"

void	exit_cub3d(int value);
void	print_error(int code);
void	close_cub3d(t_game *game);

#endif