#include "cub3d.h"

int	check_so_path(char *line, t_params *list)
{
	static char	**res;

	if (list->so_path != NULL)
		return (0); //были введены повторяющиеся параметры
	res = ft_split(line, ' ');
	if (res[2])
		return (0);
	if (ft_strchr(res[0], 'S') && (res[0][1] == 'O') && (res[0][2] == '\0'))
		list->so_path = res[1];
	return (0);
}

int	check_no_path(char *line, t_params *list)
{
	static char	**res;

	if (list->no_path != NULL)
		return (0); //были введены повторяющиеся параметры
	res = ft_split(line, ' ');
	if (res[2])
		return (0);
	if (ft_strchr(res[0], 'N') && (res[0][1] == 'O') && (res[0][2] == '\0'))
		list->no_path = res[1];
	return (0);
}

int	check_we_path(char *line, t_params *list)
{
	static char	**res;

	if (list->we_path != NULL)
		return (0); //были введены повторяющиеся параметры
	res = ft_split(line, ' ');
	if (res[2])
		return (0);
	if (ft_strchr(res[0], 'W') && (res[0][1] == 'E') && (res[0][2] == '\0'))
		list->we_path = res[1];
	return (0);
}

int	check_ea_path(char *line, t_params *list)
{
	static char	**res;

	if (list->ea_path != NULL)
		return (0); //были введены повторяющиеся параметры
	res = ft_split(line, ' ');
	if (res[2])
		return (0);
	if (ft_strchr(res[0], 'E') && (res[0][1] == 'A') && (res[0][2] == '\0'))
		list->ea_path = res[1];
	return (0);
}

int	check_s_path(char *line, t_params *list)
{
	static char	**res;

	if (list->s_path != NULL)
		return (0); //были введены повторяющиеся параметры
	res = ft_split(line, ' ');
	if (res[2])
		return (0);
	if (ft_strchr(res[0], 'S') && (res[0][1] == '\0'))
		list->s_path = res[1];
	return (0);
}

int	check_floor_path(char *line, t_params *list)
{
	char	**res1;
	char	**res2;

	if (list->flclr != 0)
		return (0);
	res1 = ft_split(line, ' ');
	if (ft_strchr(res1[0], 'F') && (res1[0][1] == '\0'))
	{
		if (res1[2])
			return (0);
		res2 = ft_split(res1[1], ',');
		if (res2[3])
			return (0);
		list->flclr = (ft_atoi(res2[0]) << 16 | ft_atoi(res2[1]) << 8
				| ft_atoi(res2[2]));
	}
	return (0);
}

int	check_celing_path(char *line, t_params *list)
{
	char	**res1;
	char	**res2;

	if (list->clclr != 0)
		return (0);
	res1 = ft_split(line, ' ');
	if (ft_strchr(res1[0], 'C') && (res1[0][1] == '\0'))
	{
		if (res1[2])
			return (0);
		res2 = ft_split(res1[1], ',');
		if (res2[3])
			return (0);
		list->clclr = (ft_atoi(res2[0]) << 16
				| ft_atoi(res2[1]) << 8 | ft_atoi(res2[2]));
	}
	return (0);
}
