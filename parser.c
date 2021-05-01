#include "cub3d.h"

int	 	check_params_fill(t_params *list)
{
	if (list->height && list->width && list->no_path \
	 && list->so_path && list->we_path && list->ea_path\
	 && list->flclr && list->clclr)
		list->params_fillment = 1;
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
			j = -1;
			while (map[i][++j])
			{
				tmp[j] = map[i][j];
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

void	set_player(t_cub *cub)
{
	int 	i;
	int		j;

	i = -1;
	while (cub->map[++i])
	{
		j = -1;
		while (cub->map[i][++j] != '\0')
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
		}
	}
}
