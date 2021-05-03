#include "cub3d.h"

int		ft_cnt_sprites(t_cub *cub)
{
	int i;
	int j;
	int x;

	cub->sprites = (t_sprite *)malloc(sizeof(t_sprite) * cub->sprcast.cnt);
	if (!cub->sprites)
	  return (0000000000000000);
	i = -1;
	x = 0;
	while (++i < cub->map_h)
	{
		j = -1;
		while (cub->map[i][++j])
		{
			if (cub->map[i][j] == '2')
			{
				
				cub->sprites[x].x = j + 0.5;
				cub->sprites[x].y = i + 0.5;
				x++;
			}
		}
	}
	return (0);
}

void	ft_sort_sprites(t_cub *cub)
{
	int		i;
	int		j;
	double	tmp;

	i = -1;
	while (++i < cub->sprcast.cnt)
	{
		j = -1;
		while (++j < cub->sprcast.cnt - 1)
		{
			if (cub->sprites[j].distance < cub->sprites[j + 1].distance)
			{
				tmp = cub->sprites[j].distance;
				cub->sprites[j].distance = cub->sprites[j + 1].distance;
				cub->sprites[j + 1].distance = tmp;
				tmp = cub->sprites[j].order;
				cub->sprites[j].order = cub->sprites[j + 1].order;
				cub->sprites[j + 1].order = (int)tmp;
			}
		}
	}
}

void			ft_order_sprites(t_cub *cub)
{
	int   i;
  
  i = -1;
  while (++i < cub->sprcast.cnt)
	{
		cub->sprites[i].order = i;
		cub->sprites[i].distance = pow(cub->ray.playerX - \
		cub->sprites[i].x, 2) + pow(cub->ray.playerY - cub->sprites[i].y, 2);
	}
}

void		cast_sprites(t_cub *cub)
{
	int	 i;
	ft_cnt_sprites(cub);
	ft_order_sprites(cub);
	ft_sort_sprites(cub);
	i = 0;
	while (i < cub->sprcast.cnt)
	{
	  cub->sprcast.spriteX = cub->sprites[cub->sprites[i].order].x - cub->ray.playerX;
	  cub->sprcast.spriteY = cub->sprites[cub->sprites[i].order].y - cub->ray.playerY;
	  cub->sprcast.invDet = 1.0 / (cub->ray.planeX * cub->ray.dirY - cub->ray.dirX * cub->ray.planeY); //required for correct matrix multiplication
	  cub->sprcast.transformX = cub->sprcast.invDet * (cub->ray.dirY * cub->sprcast.spriteX - cub->ray.dirX * cub->sprcast.spriteY);
	  cub->sprcast.transformY = cub->sprcast.invDet * (-cub->ray.planeY * cub->sprcast.spriteX + cub->ray.planeX * cub->sprcast.spriteY); //this is actually the depth inside the screen, that what Z is in 3D
	  cub->sprcast.spriteScreenX = (int)((cub->list.width / 2) * (1 + cub->sprcast.transformX / cub->sprcast.transformY));  //why??? 5687 ???
	  //calculate height of the sprite on screen
	  cub->sprcast.spriteHeight = abs((int)(cub->list.height / cub->sprcast.transformY)); //using 'transformY' instead of the real distance prevents fisheye
	  //calculate lowest and highest pixel to fill in current stripe

	  cub->sprcast.drawStartY = -cub->sprcast.spriteHeight / 2 + cub->list.height / 2;
	  if(cub->sprcast.drawStartY < 0)
		cub->sprcast.drawStartY = 0;
	  cub->sprcast.drawEndY = cub->sprcast.spriteHeight / 2 + cub->list.height / 2;
	  if(cub->sprcast.drawEndY >= cub->list.height)
		cub->sprcast.drawEndY = cub->list.height - 1;

	  //calculate width of the sprite
	  cub->sprcast.spriteWidth = abs((int)(cub->list.height / cub->sprcast.transformY));
	  cub->sprcast.drawStartX = -cub->sprcast.spriteWidth / 2 + cub->sprcast.spriteScreenX;
	  if(cub->sprcast.drawStartX < 0)
		cub->sprcast.drawStartX = 0;
	  cub->sprcast.drawEndX = cub->sprcast.spriteWidth / 2 + cub->sprcast.spriteScreenX;
	  if(cub->sprcast.drawEndX >= cub->list.width)
		cub->sprcast.drawEndX = cub->list.width - 1;

	  //loop through every vertical stripe of the sprite on screen
	  stripe(cub);
	i++;
	}
}