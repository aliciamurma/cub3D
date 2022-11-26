/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:08:30 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/26 17:48:42 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "game.h"
#include "maps.h"
#include "textures.h"
#include "exit.h"

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
	    ft_exit_cub3d(1);
	close(fd);
}

void	ft_get_path(char *texture, char *path)
{
	texture = malloc(sizeof(char) * ft_strlen(path));
	texture = path;
}

void	ft_set_north_texture(t_texture texture, char *str)
{
	char	**north;
	
	north = ft_words_split(str);
	if (!north)
		ft_exit_cub3d(1);
	if (ft_strnstr(north[0], "NO"))
	{
		ft_get_path(texture.north, north[1]);
		ft_check_textures(texture.north);
		// LOAD
	}
	ft_free_matrix(north);
}

void	ft_set_south_texture(t_texture texture, char *str)
{
	char	**south;
	
	south = ft_words_split(str);
	if (!south)
		ft_exit_cub3d(1);
	if (ft_strnstr(south[0], "SO"))
	{
		ft_get_path(texture.south, south[1]);
		ft_check_textures(texture.south);
		// LOAD
	}
	ft_free_matrix(south);
}

void	ft_set_east_texture(t_texture texture, char *str)
{
	char	**east;

	east = ft_words_split(str);
	if (!east)
		ft_exit_cub3d(1);
	if (ft_strnstr(east[0], "EA"))
	{	ft_get_path(texture.east, east[1]);
		ft_check_textures(texture.east);
		// LOAD
	}
	ft_free_matrix(east);
}

void	set_west_texture(t_texture texture, char *str)
{
	char	**west;
	
	west = ft_words_split(str);
	if (!west)
		ft_exit_cub3d(1);
	if (ft_strnstr(west[0], "WE"))
	{
		ft_get_path(texture.west, west[1]);
		ft_check_textures(texture.west);
		// LOAD
	}
	ft_free_matrix(west);
}

/**
 * @brief Check if the given number for the colours is correct
 * 
 * @param game 
 */
void	ft_check_colours(char *str)
{
	char	**nbrs;

	nbrs = ft_my_split(str);
	if (!nbrs)
	    ft_exit_cub3d(1);
	if ((ft_atoi(nbrs[3]) < 0 || ft_atoi(nbrs[3]) > 255)
		|| (ft_atoi(nbrs[1]) < 0 || ft_atoi(nbrs[1]) > 255)
		|| (ft_atoi(nbrs[2]) < 0 || ft_atoi(nbrs[2]) > 255))
		ft_exit_cub3d(2);
	ft_free_matrix(nbrs);
}

void	ft_set_ceil_colour(t_texture texture, char *str)
{
	char	*ceil;
	int		count;

	count = 0;
	while (str[count] && str[count + 1])
	{
		if(str[count] == ',' && str[count + 1] == ',')
		    ft_exit_cub3d(2);
		count++;
	}
	ceil = ft_words_split(str);
	if (!ceil)
	    ft_exit_cub3d(1);
	if (ft_strnstr(ceil[0], "C"))
	{
		ft_get_path(texture.ceil, ceil[1]);
		ft_check_colours(texture.ceil);
		// LOAD
		/*
		img_r = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
        	"./src/assets/textures/west.xpm", &d, &d);
		img2.pixels = mlx_get_data_addr(img_r, &img2.bits_per_pixel,
			&img2.line_size, &img2.endian);
		*/
	}
	ft_free_matrix(ceil);
}

void	ft_set_floor_colour(t_texture texture, char *str)
{
	char	*floor;

	floor = ft_words_split(str);
	if (!floor)
		ft_exit_cub3d(1);
	if (ft_strnstr(floor[0], "F"))
	{
		ft_get_path(texture.floor, floor[1]);
		ft_check_colours(texture.floor);
	// LOAD
	}
	ft_free_matrix(floor);
}

void	ft_get_textures_colours(t_map map, t_texture texture)
{
	int count;

	count = 0;
	while (count < 6)
	{
		ft_set_north_texture(texture, map.map[count]);
		ft_set_south_texture(texture, map.map[count]);
		ft_set_west_texture(texture, map.map[count]);
		ft_set_east_texture(texture, map.map[count]);
		ft_set_floor_colour(texture, map.map[count]);
		ft_set_ceil_colour(texture, map.map[count]);
		count++;
	}
}
