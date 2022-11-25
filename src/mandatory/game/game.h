#ifndef GAME_H
# define GAME_H

# include "maps.h"
# include "player.h"
# include "window.h"

typedef struct s_image
{
	void	*pointer;
	// t_vector  size;
	char	*pixels;
	int		bits_per_pixel;
	int		line_size;
	int		endian;
}			t_image;

typedef struct s_game
{
    t_player    player;
    t_map       map;
    t_window    mlx;
    t_image     img;
}	t_game;

int ft_game_loop(t_game *game);

#endif