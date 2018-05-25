#include "myapue.h"
#include <dirent.h>
#include <sys/stat.h>

typedef int Myfunc(const char *, const struct stat *, int);
static Myfunc file_type_statistics;
static int file_tarverse_walker(char *, Myfunc *);
static int _ftw(Myfunc *); // like private function for [file_tarverse_walker]

static char *fullpath;
static size_t path_len;
static long total_regular, total_dir, total_char, total_block, total_fifo, total_link, total_socket, total_in_total;

#define _IS_FILE 1
#define _IS_DIR 2
#define _IS_DIR_CANT_READ 3
#define _IS_FILE_CANT_STAT 4

int main(int argc, char *argv[])
{
	if (argc != 2) err_quit("usage: ./a.out <path_name>");

	int ret = file_tarverse_walker(argv[1], file_type_statistics);

	total_in_total = total_regular + total_dir + total_block + total_char + total_fifo + total_link + total_socket;
	if (total_in_total == 0) total_in_total = 1;

	printf("regular files = %7ld, %5.2f %%\n", total_regular, total_regular * 100.0 / total_in_total);
	printf("directories = %7ld, %5.2f %%\n", total_dir, total_dir * 100.0 / total_in_total);
	printf("block special = %7ld, %5.2f %%\n", total_block, total_block * 100.0 / total_in_total);
	printf("char special = %7ld, %5.2f %%\n", total_char, total_char * 100.0 / total_in_total);
	printf("FIFOs = %7ld, %5.2f %%\n", total_fifo, total_fifo * 100.0 / total_in_total);
	printf("symbolic links = %7ld, %5.2f %%\n", total_link, total_link * 100.0 / total_in_total);
	printf("sockets = %7ld, %5.2f %%\n", total_socket, total_socket * 100.0 / total_in_total);

	return 0;
}

static int file_tarverse_walker(char *pathname, Myfunc *statistics)
{
	fullpath = path_alloc(&path_len);

	if (path_len <= strlen(pathname))
	{
		path_len = strlen(pathname) * 2;
		if ((fullpath = realloc(fullpath, path_len)) == NULL) err_quit("realloc failed");
	}

	strcpy(fullpath, pathname);
	return _ftw(statistics);
}

static int _ftw(Myfunc *statistics)
{
	struct stat stat_info;
	struct dirent *file_info;
	DIR *d_handle;

	int ret, n;

	if (lstat(fullpath, &stat_info) < 0) return statistics(fullpath, &stat_info, _IS_FILE_CANT_STAT);
	if (S_ISDIR(stat_info.st_mode) == 0) return statistics(fullpath, &stat_info, _IS_FILE);

	// process with directory
	if ((ret = statistics(fullpath, &stat_info, _IS_DIR)) != 0) return ret;
	n = strlen(fullpath);
	if (n + NAME_MAX + 2 > path_len)
	{
		path_len *= 2;
		if ((fullpath = realloc(fullpath, path_len)) == NULL) err_sys("realloc failed");
	}
	fullpath[n] = '/';
	n++;
	fullpath[n] = 0;
	d_handle = opendir(fullpath);
	if (d_handle == NULL) return statistics(fullpath, &stat_info, _IS_DIR_CANT_READ);

	while ((file_info = readdir(d_handle)) != NULL)
	{
		if (strcmp(file_info->d_name, ".") == 0 || strcmp(file_info->d_name, "..") == 0) continue;

		strcpy(&fullpath[n], file_info->d_name);
		if ((ret = _ftw(statistics)) != 0) break;
	}

	fullpath[n - 1] = 0;// erase slash
	if (closedir(d_handle) < 0) err_ret("can not close dir %s", fullpath);

	return ret;
}


static int file_type_statistics(const char *pathname, const struct stat *stat_info, int self_define_type)
{
	switch (self_define_type)
	{
	case _IS_FILE:

		switch (stat_info->st_mode & S_IFMT) // S_IFMT means [type of file]
		{
		case S_IFREG: // regular file
			total_regular++;
			break;
		case S_IFBLK:
			total_block++;
			break;
		case S_IFCHR:
			total_char++;
			break;
		case S_IFIFO:
			total_fifo++;
			break;
		case S_IFLNK:
			total_link++;
			break;
		case S_IFSOCK:
			total_socket++;
			break;
		case S_IFDIR:
			err_dump("for S_IFDIR for %s", pathname); // dir should not be here
			break;
		default:
			break;
		}

		break;

	case _IS_DIR:
		total_dir++;
		break;
	case _IS_DIR_CANT_READ:
		err_ret("can not read directory %s", pathname);
		break;
	case _IS_FILE_CANT_STAT:
		err_ret("stat error for %s", pathname);
		break;

	default:
		err_dump("unknown type %d for pathname %s", self_define_type, pathname);
		break;
	}

	return 0;
}