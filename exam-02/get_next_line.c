# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

void *myfree(void *f)
{
    free(f);
    return (NULL);
}

char *get_next_line(int fd)
{
    char *ret = (char *)malloc(sizeof(char) * 9999);
    char buff = 0;
    int i = 1;
    int j = 0;
    
    while(i > 0)
    {
        i = read(fd, &buff, 1);
        if (i <= 0)
            break ;
        ret[j++] = buff;
        if(buff == '\n')
            break ;
    }
    ret[j] = 0;
    if(!*ret)
        return (myfree(ret));
    return (ret);
}

int main(void){
    int fd;
    char *line;
    fd = open("./inter.c",O_RDONLY);
    line = get_next_line(fd);
    printf("%s\n", line);
    line = get_next_line(fd);
    printf("%s\n", line);
    line = get_next_line(fd);
    printf("%s\n", line);
    line = get_next_line(fd);
    printf("%s\n", line);
}
