#include "cub3d.h"

void	ft_free(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free (res[i++]);
	free (res);
}

int	check_floor_path(char *line, t_params *list)
{
	char	**res1;
	char	**res2;

	if (list->flclr != 0)
		return (0);
	res1 = ft_split(line, ' ');
	free(line);
	if (ft_strchr(res1[0], 'F') && (res1[0][1] == '\0'))
	{
		if (res1[2])
			return (0);
		res2 = ft_split(res1[1], ',');
		if (res2[3])
			return (0);
		list->flclr = (ft_atoi(res2[0]) << 16 | ft_atoi(res2[1]) << 8
				| ft_atoi(res2[2]));
		ft_free(res2);
	}
	ft_free(res1);
	return (0);
}

int	check_celing_path(char *line, t_params *list)
{
	char	**res1;
	char	**res2;

	if (list->clclr != 0)
		return (0);
	res1 = ft_split(line, ' ');
	free(line);
	if (ft_strchr(res1[0], 'C') && (res1[0][1] == '\0'))
	{
		if (res1[2])
			return (0);
		res2 = ft_split(res1[1], ',');
		if (res2[3])
			return (0);
		list->clclr = (ft_atoi(res2[0]) << 16
				| ft_atoi(res2[1]) << 8 | ft_atoi(res2[2]));
		ft_free(res2);
	}
	ft_free(res1);
	return (0);
	return (0);
}
