#include <mlx.h>
#include <stdio.h>

typedef struct s_image
{
    void *pointer;
    // t_vector  size;
    char *pixels;
    int bits_per_pixel;
    int line_size;
    int endian;
} t_image;

int main(void)
{
    void *mlx;
    void *mlx_win;
    int dim;

    dim = 100;
    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");

    t_image img;
    t_image img2;
    void *img_r = mlx_xpm_file_to_image(mlx, "./src/assets/textures/west.xpm", &dim, &dim);
    img.pointer = mlx_new_image(mlx, 64, 64);
    img.pixels = mlx_get_data_addr(img.pointer, &img.bits_per_pixel, &img.line_size, &img.endian);
    img2.pixels = mlx_get_data_addr(img_r, &img2.bits_per_pixel, &img2.line_size, &img2.endian);

    printf("%s\n", img.pixels);
    printf("%i\n", img.bits_per_pixel);
    printf("%i\n", img.line_size);
    printf("%i\n", img.endian);
    mlx_put_image_to_window(mlx, mlx_win, img_r, 5, 5);

    for (size_t x = 0; x < 64; x++)
    {
        for (size_t y = 0; y < 64; y++)
        {
            // Extraer el color de la imagen
            int c = *(unsigned int *)(img2.pixels + (y * img.line_size + x * (img.bits_per_pixel / 8)));
            mlx_pixel_put(mlx, mlx_win, 100 + x, 100 + y, c);
        }
    }

    mlx_loop(mlx);
    return 0;
}