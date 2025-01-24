#include "mlx.h"


int main(void)
{
    void *mlx;
    void *window;

    // Initialize the MiniLibX connection
    mlx = mlx_init();
    if (!mlx)
        return (1);

    // Create a window (width: 800px, height: 600px, title: "so_long")
    window = mlx_new_window(mlx, 800, 600, "so_long");
    if (!window)
        return (1);

    // Keep the window open
    mlx_loop(mlx);
    return (0);
}