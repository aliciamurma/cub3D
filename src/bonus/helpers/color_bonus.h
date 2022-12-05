/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:38:58 by amurcia-          #+#    #+#             */
/*   Updated: 2022/12/05 17:17:23 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_BONUS_H
# define COLOR_BONUS_H

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

void			ft_check_color(int color);
void			ft_check_color_digit(char *color);
unsigned int	ft_create_rgb(t_color color);

#endif