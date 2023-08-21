#include <stdlib.h>//FOR EXİT();
#include "so_long.h"
void	ft_ber_extension_checker(char *path)
{
    int	len;

    len = ft_strlen(path);
    if (path[len - 1] != 'r' || path[len - 2] != 'e'
        || path[len - 3] != 'b' || path[len - 4] != '.')
    {
        ft_printf("Wrong file extension. Your map must be in .ber format");
        exit(1); //TODO: ARE WE ALLOWED TO USE STDLİB ?
    }
}

void	ft_filepath_checker(char *path)
{
    int	fd;

    fd = open(path, O_RDWR);
    if (fd <= 0)
    {
        ft_printf("Wrong file path. There is no .ber file in the specified path.");
        close(fd);
        exit(1);
    }
    close(fd);
}