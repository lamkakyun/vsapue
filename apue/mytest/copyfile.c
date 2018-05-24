#include "apue.h"

#define BUF_SIZE 4069

// usage: a.out > tmp
int main(void)
{
    int n;
    char buf[BUF_SIZE];
    while ((n=read(STDIN_FILENO, buf, BUF_SIZE)) > 0)
    {
            if (write(STDOUT_FILENO, buf, n) != n)
            {
                    err_sys("write err");
            }
    }

    if (n < 0)
    {
            err_sys("read err");
    }

    // program does not close the input file and outout file.Instead, the program
    // uses the feature of the UNIX kernel that closes all open file descriptors in a
    // process when that process terminates.
    exit(0);
}

