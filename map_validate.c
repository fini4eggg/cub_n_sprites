#include "cub3d.h"

int	check_char(int c, char *compare)
{
	int	i;

	i = -1;
	if (!compare)
		return (0);
	while (compare[++i])
		if (compare[i] == c)
			return (1);
	return (0);
}

int	check_around(char **map, int i, int j, char *compare)
{
	if (check_char(map[i][j - 1], compare)\
		 || check_char(map[i][j + 1], compare) || check_char(map[i + 1][j], compare)\
		 || check_char(map[i - 1][j], compare) || check_char(map[i + 1][j + 1], compare)\
		 || check_char(map[i - 1][j - 1], compare) || check_char(map[i - 1][j + 1], compare)\
		 || check_char(map[i + 1][j - 1], compare))
		return (666);
	return (0);
}

int	check_validity(char **map, t_cub *cub)
{
	int	i;
	int	j;

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