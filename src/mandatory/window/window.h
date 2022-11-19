/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:40:28 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/19 11:43:13 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H
# define WIDTH 800
# define HEIGHT 600
# define NAME_W "MY CUB3D"

typedef struct s_window
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_window;

#endif
