#include "so_long.h"

int main(int argc, char*argv[]) {
    t_win window;

    if (argc != 2) {
        ft_printf("Wrong arguments... \n Usage: ./so_long <mymap.ber>");
        exit(1);
    }
    ft_filepath_checker(argv[1]);
    ft_ber_extension_checker(argv[1]);
    ft_set_window(&window, argv[1]);
    render_map(&window);
    mlx_hook(window.window, 2, (1L << 0), walk, &window);
    mlx_hook(window.window, 17, 0, close_frame, &window);
    mlx_loop(window.mlx);
}
