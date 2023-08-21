#include "so_long.h"

void	render_map(t_win *pnc)
{
    int	i;
    int	j;
    int	x;
    int	y;

    i = 0;
    j = 0;
    x = 0;
    y = 0;
    while (pnc->map->map_matrix[i])
    {
        j = 0;
        x = 0;
        while (pnc->map->map_matrix[i][j])
        {
            put_element(pnc->map->map_matrix[i][j++], pnc, x, y);
            put_score(pnc);
            x += 64;
        }
        i++;
        y = y + 64;
    }
}

void	put_element(char c, t_win *pnc, int x, int y)
{
    mlx_put_image_to_window(pnc->mlx, pnc->window, pnc->img_bg, x, y);
    if (c == 'P')
    {
        pnc->player->l_x = x;
        pnc->player->l_y = y;
        mlx_put_image_to_window(pnc->mlx, pnc->window, pnc->player->player_current, x, y);
    }
    if (c == '1')
        mlx_put_image_to_window(pnc->mlx, pnc->window, pnc->block_bg, x, y);
    if (c == 'C')
        mlx_put_image_to_window(pnc->mlx, pnc->window, pnc->player_bg, x, y);
    if (c == 'E')
    {
        pnc->map->gate_x = x;
        pnc->map->gate_y = y;
        mlx_put_image_to_window(pnc->mlx, pnc->window, pnc->exit_bg, x, y);
    }
}

void	put_score(t_win *pnc)
{
    char	*score;

    score = ft_itoa(pnc->player->point);
    mlx_string_put(pnc->mlx, pnc->window, 20, 20, 0xFFFFFFFF, score);
    free(score);
}

int	close_frame(void *param)
{
    t_win	*pnc;
    int		i;

    pnc = param;
    i = 0;
    mlx_destroy_image(pnc->mlx, pnc->player->player_front);
    mlx_destroy_image(pnc->mlx, pnc->player->player_back);
    mlx_destroy_image(pnc->mlx, pnc->player->player_right);
    mlx_destroy_image(pnc->mlx, pnc->player->player_left);
    mlx_destroy_image(pnc->mlx, pnc->player_bg);
    mlx_destroy_image(pnc->mlx, pnc->exit_bg);
    mlx_destroy_image(pnc->mlx, pnc->block_bg);
    mlx_destroy_image(pnc->mlx, pnc->img_bg);
    free(pnc->player);
    while (pnc->map->map_matrix[i])
        free(pnc->map->map_matrix[i++]);
    free(pnc->map->map_matrix);
    free(pnc->map);
    mlx_destroy_window(pnc->mlx, pnc->window);
    exit(1);
    return (1);
}