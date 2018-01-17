#include "stdio.h"
#include "fcntl.h"
#include "unistd.h"

#include "get_next_line.h"

int		main(void)
{
	int		fd;
	int		pfd[2];
	int		line_count = 0;
	char	*line;

	if ((fd = open("./file0.txt", O_RDONLY)) == -1)
	{
		printf("Error opening file!\n");
		return (0);
	}


	while (get_next_line(fd, &line) == 1){
		printf("output (%i):- <(%s)>\n", line_count, line);
		ft_strdel(&line);
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

/*int 	main(void)
{
		char 	*line;
		int		out;
		int		p[2];
		int		fd;

		out = dup(1);
		pipe(p);

		fd = 1;
		dup2(p[1], fd);
		write(fd, "abcd1234", 8);
		close(p[1]);
		dup2(out, fd);
		get_next_line(p[0], &line);
		printf(">> %s", line);
}*/
