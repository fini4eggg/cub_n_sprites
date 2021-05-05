#include "cub3d.h"

int	 	check_params_fill(t_params *list)
{
	if (list->height && list->width && list->no_path
		&& list->so_path && list->we_path && list->ea_path
		&& list->flclr && list->clclr)
		list->params_fillment = 1;
	return (0);
}

char	**make_map(t_list **head, int size)
{
	char	**map;
	int		i;
	t_list	*tmp;

	map = ft_calloc(size + 1, sizeof(char *));
	if (!map)
		return (0);
	tmp = *head;
	i = -1;
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	free (tmp);
	while (map[++i])
		ft_putendl_fd(map[i], 1);
	return (map);
}

void	map_w_h(t_cub *cub, char **map)
{
	int			i;
	static int	len;
	static int	maxlen;

	i = -1;
	while (map[++i])
	{	
		len = ft_strlen(map[i]);
		if (len > maxlen)
			maxlen = len;
	}
	cub->map_w = maxlen;
	cub->map_h = i;
}

int	make_rectangle(t_cub *cub, char **map)
{
	int			i;
	int			j;
	char		*tmp;
	static int	len;

	tmp = NULL;
	map_w_h(cub, map);
	i = -1;
	while (map[++i])
	{
		len = ft_strlen(map[i]);
		if (len < cub->map_w)
		{
			tmp = ft_calloc(cub->map_w + 1, sizeof(char *));
			j = -1;
			while (map[i][++j])
				tmp[j] = map[i][j];
			while (j++ < cub->map_w)
				tmp[j] = ' ';
			map[i] = tmp;
		}
	}
	return (0);
}
