#include <stdio.h>

void count()
{
	static int i = 0;

	printf("%d\n", ++i);
}

int main()
{
	int i = 0;

	while (i < 5)
	{
		count();
		i++;
	}

	return (0);
}