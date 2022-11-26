// #include <mlx.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

#include "game.h"
#include "validators.h"
// #include "exit.h"
// #include "raycast.h"
// #include "window.h"
// #include "inputs.h"
// #include "player.h"
#include "helpers.h"

// typedef struct s_image
// {
//     void *pointer;
//     // t_vector  size;
//     char *pixels;
//     int bits_per_pixel;
//     int line_size;
//     int endian;
// } t_image;


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
// int main(void)
int main(int argc, char **argv)
{
    t_game  game;

    ft_check_parameters(argc, argv[1]);
	ft_set_cub_info(&game, argv[1]);
	// ft_check_map(&game.map);
    // game.map.map = malloc(sizeof(char *) * 25);

    // game.map.map[0] = "111111111111111111111111";
    // game.map.map[1] = "100000000000000000000001";
    // game.map.map[2] = "100000000000000000000001";
    // game.map.map[3] = "100000000011000000000001";
    // game.map.map[4] = "100000000010000000010001";
    // game.map.map[5] = "1000000000100N0000010001";
    // game.map.map[6] = "100000000010000000010001";
    // game.map.map[7] = "100000000011000000000001";
    // game.map.map[8] = "100000000000000000000001";
    // game.map.map[9] = "100000000000000000000001";
    // game.map.map[10] = "100000000111111100000001";
    // game.map.map[11] = "100000000000000000000001";
    // game.map.map[12] = "100000000000000000000001";
    // game.map.map[13] = "100000000000000000000001";
    // game.map.map[14] = "100000000000000000000001";
    // game.map.map[15] = "100000000000000000000001";
    // game.map.map[16] = "100000000000000000000001";
    // game.map.map[17] = "100000000000000000000001";
    // game.map.map[18] = "100000000000000000000001";
    // game.map.map[19] = "100000000000000000000001";
    // game.map.map[20] = "100000000000000000000001";
    // game.map.map[21] = "100000000000000000000001";
    // game.map.map[22] = "100000000000000000000001";
    // game.map.map[23] = "111111111111111111111111";
    // game.map.map[24] = NULL;
    // game.player.pos.x = 12;
    // game.player.pos.y = 5;
    // game.player.dir.x = -1;
    // game.player.dir.y = 0;
    // game.player.plane.x = 0;
    // game.player.plane.y = 0.66;
    // game.mlx.mlx_ptr = mlx_init();
    // game.mlx.win_ptr = mlx_new_window(game.mlx.mlx_ptr, WIDTH, HEIGHT, NAME_WIN);
    // game.player.movement.forward = false;
    // game.player.movement.backward = false;
    // game.player.movement.right = false;
    // game.player.movement.left = false;
    // game.player.rotation.right = false;
    // game.player.rotation.left = false;
   
    // mlx_loop_hook(game.mlx.mlx_ptr, &ft_game_loop, &game);
    // mlx_hook(game.mlx.win_ptr, 2, 0, handle_keydown, &game);
    // mlx_hook(game.mlx.win_ptr, 3, 0, handle_keyup, &game);
	// mlx_hook(game.mlx.win_ptr, 17, 0, handle_close, &game);
    // mlx_loop(game.mlx.mlx_ptr);
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


// typedef struct s_image
// {
// 	void	*pointer;
// 	// t_vector  size;
// 	char	*pixels;
// 	int		bits_per_pixel;
// 	int		line_size;
// 	int		endian;
// }			t_image;

// int	key_hook(int keycode, int *vars)
// {
// 	(void)vars;
// 	printf("Hello from key_hook! %i\n", keycode);
// 	return (0);
// }

// int	render_next_frame(int *vars)
// {
// 	(void)vars;
// 	printf("Hello from key_hook!\n");
// 	return (0);
// }
// int	close_cub(int *vars)
// {
// 	(void)vars;
// 	printf("Exit!\n");
// 	return (0);
// }
// int	mouse_hook(int keycode, int *vars)
// {
// 	(void)vars;
// 	printf("Hello from mouse_hook! %i\n", keycode);
// 	return (0);
// }
// int	mouse_event(int x, int y, int *vars)
// {
// 	(void)vars;
// 	printf("Hello from mouse_event! x: %i y: %i\n", x, y);
// 	return (0);
// }

// /**
//  * @brief 
//  * mlx_init --> Inicializamos mlx
//  * mlx_new_window --> Abrimos la ventana
//  * mlx_new_image --> PARA QUE??
//  * mlx_xpm_file_to_image y mlx_get_data_addr --> Carga la imagen
//  * mlx_loop --> Crea un bucle para que no se cierre el juego
//  * mlx_put_image_to_window --> Pone la imagen en la ventana
//  * @return int 
//  */
// int	main(void)
// {
// 	void *mlx;
// 	void *mlx_win;
// 	int dim;

// 	dim = 100;
// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 500, 500, "Cub3D");
// 	t_image img;
// 	t_image img2;
// 	void *img_r = mlx_xpm_file_to_image(mlx, "./src/assets/textures/west.xpm",
// 			&dim, &dim);
// 	img.pointer = mlx_new_image(mlx, 64 * 3, 64 * 3);
// 	img.pixels = mlx_get_data_addr(img.pointer, &img.bits_per_pixel,
// 			&img.line_size, &img.endian);
// 	img2.pixels = mlx_get_data_addr(img_r, &img2.bits_per_pixel,
// 			&img2.line_size, &img2.endian);

// 	printf("%s\n", img.pixels);
// 	printf("%i\n", img.bits_per_pixel);
// 	printf("%i\n", img.line_size);
// 	printf("%i\n", img.endian);
// 	mlx_put_image_to_window(mlx, mlx_win, img_r, 5, 5);

// 	for (size_t x = 0; x < 64 * 3; x++)
// 	{
// 		for (size_t y = 0; y < 64 * 3; y++)
// 		{
// 			// Extraer el color de la imagen porque luego va a ser distorsionada
// 			int c = *(unsigned int *)(img2.pixels + (y / 3 * img2.line_size + x
// 						/ 3 * (img2.bits_per_pixel / 8)));

// 			// OPCION 1 con pixeles
// 			mlx_pixel_put(mlx, mlx_win, 100 + x, 100 + y, c);

// 			// OPCION 2 con la imagen
// 			int pixel = (y * img.line_size) + (x * 4);
// 			int color = 0xABCDEF;                        // ignoramos esto
// 			if (img.bits_per_pixel != 32)                // ignoramos esto
// 				color = mlx_get_color_value(mlx, color); // ignoramos esto

// 			if (img.endian == 1) // Most significant (Alpha) byte first
// 			{
// 				img.pixels[pixel + 0] = (c >> 24);
// 				img.pixels[pixel + 1] = (c >> 16) & 0xFF;
// 				img.pixels[pixel + 2] = (c >> 8) & 0xFF;
// 				img.pixels[pixel + 3] = (c)&0xFF;
// 			}
// 			else if (img.endian == 0) // Least significant (Blue) byte first
// 			{
// 				img.pixels[pixel + 0] = (c)&0xFF;
// 				img.pixels[pixel + 1] = (c >> 8) & 0xFF;
// 				img.pixels[pixel + 2] = (c >> 16) & 0xFF;
// 				img.pixels[pixel + 3] = (c >> 24);
// 			}
// 		}
// 	}
// 	mlx_put_image_to_window(mlx, mlx_win, img.pointer, 0, 70);

// 	mlx_hook(mlx_win, 2, 0, key_hook, &dim);
// 	mlx_hook(mlx_win, 3, 0, key_hook, &dim);
// 	mlx_hook(mlx_win, 17, 0, close_cub, &dim);
// 	mlx_hook(mlx_win, 6, 0, mouse_event, &dim);
//     mlx_mouse_hook(mlx_win, mouse_hook, &dim);
// 	// mlx_hook(mlx_win, 17, 0, key_hook, &dim);
// 	// mlx_loop_hook(mlx, render_next_frame, &dim);
// 	mlx_loop(mlx);
// 	return (0);
// }