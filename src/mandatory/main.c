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
    int *texture[8];
    int worldMap[mapWidth][mapHeight]=
    {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
    {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
    };

    double posX_x = 22, pos_y = 12;  //x and y start position
    double dir_x = -1, dir_y = 0; //initial direction vector
    double planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane

    double time = 0; //time of current frame
    double oldTime = 0; //time of previous frame
    screen(screenWidth, screenHeight, 0, "Raycaster"); //la pantalla se crea especificando la resolución con la función screen()

    while(!done())
  {
        for(int x = 0; x < w; x++)
        {
            //calculate ray position and direction
            double cameraX = 2 * x / double(w) - 1; //x-coordinate in camera space
            double rayDirX = dir_x + planeX * cameraX;
            double rayDirY = dir_y + planeY * cameraX;
        }
    }
}

// void	my_mlx_pixel_put(t_info *info, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = (char *)info->global.addr
// 		+ (y * info->global.line_length + x * (info->global.bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }


//     dim = 100;
//     mlx = mlx_init();
//     mlx_win = mlx_new_window(mlx, 500, 500, "Cub3D");
//     t_image img;
//     t_image img2;
//     void *img_r = mlx_xpm_file_to_image(mlx, "./src/assets/textures/west.xpm", &dim, &dim);
//     img.pointer = mlx_new_image(mlx, 64 * 3, 64 * 3);
//     img.pixels = mlx_get_data_addr(img.pointer, &img.bits_per_pixel, &img.line_size, &img.endian);
//     img2.pixels = mlx_get_data_addr(img_r, &img2.bits_per_pixel, &img2.line_size, &img2.endian);

//     printf("%s\n", img.pixels);
//     printf("%i\n", img.bits_per_pixel);
//     printf("%i\n", img.line_size);
//     printf("%i\n", img.endian);
//     mlx_put_image_to_window(mlx, mlx_win, img_r, 5, 5);

//     for (size_t x = 0; x < 64 * 3; x++)
//     {
//         for (size_t y = 0; y < 64 * 3; y++)
//         {
//             // Extraer el color de la imagen porque luego va a ser distorsionada
//             int c = *(unsigned int *)(img2.pixels + (y / 3 * img2.line_size + x / 3 * (img2.bits_per_pixel / 8)));
            
//             // OPCION 1 con pixeles
//             mlx_pixel_put(mlx, mlx_win, 100 + x, 100 + y, c);

//             // OPCION 2 con la imagen
//             int pixel = (y * img.line_size) + (x * 4);
//             int color = 0xABCDEF; // ignoramos esto
//             if (img.bits_per_pixel != 32) // ignoramos esto
//                 color = mlx_get_color_value(mlx, color); // ignoramos esto
				
//             if (img.endian == 1) // Most significant (Alpha) byte first
//             {
//                 img.pixels[pixel + 0] = (c >> 24);
//                 img.pixels[pixel + 1] = (c >> 16) & 0xFF;
//                 img.pixels[pixel + 2] = (c >> 8) & 0xFF;
//                 img.pixels[pixel + 3] = (c)&0xFF;
//             }
//             else if (img.endian == 0) // Least significant (Blue) byte first
//             {
//                 img.pixels[pixel + 0] = (c)&0xFF;
//                 img.pixels[pixel + 1] = (c >> 8) & 0xFF;
//                 img.pixels[pixel + 2] = (c >> 16) & 0xFF;
//                 img.pixels[pixel + 3] = (c >> 24);
//             }
//         }
//     }
//     mlx_put_image_to_window(mlx, mlx_win, img.pointer, 0, 70);

//     mlx_loop(mlx);
//     return 0;
// }

// // int	main(int argc, char **argv)
// // {
// // 	void	*mlx;
// // 	t_game	game;

// // 	check_parameters(argc, argv);
// // 	get_cub_info(&game, argv);
// // 	check_map(&game);
// // 	mlx = mlx_init();
// // 	mlx_new_window(mlx, 500, 500, "Hello world!");
// // 	mlx_loop(mlx);
// //     return (0);
// // }
