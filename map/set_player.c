#include "cub3d.h"

void	choose_dir (t_cub *cub, int i, int j)
{
	if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S')
	{
		cub->ray.dirX = 0.0;
		if (cub->map[i][j] == 'N')
			cub->ray.dirY = -1.0;
		else
			cub->ray.dirY = 1.0;
	}
	else if (cub->map[i][j] == 'W' || cub->map[i][j] == 'E')
	{
		cub->ray.dirY = 0.0;
		if (cub->map[i][j] == 'W')
			cub->ray.dirX = -1.0;
		else
			cub->ray.dirX = 1.0;
	}
}

void	set_player(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub->map[++i])
	{
		j = -1;
		while (cub->map[i][++j] != '\0')
		{
			if ((ft_strchr("NSWE", cub->map[i][j])))
			{
				choose_dir(cub, i, j);
				cub->ray.planeX = cub->ray.dirY * -0.66;
				cub->ray.planeY = cub->ray.dirX * 0.66;
				cub->list.player = 1;
				cub->ray.playerY = i + 0.5;
				cub->ray.playerX = j + 0.5;
			}
		}
	}
}
