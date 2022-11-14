#include <mlx.h>
#include <stdio.h>
#include <math.h>
#include "exit.h"

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
 * @return int 
 */
int main(void)
{
    void *mlx;
    void *mlx_win;
    int dim;

    dim = 100;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 500, 500, "Cub3D");
	exit_cub3d(1);
    t_image img;
    t_image img2;
    void *img_r = mlx_xpm_file_to_image(mlx, "./src/assets/textures/west.xpm", &dim, &dim);
    img.pointer = mlx_new_image(mlx, 64 * 3, 64 * 3);
    img.pixels = mlx_get_data_addr(img.pointer, &img.bits_per_pixel, &img.line_size, &img.endian);
    img2.pixels = mlx_get_data_addr(img_r, &img2.bits_per_pixel, &img2.line_size, &img2.endian);

    printf("%s\n", img.pixels);
    printf("%i\n", img.bits_per_pixel);
    printf("%i\n", img.line_size);
    printf("%i\n", img.endian);
    mlx_put_image_to_window(mlx, mlx_win, img_r, 5, 5);

    for (size_t x = 0; x < 64 * 3; x++)
    {
        for (size_t y = 0; y < 64 * 3; y++)
        {
            // Extraer el color de la imagen porque luego va a ser distorsionada
            int c = *(unsigned int *)(img2.pixels + (y / 3 * img2.line_size + x / 3 * (img2.bits_per_pixel / 8)));
            
            // OPCION 1 con pixeles
            mlx_pixel_put(mlx, mlx_win, 100 + x, 100 + y, c);

            // OPCION 2 con la imagen
            int pixel = (y * img.line_size) + (x * 4);
            int color = 0xABCDEF; // ignoramos esto
            if (img.bits_per_pixel != 32) // ignoramos esto
                color = mlx_get_color_value(mlx, color); // ignoramos esto
				
            if (img.endian == 1) // Most significant (Alpha) byte first
            {
                img.pixels[pixel + 0] = (c >> 24);
                img.pixels[pixel + 1] = (c >> 16) & 0xFF;
                img.pixels[pixel + 2] = (c >> 8) & 0xFF;
                img.pixels[pixel + 3] = (c)&0xFF;
            }
            else if (img.endian == 0) // Least significant (Blue) byte first
            {
                img.pixels[pixel + 0] = (c)&0xFF;
                img.pixels[pixel + 1] = (c >> 8) & 0xFF;
                img.pixels[pixel + 2] = (c >> 16) & 0xFF;
                img.pixels[pixel + 3] = (c >> 24);
            }
        }
    }
    mlx_put_image_to_window(mlx, mlx_win, img.pointer, 0, 70);

    mlx_loop(mlx);
    return 0;
}