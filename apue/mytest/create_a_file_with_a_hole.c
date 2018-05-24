#include <fcntl.h>
#include "apue.h"

char buf1[] = "abcdefghij";
char buf2[] = "ABCDEFGHIJ";

int main(void)
{
        int fd;
        if ((fd = creat("/home/jet/file.hole", FILE_MODE)) < 0) {
                err_msg("creat error");
        }
        if (write(fd, buf1, 10) != 10) {
                err_msg("buf1 write fail");
        }
        if (lseek(fd, 102400000, SEEK_SET) == 1) {
                err_msg("lseek error");
        }
        if (write(fd, buf2, 10) != 10) {
                err_msg("buf2 write fail");
        }
        exit(0);
}
