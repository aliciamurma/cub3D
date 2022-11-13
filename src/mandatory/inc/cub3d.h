/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:02:52 by amurcia-          #+#    #+#             */
/*   Updated: 2022/11/12 17:25:07 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "mlx.h"

# define BUFFER_SIZE 1
# define WIDTH 1920
# define HEIGHT 1080
# define SIZE_TEXTURE 100
# define screenWidth 640
# define screenHeight 480
# define texWidth 64
# define texHeight 64
# define mapWidth 24
# define mapHeight 24

// typedef struct s_texture
// {
// 	char	*north;
// 	char	*south;
// 	char	*east;
// 	char	*west;
// }	t_texture;

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

typedef struct s_vector
{
	double	x;
	double	y;
}		t_vector;

typedef struct s_rotator
{
	double	x;
	double	y;
}	t_rotator;

typedef struct s_position
{
	double			pos_x; // pos player
	double			pos_y; // pos player
	double			dir_x; // vector de la direccion del jugador
	double			dir_y; // vector de la direccion del jugador
	double			ray_dirx; //vector de direccion del rayo
	double			ray_diry; //vector de direccion del rayo
	double			plane_x;
	double			plane_y;
	double			speed_move;
	double			speed_rot;
	double			camera_x; // la posicion en el plano de la camara
	double			camera_y; // la posicion en el plano de la camara
	//la dirección del rayo se puede encontrar como (vector de dirección) + (plano de la cámara x múltiplo) 
	unsigned int	*buffer;
	double			time; // time of current frame
	double			old_time; // time of previous frame
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			ray_x;
	double			ray_y;
	double			map_x;
	double			map_y;
}	t_position;

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
	// TEXTURAS
	// char		*tnorth;
	// char		*tsouth;
	// char		*teast;
	// char		*twest;
	t_texture	*texture;
	// COLORES
	char		*floor;
	char		*ceiling;
	char		**map;
	// PLAYER
	int			player_x;
	int			player_y;
	t_position	pos;
}	t_game;

// IMAGES
void    put_images(t_game *game);

// MOVE
int	movements(int keycode, t_game *game);

// CHECK MAP
void	check_map(t_game *game);

// CHECK
int		check_parameters(int argc, char **argv);
void	open_map(t_game *game, char **argv);

// CLOSE
void	close_cub3d(int value);
int		close_x(t_game *game);

// GET_NEXT_LINE
char	*get_next_line(int fd);

// INFO CUB
void	get_map(t_game *game);
void	get_textures_colours(t_game *game);
void	check_textures(char *str);
void	check_colours(t_game *game);

// READ
void	get_cub_info(t_game *game, char **argv);

// UTILS
char	**ft_my_split(char *str);
int		ft_isdigit(int c);
int		ft_atoi(char *str);
void	free_matrix(char **str);
int		empty_line(t_game *game, int c1);
int		ft_strlen_map(char **str);
int		ft_strlen(char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
char	*ft_strdup(char *s1);
void	*ft_memcpy(void *dst, void *src, size_t n);
char	*ft_strnstr(char *haystack, char *needle, size_t len);
char	*ft_strchr(char *s, int c);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *str, size_t n);
void	*ft_memmove(void *dst, void *src, size_t len);

#endif