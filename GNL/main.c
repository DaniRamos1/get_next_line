#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int	main (void)
{
	char file[] = "./patata.txt";
	int a;
	char *str;
	a = open(file, O_RDONLY);

	while((str = get_next_line(a)) != NULL)
	{
		printf("%s", str);
		if (!str)
			return (0);
		free(str);
	}
	free(str);
	close(a);
	return (0);
}