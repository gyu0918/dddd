#include <unistd.h>
#include <stdlib.h>

char    *ft_strdup(char *str)
{
    int     i;
    char    *result;
    int     len;

    len = ft_strlen(str);
    i = -1;
    result = malloc(len + 1);
    if (!result)
        return (NULL);
    while (str[++i])
        result[i] = str[i];
    result[i] = 0;
    return (result);
}


char    *get_next_line(int fd)
{
    char    buffer;
    char    rtn[7000000];
    int     n;
    int     i;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    i = 0;
    n = read(fd, &buffer, 1);
    while (n > 0)
    {
        rtn[i++] = buffer;
        if (buffer == '\n')
            break ;
        n = read(fd, &buffer, 1);
    }
    ret[i] = 0;
    if (n <=0 && i == 0)
        return (0);
    return (ft_strdup(rtn));
}

int main()
{
    get_next_line()
}