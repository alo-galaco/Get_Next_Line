#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int		fd;
	int		i;
	char	*str;

	fd = open("teste", O_RDONLY);
	if (fd == -1)
	{
		printf("Failed\n");
		return (1);
	}
	i = 0;
	while (i < 3)
	{
		str = get_next_line (fd);
		printf("#%s", str);
		free (str);
		i++;
	}
	close(fd);
	return (0);
}