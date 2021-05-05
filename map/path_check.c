#include "cub3d.h"

int	check_so_path(char *line, t_params *list)
{
	static char	**res;

	if (list->so_path != NULL)
		ft_exit("некорректная южная текстура");
	res = ft_split(line, ' ');
	free(line);
	if (res[2])
		return (0);
	if (ft_strchr(res[0], 'S') && (res[0][1] == 'O') && (res[0][2] == '\0'))
		list->so_path = res[1];
	free(res[0]);
	return (0);
}

int	check_no_path(char *line, t_params *list)
{
	static char	**res;

	if (list->no_path != NULL)
		ft_exit("некорректная северная текстура");
	res = ft_split(line, ' ');
	free(line);
	if (res[2])
		return (0);
	if (ft_strchr(res[0], 'N') && (res[0][1] == 'O') && (res[0][2] == '\0'))
		list->no_path = res[1];
	free(res[0]);
	return (0);
}

int	check_we_path(char *line, t_params *list)
{
	static char	**res;

	if (list->we_path != NULL)
		ft_exit("некорректная западная текстура");
	res = ft_split(line, ' ');
	free(line);
	if (res[2])
		return (0);
	if (ft_strchr(res[0], 'W') && (res[0][1] == 'E') && (res[0][2] == '\0'))
		list->we_path = res[1];
	free(res[0]);
	return (0);
}

int	check_ea_path(char *line, t_params *list)
{
	static char	**res;

	if (list->ea_path != NULL)
		ft_exit("некорректная восточная текстура");
	res = ft_split(line, ' ');
	free(line);
	if (res[2])
		return (0);
	if (ft_strchr(res[0], 'E') && (res[0][1] == 'A') && (res[0][2] == '\0'))
		list->ea_path = res[1];
	free(res[0]);
	return (0);
}

int	check_s_path(char *line, t_params *list)
{
	static char	**res;

	if (list->s_path != NULL)
		ft_exit("некорректная текстура спрайта");
	res = ft_split(line, ' ');
	free(line);
	if (res[2])
		return (0);
	if (ft_strchr(res[0], 'S') && (res[0][1] == '\0'))
		list->s_path = res[1];
	free(res[0]);
	return (0);
}
