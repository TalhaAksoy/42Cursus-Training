# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

char *get_next_line(int fd)
{
	
	int j = 0;
	char *buffer = malloc(9999);
	char *dest = malloc(9999);
	int i = read(fd , buffer, 1);

	
	while (i > 0)
	{
		dest[j++] = buffer[0];
		if (buffer[0] == '\n')
		{
			break;
		}
		i = read(fd, buffer, 1);
	}
free(buffer);
return(dest);	
}

int main()
{
	int fd = 31;
	char *line;
	fd = open("inter.c", O_RDONLY);
	line = get_next_line(fd);
	printf("%s\n", line);
}