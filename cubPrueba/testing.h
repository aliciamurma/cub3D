/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:56:37 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/18 21:08:18 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTING_H
# define TESTING_H

# include <math.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
# include <unistd.h>
# include "mlx/mlx.h"
#define mapWidth 24
#define mapHeight 24
# define BUFFER_SIZE 1

typedef  struct s_pos
{
	void		*mlx_ptr;
	void		*win_ptr;
	
    double  pos_x;
    double  pos_y;
    double	dir_x;
    double	dir_y;
    double	plane_x;
    double	plane_y;
    void	*mlx;
    void	*win;
    double	move_speed;
    double	rot_speed;
	int		wid;
	int		hei;
	int		**mapita;
	char	**map;
}   t_pos;

// 0 for north
// 1 for south
// 2 for west
// 3 for east
typedef struct s_texture
{
	void			*texture;
	char			*path;
	int				width;
	int				endian;
	int				tex_width;
	int				tex_height;
}	t_texture;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		**img_ptr;
	char		**cub;
	char		*cub_raw;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			endian;
	char		*data_addr;
	// COLORES
	char		*floor;
	char		*ceiling;
	char		**map;
	// PLAYER
	int			player_x;
	int			player_y;
	t_texture	*texture;
}	t_game;

int		check_parameters(int argc, char **argv);
void	check_one_player(t_game *game);
void	check_map_letters(t_game *game);
void	check_surrounded_x(t_game *game);
void	check_surrounded_y(t_game *game);
void	check_map(t_game *game);
void    *ft_malloc(size_t size, unsigned int q);
char	*get_next_line(int fd);
char	**ft_my_split(char *str);
void	free_matrix(char **str);
int		empty_line(t_game *game, int c1);
int		ft_strlen_map(char **str);
void	get_map(t_game *game);
void	get_cub_info(t_game *game, char **argv);
void	exit_cub3d(int value);
int 	ft_strlen(char *str);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);

# endif
