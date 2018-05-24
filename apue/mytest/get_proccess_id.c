#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{

        printf("proccess id : %ld\n", (long)getpid());
        exit(0);
}
