#include "apue.h"

int main(void)
{
    struct stat file_stat;
    if (stat("foo", &file_stat) <  0) err_sys("stat error for foo");
    if (chmod("foo", (file_stat.st_mode & ~S_IXGRP) | S_ISGID)< 0 ) err_sys("chmod error for bar");
    if (chmod("bar", S_IRUSR| S_IWUSR) <0) err_sys("chmod error for bar");

    exit(0);
}

