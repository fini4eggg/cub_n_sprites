#include "cub3d.h"

void	dda(t_cub *cub)
{
	cub->ray.hit = 0;
	while (cub->ray.hit == 0)
	{
		if (cub->ray.sideDistX < cub->ray.sideDistY)
		{
			cub->ray.sideDistX += cub->ray.deltaDistX;
			cub->ray.mapX += cub->ray.stepX;
			cub->ray.side = 0;
		}
		else
		{
			cub->ray.sideDistY += cub->ray.deltaDistY;
			cub->ray.mapY += cub->ray.stepY;
			cub->ray.side = 1;
		}
		if (cub->map[cub->ray.mapY][cub->ray.mapX] == '1')
			cub->ray.hit = 1;
	}
	if (cub->ray.side == 0)
		cub->ray.perpWallDist = (cub->ray.mapX - cub->ray.playerX
				+ (1 - cub->ray.stepX) / 2) / cub->ray.rayDirX;
	else
		cub->ray.perpWallDist = (cub->ray.mapY - cub->ray.playerY
				+ (1 - cub->ray.stepY) / 2) / cub->ray.rayDirY;
}

void	chose_txt(t_cub *cub)
{
	if (cub->ray.side == 0 && cub->ray.rayDirX > 0)
		cub->current = cub->east;
	if (cub->ray.side == 0 && cub->ray.rayDirX < 0)
		cub->current = cub->west;
	if (cub->ray.side == 1 && cub->ray.rayDirY > 0)
		cub->current = cub->south;
	if (cub->ray.side == 1 && cub->ray.rayDirY < 0)
		cub->current = cub->north;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char		*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ray_casting(t_cub *cub)
{
	int	x;

	x = 0;
	cub->img.img = mlx_new_image(cub->mlx, cub->list.width, cub->list.height);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
			&cub->img.line_length, &cub->img.endian);
	cub->sprcast.zbuffer = (double *)malloc(sizeof(double) * cub->list.width);
	if (!(cub->sprcast.zbuffer))
		return (0);
	while (x < cub->list.width)
	{
		wall_cast(cub, x);
		calc_steps(cub);
		dda(cub);
		draw_walls(cub, x);
		cub->sprcast.zbuffer[x] = cub->ray.perpWallDist;
		x++;
	}
	cast_sprites(cub);
	free(cub->sprcast.zbuffer);
	free(cub->sprites);
	if (!cub->list.save)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	else
		screenshot(cub);
	mlx_destroy_image(cub->mlx, cub->img.img);
	return (0);
}

int	draw(t_cub *cub)
{
	cub->mlx = mlx_init();
	check_max_res(cub);
	if (!cub->list.save)
		cub->win = mlx_new_window(cub->mlx, cub->list.width,
				cub->list.height, "FKNCB");
	init_txt(cub);
	ray_casting(cub);
	cast_sprites(cub);
	mlx_hook(cub->win, 2, 1L << 0, &key_press, cub);
	mlx_hook(cub->win, 3, 1L << 1, &key_release, cub);
// mlx_hook(cub->win, 17, 0L, &exit, cub);
	mlx_loop_hook(cub->mlx, &read_keys, cub);
	mlx_do_sync(cub->mlx);
	mlx_loop(cub->mlx);
	return (0);
}
