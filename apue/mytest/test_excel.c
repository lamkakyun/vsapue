#include <stdio.h>

void write_excel(void);

int main(int argc, char *argv[])
{
	// write_excel();

	return 0;
}

void write_excel(void)
{
	FILE *f_handle;
	int i,t;
	char ch;
	char file_name[20] = "test.xls";

	f_handle = fopen(file_name, "w");
	for (i = 0; i < 10; i++)
	{
		printf("please input:");
		scanf("%d %c", &t, &ch);
		fprintf(f_handle, "%d\t%c\n", t, ch);
	}
	fclose(f_handle);
}