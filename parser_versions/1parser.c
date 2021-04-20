#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include "cub3d.h"
#include "get_next_line.h"

// void            make_map(t_list **head, int size)
// {
//     char **map = ft_calloc(size + 1, sizeof(char *));
//     int i = -1;
// }

void    init_struct(t_params *list)
{
    list->width = 0;
    list->height = 0;
}

int     check_resol_posit(char **res, t_params *list)
{
    int w;
    int h;

    w = ft_atoi(res[1]);
    h = ft_atoi(res[2]);
    printf("dadada");
    if (w < 0 || h < 0)
        return (0); //mistake
    list->width = w;
    list->height = h;
    printf("\n\n%d\n\n", list->width);
    printf("\n\n%d\n\n", list->height);
    return (1);
}

int     check_resol(char *line, t_params *list)
{
    char    **res;
    int     i;

    i = 0;
    //printf("%s\n", line);
    if (ft_strchr(line, 'R'))
    {
        res = ft_split(line, ' ');
        if (res[3])
            return (0); // вывести ошибку о невалидности файла
        if (ft_strchr(res[0], 'R') && (res[0][1] == '\0'))
        {
            while (res[1][i])
            {
                if (ft_isdigit(res[1][i]) == 0)
                    return (0); // вывести ошибку о невалидности файла
                i++;
                //printf("%s\n", res[1]);
            }
            i = 0;
            while (res[2][i])
            {
                if (ft_isdigit(res[2][i]) == 0)
                    return (0); // вывести ошибку о невалидности файла
                i++;
                //printf("%s\n", res[2]);
            }
        }
        printf("HHHHH");
        check_resol_posit(res, list);
        return (1);
    }
    return (0); // succes!
}

int             main(int argc, char **argv)
{
    int     fd = open("map.cub", O_RDONLY);
    char    *line = NULL; /// посмотреть норму
    int     i;
    t_params list;

    if (argc == 0 || argc > 2)
        return (0); // проверка на количество аргументов
    if (!argv)
        return (0); // HUY
    i = 0;
    printf("MRAZZZZZZ");
    init_struct(&list);
    printf("MRAZZZZZZ");
    while (get_next_line(fd, &line))
    {
        //printf("%s", line[i]);
        // printf("%d", check_resol(line[i]));
        if (check_resol(line, &list))
            printf("\n\nSHISHA\n\n");
    }
    printf("%s", "\n");
    return (0);
}