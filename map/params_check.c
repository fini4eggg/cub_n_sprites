#include "cub3d.h"

int	check_resol_posit(char **res, t_params *list)
{
	int	w;
	int	h;

	w = ft_atoi(res[1]);
	h = ft_atoi(res[2]);
	if (w < 0 || h < 0)
		return (0); //mistake
	list->width = w;
	list->height = h;
	return (1);
}

int	check_resol(char *line, t_params *list)
{
	static char	**res;
	int			i;

	i = 0;
	if (ft_strchr(line, 'R'))
	{
		res = ft_split(line, ' ');
		free(line);
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
		ft_free(res);
		return (1);
	}
	return (0); // succes!
}

void	check_max_res(t_cub *cub)	/// проверка на максимальный размер открываемого окна
{
	int	max_height;
	int	max_width;

	max_height = 0;
	max_width = 0;
	mlx_get_screen_size(cub->mlx, &max_width, &max_height);
	if (cub->list.width > max_width)
		cub->list.width = max_width;
	if (cub->list.height > max_height)
		cub->list.height = max_height;
}

int	check_params(char *line, t_params *list)
{
	// while (1);
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
