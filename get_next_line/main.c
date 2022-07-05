#include "get_next_line.h"


int	main(void)
{
	char	*line;
	int		i;
	int		fd1;

	fd1 = open("test.txt", O_RDONLY);
	i = 1;
	while (i < 9)
	{
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		free(line);
		i++;
	}
	close(fd1);
	return (0);
}
