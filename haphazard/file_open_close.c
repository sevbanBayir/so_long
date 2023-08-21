#include <stdio.h>
#include <sys/fcntl.h>
#include <unistd.h>

int ft_file_open_close() {
    int fd;
    int i;
    int fds[8]; // Initialize with -1
    char *files[] = {
            "./img/back_char.xpm",
            "./img/bg.xpm",
            "./img/block.xpm",
            "./img/coin.xpm",
            "./img/endgate.xpm",
            "./img/front_char.xpm",
            "./img/left_char.xpm",
            "./img/right_char.xpm",
            NULL
    };
    i = 0;
    while (files[i] != NULL) {
        fd = open(files[i], O_RDWR);
        fds[i] = fd;
        i++;
    }

    i = 0;
    while (i <= 7) { // Loop while the file descriptor is valid
        close(fds[i]);
        i++;
    }

    i = 0;
    while (i <= 7) { // Loop while the file descriptor is valid
        if (fds[i] <= 0)
            printf("%d Missing or wrong XPM file. Please check provided xpm directory.\n", i + 1);
        else
            printf("Success !!\n");
        i++;
    }

    return 0;
}