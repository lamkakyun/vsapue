#ifndef _MY_APUE
#define _MY_APUE

#include <stdarg.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXLINE 4096

char *path_alloc(size_t *);
void err_quit(const char *, ...) __attribute__((noreturn));
void err_ret(const char *, ...);
void err_msg(const char *, ...);
void err_sys(const char *, ...) __attribute__((noreturn));
void err_dump(const char *, ...) __attribute__((noreturn));

#endif // !_MY_APUE