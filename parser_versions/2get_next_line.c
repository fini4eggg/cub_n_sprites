#include "get_next_line.h"

int     ft_strlen(char *line)
{
    int     i;

    while (line[i] != '\0')
        i++;
    return (i);
}

char     ft_end(char *line, char bukva)
{
    char    *res;
    int     i;

    if (!(res = malloc(sizeof(char) * ft_strlen(line) + 2))
        return (NULL);
    i = 0;
    while ((res[i] = line[i]))
        i++;
    res[i++] = bukva;
    res[i] = '\0';
    free(line);
    return (*res);
}

int     get_next_line(char **line)
{
    char    buf[1];
    int     res;

    *line = (char *)malloc(1);
    line[0] = '\0';

}