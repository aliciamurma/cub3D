#include <math.h>
#include <mlx.h>
#include "raycast.h"
#include "window.h"
#include "player.h"
#include "game.h"
#include "vector.h"
#include "textures.h"

void ft_render_pixel(t_image *img, int x, int y, int color)
{
	int pixel;

	pixel = (y * img->line_size) + (x * 4);
	img->pixels[pixel + 0] = (color)&0xFF;
	img->pixels[pixel + 1] = (color >> 8) & 0xFF;
	img->pixels[pixel + 2] = (color >> 16) & 0xFF;
	img->pixels[pixel + 3] = (color >> 24);
}

void ft_render_ceil(t_image *img, int x, int start_draw, int color)
{
	int y;

	y = 0;
	while (y < start_draw)
	{
		ft_render_pixel(img, x, y, color);
		y++;
	}
}
void ft_render_floor(t_image *img, int x, int y, int color)
{
	while (y > 0 && y < HEIGHT)
	{
		ft_render_pixel(img, x, y, color);
		y++;
	}
}

void ft_render_walls(t_raycast raycast, t_player player, int x, t_image *img, t_image texture)
{
	double step;
	double text_pos;
	int y;
	t_int_vector text;

	text.x = ft_get_texture_x(raycast.side_2, player.pos, raycast.perp_wall_dist, raycast.ray);
	step = ft_get_texture_steep(raycast.line_h);
	text_pos = ft_get_texture_position(raycast.start_draw, raycast.line_h, step);
	y = raycast.start_draw;
	while (y < raycast.end_draw && y < HEIGHT)
	{
		text.y = ft_get_texture_y(text_pos);
		text_pos += step;
		ft_render_pixel(img, x, y,
						ft_get_color_image(texture, text));
		y++;
	}
}

int	ft_render_map(t_game *game)
{
	int			x;
	t_raycast	raycast;
	static int	a;

	a = 0;
	if (a != 0)
		mlx_destroy_image(game->mlx.mlx_ptr, game->img.pointer);
	mlx_clear_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	game->img.pointer = mlx_new_image(game->mlx.mlx_ptr, WIDTH, HEIGHT);
	game->img.pixels = mlx_get_data_addr(game->img.pointer,
			&game->img.bits_per_pixel, &game->img.line_size, &game->img.endian);
	x = 1;
	while (x < WIDTH)
	{
		raycast = ft_get_ray(game, x);
		ft_render_floor(&game->img, x, raycast.start_draw, game->map.textures.floor);
		ft_render_ceil(&game->img, x, raycast.end_draw, game->map.textures.ceil);
		ft_render_walls(raycast, game->player, x, &game->img, game->map.textures.south);
		x++;
	}
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->img.pointer, 0, 0);
	a = 1;
	return (0);
}
