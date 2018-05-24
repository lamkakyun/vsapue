#include "apue.h"

typedef int Myfunc(const char *, const struct stat *, int);
static Myfunc cal_type_count;
static int myftw(char *, Myfunc *);

int main(int argc, char* argv[])
{
    int ret;
    if (argc != 2)
        err_quit("usage: ./a.out <pathname>");


}
