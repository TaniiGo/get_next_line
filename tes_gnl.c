#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main(int ac, char **av)
{
	int fd;
	int i = 0;
	char *line = NULL;

	// if (ac != 2)
	// 	return (1);
	fd = open(av[1], O_RDONLY);
	// fd = 0;
	do
	{
		line = get_next_line(fd);
		printf("%d:%s", i, line);
		free(line);
		i++;
	} while (line != NULL);
	// system("leaks a.out");
	return (0);
}