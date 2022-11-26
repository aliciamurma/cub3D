/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:08:30 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/26 22:24:09 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include "game.h"
#include "maps.h"
#include "textures.h"
#include "helpers.h"
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
	{
		printf("no puedo leer: %s\n", str);
		ft_exit_cub3d(1);
	}
	close(fd);
}

void	ft_get_texture_path(char *texture, char *path)
{
	texture = malloc(sizeof(char) * ft_strlen(path));
	texture = path;
}

void	ft_set_north_texture(t_texture *texture, char *str)
{
	char	**north;
	
	north = ft_words_split(str);
	if (!north)
		ft_exit_cub3d(1);
	// printf("str is %s\n", str);
	// printf("north 0 is %s\n", north[0]);
	// printf("north is %s\n", north[1]);
	if (ft_strncmp(north[0], "NO", 2) == 0)
	{
		texture->north = ft_strdup(north[1]);
		ft_check_textures(north[1]);
		// LOAD
	}
	ft_free_matrix(north);
}

void	ft_set_south_texture(t_texture *texture, char *str)
{
	char	**south;
	
	south = ft_split(str, ' ');
	if (!south)
		ft_exit_cub3d(1);
	if (ft_strncmp(south[0], "SO", 2) == 0)
	{
		texture->south = ft_strdup(south[1]);
		ft_check_textures(south[1]);
		// LOAD
	}
	ft_free_matrix(south);
}

void	ft_set_east_texture(t_texture *texture, char *str)
{
	char	**east;

	east = ft_split(str, ' ');
	if (!east)
		ft_exit_cub3d(1);
	if (ft_strncmp(east[0], "EA", 2) == 0)
	{	
		texture->east = ft_strdup(east[1]);
		ft_check_textures(east[1]);
		// LOAD
	}
	ft_free_matrix(east);
}

// TODO Arreglar el ft_words_split
void	ft_set_west_texture(t_texture *texture, char *str)
{
	char	**west;
	
	west = ft_split(str, ' ');
	if (!west)
		ft_exit_cub3d(1);
	if (ft_strncmp(west[0], "WE", 2) == 0)
	{
		printf("str is %s\n", str);
		printf("fst pos is %s\n", west[0]);
		printf("sec pos is %s\n", west[1]);
		texture->west = ft_strdup(west[1]);
		ft_check_textures(west[1]);
		// LOAD
	}
	ft_free_matrix(west);
}

int	ft_get_colour_id(char **nbrs)
{
	return ((ft_atoi(nbrs[1]) & 0xff) << 16) + ((ft_atoi(nbrs[2]) & 0xff) << 8) + (ft_atoi(nbrs[3]) & 0xff);
}

/**
 * @brief Check if the given number for the colours is correct
 * 
 * 
 * @param game 
 */
// TODO CHECK SI ES NECESARIO
void	ft_check_nbrs(char *str)
{
	char	**nbrs;

	nbrs = ft_colour_split(str);
	if (!nbrs)
	    ft_exit_cub3d(1);
	if ((ft_atoi(nbrs[3]) < 0 || ft_atoi(nbrs[3]) > 255)
		|| (ft_atoi(nbrs[1]) < 0 || ft_atoi(nbrs[1]) > 255)
		|| (ft_atoi(nbrs[2]) < 0 || ft_atoi(nbrs[2]) > 255))
		ft_exit_cub3d(2);
	ft_free_matrix(nbrs);
}

void	ft_check_format_colour(char *str)
{
	int		count;

	count = 0;
	while (str[count] && str[count + 1])
	{
		if(str[count] == ',' && str[count + 1] == ',')
		    ft_exit_cub3d(2);
		count++;
	}
}

void	ft_set_ceil_colour(t_texture *texture, char *str)
{
	char	**ceil;

	ceil = ft_words_split(str);
	if (!ceil)
	    ft_exit_cub3d(1);
	if (ft_strncmp(ceil[0], "C", 1) == 0)
	{
		ft_check_format_colour(ceil[1]);
		ft_check_nbrs(ceil[1]);
		texture->ceil = ft_get_colour_id(ceil);
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

void	ft_set_floor_colour(t_texture *texture, char *str)
{
	int		count;
	char	**floor;
	// char	*aux;

	count = 0;
	floor = ft_split(str, ' ');
	if (!floor)
		ft_exit_cub3d(1);
	if (ft_strncmp(floor[0], "F", 1) == 0)
	{
		ft_free_matrix(floor);
		floor = ft_split(str, ',');
		// while (floor[count])
		// {
		// 	aux = ft_strtrim(floor[count], " ");
		// 	free(floor[count]);
		// 	floor[count] = aux;
		// 	count++;
		// }
		ft_check_format_colour(floor[1]);
		ft_check_nbrs(floor[1]);
		texture->floor = ft_get_colour_id(floor);
	// LOAD
	}
	ft_free_matrix(floor);
}

void	ft_get_textures(t_map *map, t_texture *texture)
{
	int count;

	count = 0;
	while (count < 6)
	{
		ft_set_north_texture(texture, map->cub[count]);
		ft_set_south_texture(texture, map->cub[count]);
		ft_set_west_texture(texture, map->cub[count]);
		ft_set_east_texture(texture, map->cub[count]);
		// ft_set_floor_colour(texture, map->cub[count]);
		// ft_set_ceil_colour(texture, map->cub[count]);
		count++;
	}
}
