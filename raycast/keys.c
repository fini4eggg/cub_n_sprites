#include "cub3d.h"

int key_press(int key, t_cub *cub)
{
	if (key == 13)
		cub->key.up = 1;
	if (key == 1)
		cub->key.down = 1;
	if (key == 123)
		cub->key.left = 1;
	if (key == 124)
		cub->key.right = 1;
	if (key == 0)
		cub->key.stepl = 1;
	if (key == 2)
		 cub->key.stepr = 1;
	if (key == 53)
		 cub->key.exit = 1;
	read_keys(cub);
	return (0);
}

int key_release(int key, t_cub *cub)
{
	if (key == 13)
		cub->key.up = 0;
	if (key == 1)
		cub->key.down = 0;
	if (key == 123)
		cub->key.left = 0;
	if (key == 124)
		cub->key.right = 0;
	if (key == 0)	
		cub->key.stepl = 0;
	if (key == 2)
		 cub->key.stepr = 0;
	if (key == 53)
		 cub->key.exit = 0;
	read_keys(cub);
	return (0);
}