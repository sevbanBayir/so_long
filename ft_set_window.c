#include "so_long.h"
char	*ft_strappend(char **str, char *str2)
{
    char	*old;

    old = *str;
    *str = ft_strjoin(old, str2);
    if (old)
        free(old);
    return (0);
}

char    **ft_read_map(char *map_path) {
    int     fd;
    char    **raw_map;
    char    *line;
    char    *lines;

    lines = malloc(sizeof(char *));
    fd = open(map_path, O_RDWR);
    if (fd == -1)
        exit(1);
    while((line = get_next_line(fd))) {
        lines = ft_strjoin(lines, line);
    }
    raw_map = ft_split(lines, '\n');
    return (raw_map);
}

t_map    *ft_read_adjust_map(char* map_path) {
    t_map   *map;
    int     height;
    int     width;

    map = ft_calloc(1, sizeof(t_map));
    height = 0;
    width = 0;
    map->map_matrix = ft_read_map(map_path);

    while (map->map_matrix[height]) {
        while(map->map_matrix[height][width]) //Theoratically all lines' width must be equal.
            width++;                           //Eğer tüm linelar eşit değilse eşit olmayanın uzunluğuna eşitler burası.
        height++;                              //Bu yüzden, ilk line'dan sonraki linelar için "null değilse hata ver" diyebiliriz.
    }
    map->height = height;
    map->width = width;
    return (map);
}

void	get_img(t_win *pnc, int width_for_images, int height_for_images)
{
    pnc->height = pnc->map->height * 64;
    pnc->width = pnc->map->width * 64;
    pnc->mlx = mlx_init();
    pnc->window = mlx_new_window(pnc->mlx, pnc->width, pnc->height, "Slime Game");
    pnc->player = ft_calloc(1, sizeof(t_player));
    pnc->player->l_x = 0;
    pnc->player->l_y = 0;
    pnc->player->point = 0;
    pnc->player->player_front = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/front_char.xpm", &width_for_images, &height_for_images);
    pnc->player->player_back = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/back_char.xpm", &width_for_images, &height_for_images);
    pnc->player->player_right = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/right_char.xpm", &width_for_images, &height_for_images);
    pnc->player->player_left = mlx_xpm_file_to_image(pnc->mlx, \
			"./img/left_char.xpm", &width_for_images, &height_for_images);
    pnc->player->player_current = pnc->player->player_front;
    pnc->img_bg = mlx_xpm_file_to_image(pnc->mlx, "./img/bg.xpm", &width_for_images, &height_for_images);
    pnc->block_bg = mlx_xpm_file_to_image(pnc->mlx, "./img/block.xpm", &width_for_images, &height_for_images);
    pnc->player_bg = mlx_xpm_file_to_image(pnc->mlx, "./img/coin.xpm", &width_for_images, &height_for_images);
    pnc->exit_bg = mlx_xpm_file_to_image(pnc->mlx, "./img/endgate.xpm", &width_for_images, &height_for_images);
}

void    ft_set_window(t_win* window, char *map_path) {
    int width_for_images;
    int height_for_images;

    window->map = ft_read_adjust_map(map_path);
    get_img(window, width_for_images, height_for_images);
    player_control(window);
    map_size_control(window);
    wall_control(window);
    end_control(window);
    coin_control(window);
    char_control(window);
}

