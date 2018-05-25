#include <stdio.h>
#include <stdarg.h>


void display_int(int);
void myprintf(const char *, ...);

int main(void)
{
	myprintf("s ccc d%.\n", "hello", 'j', 'e', 't', 100);
	return 0;
}

void display_int(int num)
{
	if (num > 9) display_int(num / 10);
	putchar(num % 10 + '0');
}

void myprintf(const char *format_str, ...)
{
	va_list arg; // define variable argument
	va_start(arg, format_str); // initiate and get variable argument
	
	while (*format_str != '\0') // get a char 
	{
		int i = 0;
		if (*format_str == 's')
		{
			char *str = NULL;
			str = va_arg(arg, char*);
			while (*str != '\0')
			{
				putchar(*str);
				str++;
			}
		}
		else if (*format_str == 'c')
		{
			//putchar(va_arg(arg, char));
			putchar(va_arg(arg, int));
		}
		else if (*format_str == 'd')
		{
			int num = va_arg(arg, int);
			display_int(num);
		}
		else
		{ 
			putchar(*format_str);
		}
		format_str++;
	}
	va_end(arg); // end up from get variable argument
}