
#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx/mlx.h"
# include "./ft_printf/include/ft_printf.h"
# include "./get_next_line/get_next_line.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_player
{
    int		l_x;
    int		l_y;
    int		point;
    void	*player_front;
    void	*player_back;
    void	*player_left;
    void	*player_right;
    void	*player_current;
}	t_player;

typedef struct s_map
{
    char	**map_matrix;
    int		width;
    int		height;
    int		collectible;
    int		gate_x;
    int		gate_y;
    int		player_count;
    int		exit_count;
    int		coin_count;
}	t_map;

typedef struct s_win
{
    t_map	    *map;
    t_player	*player;
    void	    *window;
    void	    *mlx;
    void	    *img_bg;
    void	    *block_bg;
    void	    *player_bg;
    void	    *exit_bg;
    int		    height;
    int		    width;
}	t_win;

//Actual
void    ft_filepath_checker(char *filepath);
void    ft_ber_extension_checker(char *path);
void    ft_set_window(t_win* window, char *map_path);
void	get_img(t_win *pnc, int width_for_images, int height_for_images);
void	render_map(t_win *pnc);
int	close_frame(void *param);
void	putchr(t_win *pnc, int keycode);
void	print_score(t_win *pnc);
void	move_p(t_win *pnc, int side, int x, int y);
int	walk(int keycode, void *param);
void	player_control(t_win *pnc);
void	wall_control(t_win *pnc);
void	map_size_control(t_win *pnc);
void	end_control(t_win *pnc);
void	coin_control(t_win *pnc);
void	char_control(t_win *pnc);
void	put_element(char c, t_win *pnc, int x, int y);
void	put_score(t_win *pnc);
#endif