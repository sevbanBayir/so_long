#include "so_long.h"

void	player_control(t_win *pnc)
{
    int	i;
    int	j;

    i = 0;
    j = 0;
    while (pnc->map->map_matrix[i])
    {
        while (pnc->map->map_matrix[i][j])
        {
            if (pnc->map->map_matrix[i][j] == 'P')
            {
                pnc->map->player_count += 1;
            }
            j++;
        }
        i++;
        j = 0;
    }
    if (pnc->map->player_count != 1)
    {
        ft_printf("Player Count Error");
        close_frame(pnc);
    }
}

void	wall_control(t_win *pnc)
{
    int	i;
    int	last;

    i = -1;
    while (pnc->map->map_matrix[0][++i])
    {
        if (pnc->map->map_matrix[0][i] != '1' ||
            pnc->map->map_matrix[pnc->map->height - 1][i] != '1')
        {
            ft_printf("Wall Error");
            close_frame(pnc);
        }
    }
    i = -1;
    last = pnc->map->width - 1;
    while (pnc->map->map_matrix[++i])
    {
        if (pnc->map->map_matrix[i][0] != '1' || pnc->map->map_matrix[i][last] != '1')
        {
            ft_printf("Wall Error");
            close_frame(pnc);
        }
    }
}

void	map_size_control(t_win *pnc)
{
    int	i;
    int	len;

    i = 0;
    len = pnc->map->width;
    while (pnc->map->map_matrix[i])
    {
        if (ft_strlen(pnc->map->map_matrix[i]) != len)
        {
            ft_printf("Line Size Error");
            close_frame(pnc);
        }
        i++;
    }
}

void	end_control(t_win *pnc)
{
    int	i;
    int	j;

    i = -1;
    j = -1;
    while (pnc->map->map_matrix[++i])
    {
        while (pnc->map->map_matrix[i][++j])
        {
            if (pnc->map->map_matrix[i][j] == 'E')
            {
                pnc->map->exit_count = pnc->map->exit_count + 1;
            }
        }
        j = 0;
    }
    if (pnc->map->exit_count < 1)
    {
        ft_printf("End Door Count Error");
        close_frame(pnc);
    }
}

void	coin_control(t_win *pnc)
{
    int	i;
    int	j;

    i = -1;
    j = -1;
    while (pnc->map->map_matrix[++i])
    {
        while (pnc->map->map_matrix[i][++j])
        {
            if (pnc->map->map_matrix[i][j] == 'C')
                pnc->map->coin_count = pnc->map->coin_count + 1;
        }
        j = 0;
    }
    if (pnc->map->coin_count <= 0)
    {
        ft_printf("Not Found Coin in Map");
        close_frame(pnc);
    }
}

void	char_control(t_win *pnc)
{
    int	i;
    int	j;

    i = -1;
    j = -1;
    while (pnc->map->map_matrix[++i])
    {
        while (pnc->map->map_matrix[i][++j])
        {
            if (pnc->map->map_matrix[i][j] != '0'
                && pnc->map->map_matrix[i][j] != '1'
                && pnc->map->map_matrix[i][j] != 'P'
                && pnc->map->map_matrix[i][j] != 'C'
                && pnc->map->map_matrix[i][j] != 'E')
            {
                ft_printf("Undefined Char");
                close_frame(pnc);
            }
        }
        j = 0;
    }
}
