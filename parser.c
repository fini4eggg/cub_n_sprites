/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   parser.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: bryella <bryella@student.42lyon.fr>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/03/21 02:19:18 by bryella		   #+#	#+#			 */
/*   Updated: 2021/03/24 21:28:05 by bryella		  ###   ########lyon.fr   */
/*																			*/
/* ************************************************************************** */

#include "libft/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include "cub3d.h"
#include "get_next_line.h"

int	 	check_resol_posit(char **res, t_params *list)
{
	int w;
	int h;

	w = ft_atoi(res[1]);
	h = ft_atoi(res[2]);
	if (w < 0 || h < 0)
		return (0); //mistake
	list->width = w;
	list->height = h;
	return (1);
}

int	 	check_resol(char *line, t_params *list)
{
	static char	**res;
	int	 i;

	i = 0;
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
			}
			i = 0;
			while (res[2][i])
			{
				if (ft_isdigit(res[2][i]) == 0)
					return (0); // вывести ошибку о невалидности файла
				i++;
			}
		}
		check_resol_posit(res, list);
		return (1);
	}
	return (0); // succes!
}

int	 	check_so_path(char *line, t_params *list)
{
	static char **res;

	if(list->so_path != NULL)
		return (0); //были введены повторяющиеся параметры
	res = ft_split(line, ' ');
	if (res[2])
		return (0);
	if (ft_strchr(res[0], 'S') && (res[0][1] == 'O') && (res[0][2] == '\0'))
		list->so_path = res[1];
		// printf("\n%s\n", list->so_path); // удалить
	return (0);
}

int	 	check_no_path(char *line, t_params *list)
{
	static char **res;

	if(list->no_path != NULL)
		return (0); //были введены повторяющиеся параметры
	res = ft_split(line, ' ');
	if (res[2])
		return (0);
	if (ft_strchr(res[0], 'N') && (res[0][1] == 'O') && (res[0][2] == '\0'))
		list->no_path = res[1];
		// printf("\n%s\n", list->no_path); // удалить
	return (0);
}

int	 	check_we_path(char *line, t_params *list)
{
	static char **res;

	if(list->we_path != NULL)
		return (0); //были введены повторяющиеся параметры
	res = ft_split(line, ' ');
	if (res[2])
		return (0);
	if (ft_strchr(res[0], 'W') && (res[0][1] == 'E') && (res[0][2] == '\0'))
		list->we_path = res[1];
		// printf("\n%s\n", list->we_path); // удалить
	return (0);
}

int	 	check_ea_path(char *line, t_params *list)
{
	static char **res;

	if(list->ea_path != NULL)
		return (0); //были введены повторяющиеся параметры
	res = ft_split(line, ' ');
	if (res[2])
		return (0);
	if (ft_strchr(res[0], 'E') && (res[0][1] == 'A') && (res[0][2] == '\0'))
		list->ea_path = res[1];
		// printf("\n%s\n", list->ea_path); // удалить
	return (0);
}

int	 	check_s_path(char *line, t_params *list)
{
	static char **res;

	if(list->s_path != NULL)
		return (0); //были введены повторяющиеся параметры
	res = ft_split(line, ' ');
	if (res[2])
		return (0);
	if (ft_strchr(res[0], 'S') && (res[0][1] == '\0'))
		list->s_path = res[1];
		// printf("\n%s\n", list->s_path); // удалить
	return (0);
}

int	 	check_floor_path(char *line, t_params *list)
{
	char **res1;
	char **res2;

	if(list->flclr != 0)
		return (0);
	res1 = ft_split(line, ' ');
	if (ft_strchr(res1[0], 'F') && (res1[0][1] == '\0'))
	{
		if (res1[2])
			return (0);	
		res2 = ft_split(res1[1], ',');
		if (res2[3])
			return (0);
		list->flclr = (ft_atoi(res2[0]) << 16 | ft_atoi(res2[1]) << 8 | ft_atoi(res2[2]));
	}
	return (0);
}

int	 	check_celing_path(char *line, t_params *list)
{
	char **res1;
	char **res2;

	if(list->clclr != 0)
		return (0);
	res1 = ft_split(line, ' ');
	if (ft_strchr(res1[0], 'C') && (res1[0][1] == '\0'))
	{
		if (res1[2])
			return (0);	
		res2 = ft_split(res1[1], ',');
		if (res2[3])
			return (0);
		list->clclr = (ft_atoi(res2[0]) << 16 | ft_atoi(res2[1]) << 8 | ft_atoi(res2[2]));
	}
	return (0);
}

int	 	check_params_fill(t_params *list)
{
	if (list->height && list->width && list->no_path \
	 && list->so_path && list->we_path && list->ea_path\
	 && list->flclr && list->clclr)
		list->params_fillment = 1;
	return (0);
}

int	 	check_params(char *line, t_params *list)
{
	if (ft_strnstr(line, "R", 1) != NULL)
		check_resol(line, list);
	else if (ft_strnstr(line, "SO", 2) != NULL) // разобраться с проверкой пути к текстурам в mlx
		check_so_path(line, list);
	else if (ft_strnstr(line, "NO", 2) != NULL)
		check_no_path(line, list);
	else if (ft_strnstr(line, "EA", 2) != NULL)
		check_ea_path(line, list);
	else if (ft_strnstr(line, "WE", 2) != NULL)
		check_we_path(line, list);
	else if (ft_strnstr(line, "S", 1) != NULL)
		check_s_path(line, list);
	else if (ft_strnstr(line, "F", 1) != NULL)
		check_floor_path(line, list);
	else if (ft_strnstr(line, "C", 1) != NULL)
		check_celing_path(line, list);
	// // else if (list->params_fillment)
	// //	 fill_map(line, list);
	return (0);
}

