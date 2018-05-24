#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
        fprintf(stderr, "ERROR ACCESS:%s\n", strerror(EACCES));
        errno = ENOENT;
        perror(argv[0]);

        exit(0);
}
