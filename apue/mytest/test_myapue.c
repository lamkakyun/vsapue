#include "myapue.h"

// you should compile myapue_err.c first

int test()
{
	int a = 1;
	switch (a)
	{
	case 1:
		err_ret("hello , this is a test2\n");
		break;
	default:
		break;
	}
	return (0);
}

int main(void)
{
	err_msg("hello , this is a test\n");
	int ret;
	if ((ret = test()) == 0)
	{
		printf("hello world\n");
	}
	else
	{
		printf("error\n");
	}

	return 0;
}