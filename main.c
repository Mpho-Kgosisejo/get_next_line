#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"

#include "get_next_line.h"

int		main(void)
{
	int		fd;
	int		line_count = 0;
	char	*line;

	//return (0);
	if ((fd = open("./file0.txt", O_RDONLY)) == -1){
		printf("Error opening file!\n");
		return (0);
	}

	while (get_next_line(fd, &line) == 1){
		printf("output (%i):- <(%s)>\n", line_count, line);
		ft_strdel(&line);
		/*free(line);
		line = NULL;*/
		line_count++;
	}
	printf("output! (%i):- <(%s)>\n", line_count, line);
	ft_strdel(&line);

	//get_next_line(fd, &line);
	//get_next_line(fd, &line);
	//printf(">> %s\n", line);

	if (close(fd) == -1)
		printf("Error closing file!\n");
	return (0);
}
