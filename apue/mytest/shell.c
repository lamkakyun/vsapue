#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "apue.h"

#define MAXLINE 4096 

int main(void)
{
    char input_cmd[MAXLINE];
    pid_t pid;
    int status;

    printf("%% ");
    while (fgets(input_cmd, MAXLINE, stdin) != NULL)
    {
        if (input_cmd[strlen(input_cmd) - 1] == '\n')
        {
                input_cmd[strlen(input_cmd) - 1] = 0;
        }
        if ((pid = fork()) < 0)
        {
            err_sys("fork error");
        }
        else if (pid == 0)
        {
                execlp(input_cmd, input_cmd, (char *)0);
                err_ret("cound not execute: %s", input_cmd);
                exit(127);
        }

        if ((pid = waitpid(pid, &status, 0)) < 0)
        {
                err_sys("waitpid error");
        }
        printf("%% ");
    }

    exit(0);
}
