/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:37:13 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/02 21:32:16 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include "raycast.h"
#include "window.h"
#include "player.h"
#include "game.h"
#include "vector.h"
#include "textures.h"
#include "render.h"

/**
 * @brief Pinta un pixel en una imagen
 * 
 * @param img puntero de la imagen que queremos pintar
 * @param x posicion en x donde pintar
 * @param y posicion en y donde pintar
 * @param color color del pixel
 */
void	ft_render_pixel(t_image *img, int x, int y, int color)
{
	int	pixel;

	pixel = (y * img->line_size) + (x * 4);
	img->pixels[pixel + 0] = (color) & 0xFF;
	img->pixels[pixel + 1] = (color >> 8) & 0xFF;
	img->pixels[pixel + 2] = (color >> 16) & 0xFF;
	img->pixels[pixel + 3] = (color >> 24);
}

/**
 * @brief Pinta en una imagen el cielo del cub3D
 * 
 * @param img imagen donde pintar
 * @param x posicion en x donde pintar
 * @param start_draw posicion en y donde empieza el cielo
 * @param color color del cielo
 */
void	ft_render_ceil(t_image *img, int x, int start_draw, int color)
{
	int	y;

	y = 0;
	while (y >= 0 && y < HEIGHT && y < start_draw)
	{
		ft_render_pixel(img, x, y, color);
		y++;
	}
}

/**
 * @brief Pinta en una imagen el suelo del cub3D
 * 
 * @param img imagen donde pintar
 * @param x posicion en x donde pintar
 * @param y posicion en y donde empezar a pintara
 * @param color color del suelo
 */
void	ft_render_floor(t_image *img, int x, int y, int color)
{
	while (y > 0 && y < HEIGHT)
	{
		ft_render_pixel(img, x, y, color);
		y++;
	}
}

/**
 * @brief Pinta en una imagen los muros del cub3D
 * 
 * @param raycast informacion del muro obtenida con el raycast
 * @param player informacion del jugador
 * @param x posicion en x
 * @param img imagen donde pintar
 * @param texture informacion de la textura que pintar
 */
void	ft_render_walls(
	t_raycast_pos raycast_pos, t_player player, t_image *img, t_image texture)
{
	double			step;
	double			text_pos;
	int				y;
	t_int_vector	text;
	t_texture_x		texture_x;

	texture_x.perp_wall_dist = raycast_pos.raycast.perp_wall_dist;
	texture_x.side = raycast_pos.raycast.side_2;
	text.x = ft_get_texture_x(texture_x, player.pos,
			raycast_pos.raycast.ray, texture.height);
	step = ft_get_texture_steep(raycast_pos.raycast.line_h,
			texture.bits_per_pixel, texture.line_size);
	text_pos = ft_get_texture_position(
			raycast_pos.raycast.start_draw, raycast_pos.raycast.line_h, step);
	y = raycast_pos.raycast.start_draw;
	while (y < raycast_pos.raycast.end_draw && y < HEIGHT)
	{
		text.y = ft_get_texture_y(text_pos, texture.height);
		text_pos += step;
		ft_render_pixel(
			img, raycast_pos.x, y,
			ft_get_color_image(texture, text, texture.height)
			);
		y++;
	}
}

/**
 * @brief Pinta el mapa del cub3D
 * 
 * @param game informacion del juego
 * @return int 
 */
int	ft_render_map(t_game *game)
{
	t_raycast_pos	raycast_pos;

	mlx_clear_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	game->img.pointer = mlx_new_image(game->mlx.mlx_ptr, WIDTH, HEIGHT);
	game->img.pixels = mlx_get_data_addr(game->img.pointer,
			&game->img.bits_per_pixel, &game->img.line_size, &game->img.endian);
	raycast_pos.x = 1;
	while (raycast_pos.x < WIDTH)
	{
		raycast_pos.raycast = ft_get_ray(game, raycast_pos.x);
		ft_render_floor(&game->img, raycast_pos.x,
			raycast_pos.raycast.start_draw, game->map.textures.floor);
		ft_render_ceil(&game->img, raycast_pos.x,
			raycast_pos.raycast.end_draw, game->map.textures.ceil);
		if (raycast_pos.raycast.side_2 == 1 && raycast_pos.raycast.step.y == 1)
			ft_render_walls(raycast_pos, game->player,
				&game->img, game->map.textures.east);
		if (raycast_pos.raycast.side_2 == 1 && raycast_pos.raycast.step.y == -1)
			ft_render_walls(raycast_pos, game->player,
				&game->img, game->map.textures.west);
		if (raycast_pos.raycast.side_2 == 0 && raycast_pos.raycast.step.x == 1)
			ft_render_walls(raycast_pos, game->player,
				&game->img, game->map.textures.north);
		if (raycast_pos.raycast.side_2 == 0 && raycast_pos.raycast.step.x == -1)
			ft_render_walls(raycast_pos, game->player,
				&game->img, game->map.textures.south);
		raycast_pos.x++;
	}
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->img.pointer, 0, 0);
	mlx_destroy_image(game->mlx.mlx_ptr, game->img.pointer);
	return (0);
}
