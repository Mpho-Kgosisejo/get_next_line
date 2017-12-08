#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"

#include "get_next_line.h"

int		main(void)
{
	int		fd;
	char	*line;

	if ((fd = open("file.txt", O_RDONLY)) == -1){
		printf("Error opening file!\n");
		return (0);
	}

	/*
	while (get_next_line(fd, &line) == 1){
		printf("output:- <(%s)>\n", line);
	}
	*/

	get_next_line(fd, &line);
	get_next_line(fd, &line);

	if (close(fd) == -1)
		printf("Error closing file!\n");
	return (0);
}
