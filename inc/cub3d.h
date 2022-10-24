/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:02:52 by amurcia-          #+#    #+#             */
/*   Updated: 2022/10/24 20:18:27 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../mlx/mlx.h"

# define BUFFER_SIZE 1

typedef struct s_texture
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}	t_texture;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**cub;
	char		*cub_raw;
	int			width;
	int			height;
	// TEXTURAS
	char		*tnorth;
	char		*tsouth;
	char		*teast;
	char		*twest;
	// COLORES
	char		*floor;
	char		*ceiling;
	char		**map;
}	t_game;

// CHECK MAP
void	check_map(t_game *game);

// CHECK
int		check_parameters(int argc, char **argv);
void	open_map(t_game *game, char **argv);

// CLOSE
void	close_cub3d(int value);

// GET_NEXT_LINE
char	*get_next_line(int fd);

// INFO CUB
void	get_map(t_game *game);
void	get_colours(t_game *game);
void	get_textures(t_game *game);

// READ
void	get_cub_info(t_game *game, char **argv);

// UTILS
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
