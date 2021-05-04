#include "cub3d.h"

void	forw_back(t_cub *cub, int angle)
{
	if (cub->key.down == 1)
		angle *= -1;
	if (cub->map[(int)(cub->ray.playerY + cub->ray.dirY * g_mspeed * angle)]
			[(int)(cub->ray.playerX)] != '1')
		cub->ray.playerY += cub->ray.dirY * g_mspeed * angle;
	if (cub->map[(int)(cub->ray.playerY)][(int)(cub->ray.playerX
			+ cub->ray.dirX * g_mspeed * angle)] != '1')
		cub->ray.playerX += cub->ray.dirX * g_mspeed * angle;
}

void	rot(t_cub *cub, int angle)
{
	double	oldDirX;
	double	oldPlaneX;

	if (cub->key.left)
		angle *= -1;
	oldDirX = cub->ray.dirX;
	cub->ray.dirX = cub->ray.dirX * cos(g_rspeed * angle)
		- cub->ray.dirY * sin(g_rspeed * angle);
	cub->ray.dirY = oldDirX * sin(g_rspeed * angle)
		+ cub->ray.dirY * cos(g_rspeed * angle);
	oldPlaneX = cub->ray.planeX;
	cub->ray.planeX = cub->ray.planeX * cos(g_rspeed * angle)
		- cub->ray.planeY * sin(g_rspeed * angle);
	cub->ray.planeY = oldPlaneX * sin(g_rspeed * angle)
		+ cub->ray.planeY * cos(g_rspeed * angle);
}

void	step(t_cub *cub, int angle)
{
	if (cub->key.stepl)
		angle *= -1;
	if (cub->map[(int)(cub->ray.playerY + cub->ray.planeY
			* g_mspeed * angle)][(int)(cub->ray.playerX)] != '1')
		cub->ray.playerY += cub->ray.planeY * g_mspeed * angle;
	if (cub->map[(int)(cub->ray.playerY)][(int)(cub->ray.playerX
			+ cub->ray.planeX * g_mspeed * angle)] != '1')
		cub->ray.playerX += cub->ray.planeX * g_mspeed * angle;
}

int	read_keys(t_cub *cub)
{	
	int	angle;

	angle = 1;
	if (cub->key.up || cub->key.down)
		forw_back(cub, angle);
	if (cub->key.right || cub->key.left)
		rot(cub, angle);
	if (cub->key.stepr || cub->key.stepl)
		step(cub, angle);
	if (cub->key.exit /*|| или кнопка крестик */)
	{
		exit (0);
		// очистка памяти и всех маллоков с массивами
	}
	ray_casting(cub);
	return (0);
}
