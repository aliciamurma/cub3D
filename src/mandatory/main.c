#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include "exit.h"
#include "cub3d.h"
#include "raycast.h"

typedef struct s_image
{
    void *pointer;
    // t_vector  size;
    char *pixels;
    int bits_per_pixel;
    int line_size;
    int endian;
} t_image;

int handle_keydown(int key, t_game2 *game)
{
    // 13 - arriba
    if (key == 13)
    {
        game->player.pos.x -= 0.1;
    }
    // 2 - derecha
    if (key == 2)
    {
        game->player.pos.y += 0.1;
    }
    // 0 - izquierda
    if (key == 0)
    {
        game->player.pos.y -= 0.1;
    }
    // 1 - abajo
    if (key == 1)
    {
        game->player.pos.x += 0.1;
    }
    // Rotar dereacha
    if (key == 124)
    {
        if (game->player.plane.x > -1 && game->player.plane.x < 1)
            game->player.plane.x += 0.1;
        else
            game->player.plane.x -= 0.1;

        if (game->player.plane.y > -1 && game->player.plane.x < 1)
            game->player.plane.y += 0.1;
        else
            game->player.plane.y -= 0.1;
    }
    // Rotar izquierda
    if (key == 123)
    {
        if (game->player.plane.x > 0)
            game->player.plane.x -= 0.1;
        else
            game->player.plane.x += 0.1;
        if (game->player.plane.y > 0)
            game->player.plane.y -= 0.1;
        else
            game->player.plane.y += 0.1;
    }
    // printf("input: %i\n", key);
    return 1;
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
    t_game2 game;

    game.map.map = malloc(sizeof(char *) * 25);

    game.map.map[0] = "111111111111111111111111";
    game.map.map[1] = "100000000000000000000001";
    game.map.map[2] = "100000000000000000000001";
    game.map.map[3] = "100000000011000000000001";
    game.map.map[4] = "100000000010000000010001";
    game.map.map[5] = "1000000000100N0000010001";
    game.map.map[6] = "100000000010000000010001";
    game.map.map[7] = "100000000011000000000001";
    game.map.map[8] = "100000000000000000000001";
    game.map.map[9] = "100000000000000000000001";
    game.map.map[10] = "100000000111111100000001";
    game.map.map[11] = "100000000000000000000001";
    game.map.map[12] = "100000000000000000000001";
    game.map.map[13] = "100000000000000000000001";
    game.map.map[14] = "100000000000000000000001";
    game.map.map[15] = "100000000000000000000001";
    game.map.map[16] = "100000000000000000000001";
    game.map.map[17] = "100000000000000000000001";
    game.map.map[18] = "100000000000000000000001";
    game.map.map[19] = "100000000000000000000001";
    game.map.map[20] = "100000000000000000000001";
    game.map.map[21] = "100000000000000000000001";
    game.map.map[22] = "100000000000000000000001";
    game.map.map[23] = "111111111111111111111111";
    game.map.map[24] = NULL;
    game.player.pos.x = 12;
    game.player.pos.y = 5;
    game.player.dir.x = -1;
    game.player.dir.y = 0;
    game.player.plane.x = 0;
    game.player.plane.y = 0.66;
    game.mlx.mlx_ptr = mlx_init();
    game.mlx.win_ptr = mlx_new_window(game.mlx.mlx_ptr, 800, 800, "MYCUB3D");
    mlx_loop_hook(game.mlx.mlx_ptr, &ft_render_map, &game);
    mlx_hook(game.mlx.win_ptr, 2, 0, handle_keydown, &game);
    mlx_loop(game.mlx.mlx_ptr);
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
