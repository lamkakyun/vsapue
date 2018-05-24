#ifndef _MY_APUE
#define _MY_APUE

#include <stdlib.h>

char *path_alloc(size_t *);
void err_quit(const char *, ...) __attribute__((noreturn));
void err_ret(const char *);
void err_msg(const char *);

#endif // !_MY_APUE