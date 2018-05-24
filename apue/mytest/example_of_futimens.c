#include "apue.h"
#include <fcntl.h>

int main(int argc, char* argv[])
{
    int i, fd;
    struct stat stat_info;
    struct timespec times[2];

    for (i = 1; i < argc; i++) {
        if (stat(argv[i], &stat_info) < 0) {
            err_ret("%s: stat error", argv[i]);
            continue;
        }
        if ((fd = open(argv[i], O_RDWR | O_TRUNC)) < 0) {
            err_ret("%s: open error", argv[i]);
            continue;
        }
        times[0] = stat_info.st_atim;
        times[1] = stat_info.st_mtim;

        if (futimens(fd, times) < 0 )
        {
            err_ret("%s: futimens error");
        }
        close(fd);
    }
    exit(0);
}
