/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:08:30 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/25 21:26:14 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "maps.h"
#include "textures.h"

/**
 * @brief Check if the given number for the colours is correct
 * 
 * @param game 
 */
void	check_colours(t_game *game)
{
	char	**nbrs;

	nbrs = ft_my_split(game->floor);
	if (!nbrs)
		close_cub3d(-1);
	if ((ft_atoi(nbrs[3]) < 0 || ft_atoi(nbrs[3]) > 255)
		|| (ft_atoi(nbrs[1]) < 0 || ft_atoi(nbrs[1]) > 255)
		|| (ft_atoi(nbrs[2]) < 0 || ft_atoi(nbrs[2]) > 255))
		close_cub3d(-2);
	free (nbrs);
	nbrs = ft_my_split(game->ceiling);
	if (!nbrs)
		close_cub3d(-2);
	if ((ft_atoi(nbrs[3]) < 0 || ft_atoi(nbrs[3]) > 255)
		|| (ft_atoi(nbrs[1]) < 0 || ft_atoi(nbrs[1]) > 255)
		|| (ft_atoi(nbrs[2]) < 0 || ft_atoi(nbrs[2]) > 255))
		close_cub3d(-2);
	free (nbrs);
}



// TODO me cago en la puta
// noth_texture
	// -get_path
	// -check_path
	// -load_texture
// south_texture
	// -get_path
	// -check_path
	// -load_texture
// east_texture
	// -get_path
	// -check_path
	// -load_texture
// west_texture
	// -get_path
	// -check_path
	// -load_texture
// ceil_color
	// -check_path
// floor_color
	// -check_path
	// -load_color

/**
 * @brief Check if the texture path can be opened
 * 
 * @param str 
 */
void	ft_check_textures(char *str)
{
	int		fd;

	fd = open(str, R_OK);
	if (fd == -1)
		close_cub3d(-2);
	close(fd);
}

void	ft_get_path(char *texture, char *path)
{
	texture = malloc(sizeof(char) * ft_strlen(path));
	texture = path;
}

void	set_north_texture(t_texture texture, char *str)
{
	char	**north;
	
	north = ft_my_split(str);
	if (ft_strnstr(north[0], "NO"))
		ft_get_path(texture.north, north[1]);
	ft_free_matrix(north);
	ft_check_textures(texture.north);
	// LOAD
}

void	set_south_texture(t_texture texture, char *str)
{
	char	**south;
	
	south = ft_my_split(str);
	if (ft_strnstr(south[0], "SO"))
		ft_get_path(texture.south, south[1]);
	ft_free_matrix(south);
	ft_check_textures(texture.south);
	// LOAD
}

void	set_east_texture(t_texture texture, char *str)
{
	char	**east;
	
	east = ft_my_split(str);
	if (ft_strnstr(east[0], "EA"))
		ft_get_path(texture.east, east[1]);
	ft_free_matrix(east);
	ft_check_textures(texture.east);
	// LOAD
}

void	set_west_texture(t_texture texture, char *str)
{
	char	**west;
	
	west = ft_my_split(str);
	if (ft_strnstr(west[0], "WE"))
		ft_get_path(texture.west, west[1]);
	ft_free_matrix(west);
	ft_check_textures(texture.west);
	// LOAD
}

void	ft_get_textures_colours(t_map map, t_texture texture)
{
	int count;

	count = 0;
	while (count < 6)
	{
		set_north_texture(texture, map.map[count]);
		set_south_texture(texture, map.map[count]);
		set_west_texture(texture, map.map[count]);
		set_east_texture(texture, map.map[count]);
		count++;
	}
}
