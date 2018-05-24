#include "apue.h"
#include <dirent.h> // directory entry header

int main(int argc , char *argv[])
{
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2) err_quit("usage: ls directory_name\n");
    if ((dp = opendir(argv[1])) == NULL) err_sys("can not open %s\n", argv[1]);

    while ((dirp = readdir(dp)) != NULL)
    {
        printf("%s\n", dirp->d_name);
    }

    closedir(dp);
    return 0;
}