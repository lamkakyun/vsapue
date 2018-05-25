#include "myapue.h"

static void err_doit(int, int, const char *, va_list);

void err_ret(const char *format_str, ...)
{
	va_list arg;
	va_start(arg, format_str);  // start to get variable argument
	err_doit(1, errno, format_str, arg); // errono is come from error.h
	va_end(arg);
}


void err_quit(const char *fmt_str, ...)
{
	va_list arg;
	va_start(arg, fmt_str);
	err_doit(0, 0, fmt_str, arg);
	va_end(arg);
	exit(1);
}


void err_msg(const char *fmt_str, ...)
{
	va_list arg;
	va_start(arg, fmt_str);
	err_doit(0, 0, fmt_str, arg);
	va_end(arg);
}


void err_sys(const char *fmt_str, ...)
{
	va_list arg;
	va_start(arg, fmt_str);
	err_doit(1, errno, fmt_str, arg);
	va_end(arg);
	exit(1);
}

void err_dump(const char *fmt_str, ...)
{
	va_list arg;
	va_start(arg, fmt_str);
	err_doit(1, errno, fmt_str, arg);
	va_end(arg);
	abort();/* dump core and terminate */
	exit(1);/* shouldn't get here */
}

// print msg and return to caller
static void err_doit(int errno_flag, int error_num, const char *format_str, va_list arg)
{
	char buf[MAXLINE];

	vsnprintf(buf, MAXLINE - 1, format_str, arg); // push self-define err msg to buf through [variable arguments]
	
	// if err occurred, push system err info to buf
	if (errno_flag)
	{
		snprintf(buf + strlen(buf), MAXLINE - strlen(buf) - 1, ": %s", strerror(error_num));
	}

	strcat(buf, "\n");
	fflush(stdout);
	fputs(buf, stderr);
	fflush(stdout);
}