char	**make_map(t_list **head, int size)
{
	char	  **map = ft_calloc(size + 1, sizeof(char *));
	int		  i;
	t_list	  *tmp;

	tmp = *head;
	i = -1;
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp= tmp->next;

	}
	while (map[++i])
		ft_putendl_fd(map[i], 1);
	return (map);
}

int		make_rectangle(t_cub *cub, char **map)
{
	int		i;
	int		j;
	int		len;
	int		maxlen;
	char	*tmp;

	// cub->map_w = 0;
	maxlen = 0;
	len = 0;
	tmp = NULL;
	i = -1;
	while (map[++i])
	{	
		len = ft_strlen(map[i]);
		if (len > maxlen)					///				проверить когда будут пустые строки
			maxlen = len;							///				проверить --//--
	}
	cub->map_w = maxlen;
	cub->map_h = i;
	i = -1;
	while (map[++i])
	{
		len = ft_strlen(map[i]);
		if (len < maxlen)
		{
			tmp = ft_calloc(maxlen + 1, sizeof(char *));
			j = 0;
			while (map[i][j])
			{
				tmp[j] = map[i][j];
				j++;
			}
			while (j < maxlen)
			{
				tmp[j] = ' ';
				j++;
			}
			map[i] = tmp;
		}
	}
	return (0);
}

int 	check_char(int c, char *compare)
{
	int		i;

	i = -1;
	if (!compare)
		return (0);
	while (compare[++i])
		if (compare[i] == c)
			return (1);
	return (0);
}

int		check_around(char **map, int i, int j, char *compare)
{
	if (check_char(map[i][j - 1], compare)\
		 || check_char(map[i][j + 1], compare) || check_char(map[i + 1][j], compare)\
		 || check_char(map[i - 1][j], compare) || check_char(map[i + 1][j + 1], compare)\
		 || check_char(map[i - 1][j - 1], compare) || check_char(map[i - 1][j + 1], compare)\
		 || check_char(map[i + 1][j - 1], compare))
		return (666);
	return (0);
}

void	set_player(t_cub *cub)
{
	int 	i;
	int		j;

	i = 0;
	while (cub->map[i])
	{
		j = 0;
		while (cub->map[i][j] != '\0')
		{
			if ((ft_strchr("NSWE", cub->map[i][j])))
			{
				if (cub->map[i][j] == 'N')
				{
					cub->ray.dirX = 0.0;
					cub->ray.dirY = -1.0;
				}
				else if (cub->map[i][j] == 'S')
				{
					cub->ray.dirX = 0.0;
					cub->ray.dirY = 1.0;
				}
				else if (cub->map[i][j] == 'W')
				{
					cub->ray.dirX = -1.0;
					cub->ray.dirY = 0.0;
				}
				else
				{
					cub->ray.dirX = 1.0;
					cub->ray.dirY = 0.0;
				}
				cub->ray.planeX = cub->ray.dirY * -0.66;
				cub->ray.planeY = cub->ray.dirX * 0.66;
				cub->list.player = 1;
				cub->ray.playerY = i + 0.5; // записываем позицию игрока
				cub->ray.playerX = j + 0.5;
			}
			j++;
		}
		i++;
	}
}

int		check_validity(char **map, t_cub *cub)
{
	int i;
	int j;

	i = -1;
	while (map[++i])
	{	
		j = -1;
		while (map[i][++j])
		{
		if (cub->list.player > 1)
			return(0) ; // игрок уже есть на поле
		if ((map[i][j] == '0') && check_around(map, i, j, " "))
			return (888);
		if ((map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E'\
		|| map[i][j] == 'N') && !(check_around(map, i, j, "012")))
			cub->list.player++;
		if (map[i][j] == '2')
			cub->sprcast.cnt++;
		}
	}
	return (777);
}

static void	ft_init(t_cub *cub)
{
	cub->list.clclr = 0;
	cub->list.flclr = 0;
	cub->list.no_path = NULL;
	cub->list.so_path = NULL;
	cub->list.ea_path = NULL;
	cub->list.we_path = NULL;
	cub->list.s_path = NULL;
}

int	 	main(int argc, char **argv)
{
	int	 		fd;			//
	char		*line = NULL; 							/// посмотреть норму
	// t_params 	list;
	t_cub		*cub;
	t_list   	*head = NULL;

	cub = (t_cub *)malloc(sizeof(t_cub));
	if (cub == NULL)
	{
		printf("%s\n", strerror(errno));
		exit (1);
	}
	ft_init(cub);
	if (argc == 3)	
	{
		if (!(ft_strncmp("--save", argv[1], ft_strlen(argv[1]))))
			cub->list.save = 1;
		fd = open(argv[2], O_RDONLY);
	}
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		cub->list.save = 0;
	}
	if (argc == 0 || argc > 3)
		return (0); // проверка на количество аргументов
	if (!argv)
		return (0); // HUY
	cub->sprcast.cnt = 0;
	while (get_next_line(fd, &line))
	{
		check_params_fill(&cub->list);
		cub->sprcast.cnt = 0;
		if (check_params(line, &cub->list))
			printf("Nothing\n");
			// printf("\n\nSHISHA\n\n");  // удалить
		else if ((cub->list.params_fillment))
			ft_lstadd_back(&head, ft_lstnew(line));
	}
	ft_lstadd_back(&head, ft_lstnew(line));
	cub->map = make_map(&head, ft_lstsize(head));
	make_rectangle(cub, cub->map);
	set_player(cub);
	check_validity(cub->map, cub);
	// cast_sprites(cub);
	draw(cub);
	return (0);
}
