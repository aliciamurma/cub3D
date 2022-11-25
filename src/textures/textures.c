/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 13:05:45 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/25 13:10:48 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"
#include "window.h"

void    *ft_get_texture(char *path, void *mlx_ptr)
{
    void *img;
    int d;
    
    d = 0;
    img = mlx_xpm_file_to_image(mlx_ptr, path, &d, &d);
    if (!img) exit(0);
    return img;
    // ft_upload_image(game, game->texture[0], "./src/assets/textures/north.xpm");
    // ft_upload_image(game, game->texture[1], "./src/assets/textures/south.xpm");
    // ft_upload_image(game, game->texture[2], "./src/assets/textures/east.xpm");
    // ft_upload_image(game, game->texture[3], "./src/assets/textures/west.xpm");
}


void ft_load_textures(t_textures *texture, char **textures)
{
    
}