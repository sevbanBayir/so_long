#include "../so_long.h"

void	ft_exit_control(t_win *pnc)
{
    int	i;
    int	j;

    i = -1;
    j = -1;
    while (pnc->map->mappin[++i])
    {
        while (pnc->map->mappin[i][++j])
        {
            if (pnc->map->mappin[i][j] == 'E')
            {
                pnc->map->end_cnt = pnc->map->end_cnt + 1;
            }
        }
        j = 0;//[1][0] kontrol ediliyor mu bu şekilde ??
    }
    if (pnc->map->end_cnt < 1)
    {
        ft_printf(1, "End Door Count Error", 21);
        //close_frame(pnc);
    }
}
