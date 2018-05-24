#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "apue.h"

#define BUF_SZIE  4096

static void sig_int_handler(int);

        int
main(void)
{
        char        cmd       [BUF_SZIE];
        pid_t       pid;
        int     status;

        if (signal(SIGINT, sig_int_handler) == SIG_ERR) {
                err_sys("signal error");
        }
        printf("%% ");
        while (fgets(cmd, BUF_SZIE, stdin) != NULL) {
                if (cmd[strlen(cmd) - 1] == '\n') {
                        cmd[strlen(cmd) - 1] = 0;
                }
                if ((pid = fork()) < 0) {
                        err_sys("fork error");
                } else if (pid == 0) {
                        execlp(cmd, cmd, (char *)0);
                        err_ret("could not execute: %s", cmd);
                        exit(127);
                }
                if ((pid = waitpid(pid, &status, 0)) < 0) {
                        err_sys("waitpid error");
                }
                printf("%% ");

        }

        exit(0);
}

        void
sig_int_handler(int sig_no)
{
        printf("interrupt\n%%");
}
