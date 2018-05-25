#include "myapue.h"
#include <sys/stat.h>
#include <assert.h>
#include <dirent.h>

#define MY_PATH_MAX 4096

int is_dir(const char *);
void file_walker(const char *);

int file_total = 0;

int main(int argc, char *argv[])
{
	if (argc != 2) err_quit("usage: ./a.out <path>");

	char dirpath[MY_PATH_MAX];
	strcpy(dirpath, argv[1]);

	file_walker(dirpath);
	printf("total files: %d\n", file_total);
	return 0;
}

int is_dir(const char *path)
{
	struct stat buf;
	stat(path, &buf);
	return 0 != S_ISDIR(buf.st_mode);
}


void file_walker(const char *path)
{
	assert(path != NULL);

    char current_path[MY_PATH_MAX];
	DIR *d_handle;
	struct dirent *file_info;

	d_handle = opendir(path);
	if (d_handle == NULL) err_quit("open dir %s error!", path);

	while ((file_info = readdir(d_handle)) != NULL)
	{
        if (!strcmp(file_info->d_name, ".") || !strcmp(file_info->d_name, "..")) continue;

        sprintf(current_path, "%s/%s", path, file_info->d_name);

		if (is_dir(current_path))
		{
			printf("dir: %s\n", current_path);
			file_walker(current_path);
		}
        else printf("%d, %s\n", ++file_total  , file_info->d_name  );

	}
	
    closedir(d_handle);
}
