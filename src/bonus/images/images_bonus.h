/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 17:27:10 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/10 17:59:50 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGES_BONUS_H
# define IMAGES_BONUS_H

# include <stdbool.h>

typedef struct s_image
{
	void	*pointer;
	char	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
	int		width;
	int		height;
}			t_image;

typedef struct s_num_text
{
	bool	north;
	bool	south;
	bool	west;
	bool	east;
	bool	floor;
	bool	ceil;
}	t_num_text;

t_image	ft_create_img(void *mlx, char *path);
t_image	ft_create_new_img(void *mlx, int width, int height);
t_image	ft_resize_img(void *mlx, t_image img, int ratio);

#endif