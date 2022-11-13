#include <mlx.h>

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
    int     dim;

    dim = 100;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 500, 500, "Hello world!");

    void *img = mlx_xpm_file_to_image(mlx, "../../assets/west.xpm", &dim, &dim);
    mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
	mlx_loop(mlx);
    return 0;
}