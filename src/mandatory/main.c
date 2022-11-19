#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include "exit.h"
#include "cub3d.h"

typedef struct s_image
{
	void *pointer;
	// t_vector  size;
	char *pixels;
	int bits_per_pixel;
	int line_size;
	int endian;
} t_image;

void    ft_print(t_game *game, int x, int start_draw, int end_draw, int colour)
{
    int y;
 
    y = start_draw;
    while (y <= end_draw)
    {
        mlx_pixel_put(pos->mlx_ptr, pos->win_ptr , x, y, colour);
        y++;
    }
}  

/**
 * @brief Recogemos la dirección del rayo
 * 
 * @param game 
 * @param x 
 * @return t_vector 
 */
t_vector	ft_get_ray_dir(t_player *player, int x)
{
    double		camera_x;
	t_vector	ray;

	camera_x = 2 * x / (double)WIDTH - 1 ;
	ray.x = player->dir.x + player->plane.x * camera_x;
	ray.y = player->dir.y + player->plane.y * camera_x;
	return (ray);
}

t_vector	ft_get_ray_abs_distance(t_vector ray)
{
	t_vector	delta;

å	delta.x = fabs(1/ray.x);
	delta.y = fabs(1/ray.y);
}

t_vector	*ft_get_real_distance(t_vector ray, t_vector delta, t_vector map)
{
	t_vector	step;
	t_vector	side;
	t_vector	distance[2];

	if (ray.x < 0)
	{
		distance[0].x = -1;
		distance[1].x = (player->pos.x - map.x) * delta.x;
	}
	else
	{
		distance[0].x = 1;
		distance[1].x = (map.x + 1.0 - player->pos.x) * delta.x;
	}
	if (ray.y < 0)
	{
		distance[0].y = -1;
		distance[1].y = (player->pos.y - map.y) * delta.y;
	}
	else
	{
		distance[0].y = 1;
		distance[1].y = (map.y + 1.0 - player->pos.y) * delta.y;
	}
	return (distance);
}

int	ft_render_map(t_game *game)
{
	int	x;
	t_vector	delta;
	t_vector	ray;
	t_vector	distance[2];
	t_vector	map;

	x = 0;
	while (x < WIDTH)
	{
		ray = ft_get_ray_dir(game->player, x);
		delta = ft_get_ray_abs_distance(ray);
		map.x = (int)player->pos.x;
		map.y = (int)player->pos.y;
		distance = ft_get_real_distance(ray, delta, map);
		ft_
	}
	return (0);
}

/**
 * @brief 
 * mlx_init --> Inicializamos mlx
 * mlx_new_window --> Abrimos la ventana
 * mlx_new_image --> PARA QUE??
 * mlx_xpm_file_to_image y mlx_get_data_addr --> Carga la imagen
 * mlx_loop --> Crea un bucle para que no se cierre el juego
 * mlx_put_image_to_window --> Pone la imagen en la ventana
 * 
 *  FOV = 2 * atan(0.66/1.0)=66.8 es adecuado para tiradores en primera persona
 * @return int 
 */
int main(void)
{
    mlx_loop_hook(window.mlx_ptr, &ft_render_map, &game);
	return (0);
}




// int	main(int argc, char **argv)
// {
// 	void	*mlx;
// 	t_game	game;

// 	check_parameters(argc, argv);
// 	get_cub_info(&game, argv);
// 	check_map(&game);
// 	mlx = mlx_init();
// 	mlx_new_window(mlx, 500, 500, "Hello world!");
// 	mlx_loop(mlx);
//     return (0);
// }
