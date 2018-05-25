#include "myapue.h"

#ifdef PATH_MAX
static long pathmax = PATH_MAX;
#else
static long pathmax = 0;
#endif // PATH_MAX

static long posix_version = 0;
static long xsi_version = 0;

#define PATH_MAX_GUESS 1024 // en..., just a guess, no guarantee is adequate

// allocate a path name
char *path_alloc(size_t *size_allocated) // yes, return size of allocated
{
	char *return_path; // just an address of start
	size_t size_of_path_name;

	if (posix_version == 0) posix_version = sysconf(_SC_VERSION);
	if (xsi_version) xsi_version = sysconf(_SC_XOPEN_VERSION);

	if (pathmax == 0)
	{
		errno = 0;
		if ((pathmax = pathconf("/", _PC_PATH_MAX)) < 0)
		{
			if (errno == 0) pathmax = PATH_MAX_GUESS;
			else err_sys("pathconf error for _PC_PATH_MAX");
		}
		else
		{
			pathmax++; // add one since it's relative to root
		}
	}
	
	//  Before POSIX.1-2001, we aren't guaranteed that PATH_MAX includes the terminating null byte.Same goes for XPG3.
	if ((posix_version < 200112L) && (xsi_version < 4)) size_of_path_name = pathmax + 1;
	else size_of_path_name = pathmax;

	if ((return_path = malloc(size_of_path_name)) == NULL) err_sys("malloc error for pathname");

	if (size_allocated != NULL) *size_allocated = size_of_path_name;

	return return_path;
}