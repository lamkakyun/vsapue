#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    printf("posix version: %ld\n", sysconf(_SC_VERSION));
    printf("xsi version: %ld\n", sysconf(_SC_XOPEN_VERSION));

#ifdef PATH_MAX
    int pathmax = PATH_MAX;
#else
    int pathmax = 0;
#endif
    printf("path max: %d\n", pathmax);
    printf("path max(2): %ld\n", pathconf("/", _PC_PATH_MAX));

    exit(0);
}
