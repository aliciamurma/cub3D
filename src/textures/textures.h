/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 12:59:38 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/25 21:27:58 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTU
typedef struct s_texture
{
	void	*north;
	void	*south;
	void	*east;
	void	*west;
	int	    floor;
	int 	ceil;
}			t_texture;

#endif