#include "cub3d.h"

void	wall_cast(t_cub *cub, int x)
{
	cub->ray.cameraX = 2 * x / (double)cub->list.width - 1;
	cub->ray.rayDirX = cub->ray.dirX + cub->ray.planeX
		* cub->ray.cameraX;
	cub->ray.rayDirY = cub->ray.dirY + cub->ray.planeY
		* cub->ray.cameraX;
	cub->ray.deltaDistX = fabs(1 / cub->ray.rayDirX);
	cub->ray.deltaDistY = fabs(1 / cub->ray.rayDirY);
	cub->ray.mapY = (int)cub->ray.playerY;
	cub->ray.mapX = (int)cub->ray.playerX;
}

void	calc_steps(t_cub *cub)
{
	if (cub->ray.rayDirX < 0)
	{
		cub->ray.stepX = -1;
		cub->ray.sideDistX = (cub->ray.playerX - cub->ray.mapX)
			* cub->ray.deltaDistX;
	}
	else
	{
		cub->ray.stepX = 1;
		cub->ray.sideDistX = (cub->ray.mapX + 1.0 - cub->ray.playerX)
			* cub->ray.deltaDistX;
	}
	if (cub->ray.rayDirY < 0)
	{
		cub->ray.stepY = -1;
		cub->ray.sideDistY = (cub->ray.playerY - cub->ray.mapY)
			* cub->ray.deltaDistY;
	}
	else
	{
		cub->ray.stepY = 1;
		cub->ray.sideDistY = (cub->ray.mapY + 1.0 - cub->ray.playerY)
			* cub->ray.deltaDistY;
	}
}
