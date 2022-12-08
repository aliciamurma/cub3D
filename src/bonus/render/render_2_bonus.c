/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aramirez <aramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:34:43 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/08 20:18:21 by aramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "render_bonus.h"
#include "game_bonus.h"
#include "raycast_bonus.h"
#include "minimap_bonus.h"

/**
 * @brief Lanzamos todos los rayos
 * 
 * @param raycast_pos 
 * @param game 
 */
void	ft_render_multiple_rays(t_raycast_pos raycast_pos, t_game *game)
{
	while (raycast_pos.x < WIDTH)
	{
		ft_render_ray(game, raycast_pos);
		raycast_pos.x++;
	}
}

/**
 * @brief Printamos minimapa pequeño o grande
 * 
 * @param game 
 */
void	ft_choose_minimap(t_game *game)
{
	if (game->minimap == 1)
		ft_render_static_minimap(game->mlx, game->map, game->player.pos);
	if (game->minimap == 2)
		ft_render_minimap(game->mlx, game->map, game->player.pos);
}

/**
 * @brief Frame par: printamos rifle 1
 * 
 * @param frames 
 * @param mlx 
 * @return int 
 */
int	ft_frame_pair(int frames, t_window mlx)
{
	ft_render_weapon(mlx, "./src/assets/weapons/rifle/rifle_1.xpm");
	return (++frames);
}

/**
 * @brief Frame impar: printamos rifle 2
 * 
 * @param mlx 
 * @return true 
 * @return false 
 */
bool	ft_frame_odd(t_window mlx)
{
	ft_render_weapon(mlx, "./src/assets/weapons/rifle/rifle_2.xpm");
	return (false);
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
	static int		frames = 0;

	mlx_clear_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
	game->img.pointer = mlx_new_image(game->mlx.mlx_ptr, WIDTH, HEIGHT);
	game->img.pixels = mlx_get_data_addr(game->img.pointer,
			&game->img.bits_per_pixel, &game->img.line_size, &game->img.endian);
	raycast_pos.x = 1;
	ft_render_multiple_rays(raycast_pos, game);
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->img.pointer, 0, 0);
	if (game->player.is_shooting)
	{
		if (frames % 2 == 0)
			frames = ft_frame_pair(frames, game->mlx);
		else
			game->player.is_shooting = ft_frame_odd(game->mlx);
	}
	else
		ft_render_weapon(game->mlx, "./src/assets/weapons/rifle/rifle_1.xpm");
	ft_choose_minimap(game);
	mlx_destroy_image(game->mlx.mlx_ptr, game->img.pointer);
	return (0);
}
