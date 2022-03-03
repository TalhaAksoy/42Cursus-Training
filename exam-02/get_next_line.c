#include "get_next_line.h"

void *myfree(void *f)
{
	free(f);
	return(NULL);
}

char *get_next_line(int fd)
{
	char *ret = malloc(sizeof(char) * 9999);
	char buffer = 0;
	int i = 1;
	int j = 0;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (0);

	while (i > 0)
	{
		i = read(fd, &buffer, 1);
		if (i <= 0)
			break ;
		ret[j++] = buffer;
		if (buffer == '\n')
			break ;
	}
	ret[j] = 0;
	if(!*ret)
		myfree(ret);
	return (ret);
	
}


int main(void){
    int fd;
    char *line;
    fd = open("./union.c",O_RDONLY);
    line = get_next_line(fd);
    printf("%s\n", line);
    line = get_next_line(fd);
    printf("%s\n", line);
    line = get_next_line(fd);
    printf("%s\n", line);
    line = get_next_line(fd);
    printf("%s\n", line);
}