#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int ac, char **av)
{
	FILE *fp;

	fp = fopen(av[1], "r");
	char buf[50];
	char *p;
	int i = 0;
	do
	{
		p = fgets(buf, 10, fp);
		printf("%d:%s", i, p);
		i++;
	} while (p != NULL);

	fclose(fp);
	return (0);
}