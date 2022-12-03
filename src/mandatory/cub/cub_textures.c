/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 15:46:46 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/03 20:35:35 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "strings.h"
#include "cub.h"
#include "exit.h"
#include "errors.h"
#include "helpers.h"
#include "textures.h"
#include "images.h"

/**
 * @brief Comprueba que tipo de textura es la linea del .cub
 * 
 * @param texture 
 * @return t_texture_types 
 */
t_texture_types	ft_get_texture_type(char *texture)
{
	char				**parse;
	t_texture_types		type;

	type = 0;
	parse = ft_split(texture, ' ');
	if (ft_strcmp(parse[0], "NO", true))
		type = NO;
	if (ft_strcmp(parse[0], "SO", true))
		type = SO;
	if (ft_strcmp(parse[0], "WE", true))
		type = WE;
	if (ft_strcmp(parse[0], "EA", true))
		type = EA;
	if (ft_strcmp(parse[0], "F", true))
		type = F;
	if (ft_strcmp(parse[0], "C", true))
		type = C;
	ft_free_matrix(parse);
	return (type);
}

/**
 * @brief Parsea la informacion del .cub sobre la textura
 * 
 * @param texture 
 * @return char* 
 */
char	*ft_parse_texture(char *texture)
{
	char	*aux;
	char	*info;

	aux = ft_substr(texture, 2, ft_strlen(texture));
	info = ft_strtrim(aux, " ");
	free(aux);
	return (info);
}

/**
 * @brief Obtiene la informacion de la textura del .cub
 * 
 * @param mlx 
 * @param texture 
 * @return t_image 
 */
t_image	ft_get_texture(void *mlx, char *texture)
{
	t_image	img;
	char	*path;

	path = ft_parse_texture(texture);
	img = ft_create_img(mlx, path);
	free(path);
	return (img);
}

/**
 * @brief Obtiene el color hexadecimal de la informacion del .cub
 * 
 * @param texture 
 * @return unsigned int 
 */
unsigned int	ft_get_color(char *texture)
{
	char	*input;

	input = ft_parse_texture(texture);
	if (!ft_check_comas(input))
		ft_exit_cub3d(MAP_FORMAT);
	return (ft_parse_color(input));
}

/**
 * @brief Obtiene la imagen de las texturas apartir de la informacion
 * del .cub
 * 
 * @param mlx 
 * @param cub 
 * @return t_texture 
 */
t_texture	ft_parse_cub_textures(void *mlx, char **cub)
{
	int					i;
	t_texture_types		type;
	t_texture			textures;

	i = 0;
	while (cub[0] && i < 6)
	{
		type = ft_get_texture_type(cub[i]);
		if (type == 0)
			ft_exit_cub3d(CUB_FORMAT);
		if (type == NO)
			textures.north = ft_get_texture(mlx, cub[i]);
		if (type == SO)
			textures.south = ft_get_texture(mlx, cub[i]);
		if (type == EA)
			textures.east = ft_get_texture(mlx, cub[i]);
		if (type == WE)
			textures.west = ft_get_texture(mlx, cub[i]);
		if (type == C)
			textures.floor = ft_get_color(cub[i]);
		if (type == F)
			textures.ceil = ft_get_color(cub[i]);
		i++;
	}
	return (textures);
}
