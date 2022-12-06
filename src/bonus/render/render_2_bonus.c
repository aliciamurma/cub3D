/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amurcia- <amurcia-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 15:34:43 by aramirez          #+#    #+#             */
/*   Updated: 2022/12/06 18:50:02 by amurcia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "render_bonus.h"
#include "game_bonus.h"
#include "raycast_bonus.h"
#include "minimap_bonus.h"

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
	while (raycast_pos.x < WIDTH)
	{
		ft_render_ray(game, raycast_pos);
		raycast_pos.x++;
	}
	mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
		game->img.pointer, 0, 0);
	if (game->player.is_shooting)
	{
		if (frames % 2 == 0)
		{
			ft_render_weapon(game->mlx, "./src/assets/weapons/rifle/rifle_1.xpm");
			frames++;
		}
		else
		{
			ft_render_weapon(game->mlx, "./src/assets/weapons/rifle/rifle_2.xpm");
			game->player.is_shooting = false;
		}
	}
	else
		ft_render_weapon(game->mlx, "./src/assets/weapons/rifle/rifle_1.xpm");
	ft_render_minimap(game->mlx, game->map, game->player.pos);
	mlx_destroy_image(game->mlx.mlx_ptr, game->img.pointer);
	return (0);
}
