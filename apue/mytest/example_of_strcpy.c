#include <string.h>
#include <stdio.h>

int main(void)
{
    char buffer[10];
    char *name = buffer;

    name = stpcpy (stpcpy (stpcpy (name, "ice"),"-"), "cream");
    puts(buffer);

    return 0;
}
