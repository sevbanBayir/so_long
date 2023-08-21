#include "so_long.h"

void	putchr(t_win *pnc, int keycode)
{
    if (keycode == 2)
        pnc->player->player_current = pnc->player->player_right;
    if (keycode == 0)
        pnc->player->player_current = pnc->player->player_left;
    if (keycode == 13)
        pnc->player->player_current = pnc->player->player_back;
    if (keycode == 1)
        pnc->player->player_current = pnc->player->player_front;
}

void	print_score(t_win *pnc)
{
    ft_printf("%d\n", pnc->player->point);
}

void	move_p(t_win *pnc, int side, int x, int y)
{
    if (pnc->map->collectible == 0 && pnc->map->map_matrix[y / 64][x / 64] == 'E')
    {
        pnc->player->point += 1;
        print_score(pnc);
        ft_printf("Win!");
        close_frame(pnc);
    }
    if (pnc->map->map_matrix[y / 64][x / 64] != '1'
        && pnc->map->map_matrix[y / 64][x / 64] != 'E')
    {
        putchr(pnc, side);
        pnc->player->point += 1;
        if (pnc->map->map_matrix[y / 64][x / 64] == 'C')
            pnc->map->collectible -= 1;
        pnc->map->map_matrix[pnc->player->l_y / 64][pnc->player->l_x / 64] = '0';
        pnc->map->map_matrix[pnc->map->gate_y / 64][pnc->map->gate_x / 64] = 'E';
        pnc->map->map_matrix[y / 64][x / 64] = 'P';
        print_score(pnc);
    }
}

int	walk(int keycode, void *param)
{
    t_win	*pnc;

    pnc = param;
    mlx_clear_window(pnc->mlx, pnc->window);
    if (keycode == 2)
        move_p(pnc, keycode, pnc->player->l_x + 64, pnc->player->l_y);
    if (keycode == 0)
        move_p(pnc, keycode, pnc->player->l_x - 64, pnc->player->l_y);
    if (keycode == 13)
        move_p(pnc, keycode, pnc->player->l_x, pnc->player->l_y - 64);
    if (keycode == 1)
        move_p(pnc, keycode, pnc->player->l_x, pnc->player->l_y + 64);
    if (keycode == 53)
        close_frame(pnc);
    render_map(pnc);
    return (keycode);
}