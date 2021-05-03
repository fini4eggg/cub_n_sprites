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

void	draw_walls(t_cub *cub, int x)

{
	int	lineHeight;
	int	drawStart;
	int	drawEnd;
	int	y;

	lineHeight = (int)(cub->list.height / cub->ray.perpWallDist);
	drawStart = -lineHeight / 2 + cub->list.height / 2;
	drawEnd = lineHeight / 2 + cub->list.height / 2;
	if (drawStart < 0)
		drawStart = 0;
	if (drawEnd >= cub->list.height) 
		drawEnd = cub->list.height - 1;
	chose_txt(cub);
	y = drawStart;
	if (cub->ray.side == 0)
		cub->ray.wallx = cub->ray.playerY + \
		cub->ray.perpWallDist * cub->ray.rayDirY;
	else
		cub->ray.wallx = cub->ray.playerX + \
		cub->ray.perpWallDist * cub->ray.rayDirX;
	cub->ray.wallx -= floor(cub->ray.wallx);
	cub->ray.texx = (int)(cub->ray.wallx * (double)(cub->current.width));
	if (cub->ray.side == 0 && cub->ray.rayDirX > 0)
		cub->ray.texx = cub->current.width - cub->ray.texx - 1;
	if (cub->ray.side == 1 && cub->ray.rayDirY < 0)
		cub->ray.texx = cub->current.width - cub->ray.texx - 1;
	cub->ray.step = (double)cub->current.height / lineHeight;
	cub->ray.texpos = (drawStart - cub->list.height / 2 + \
	lineHeight / 2) * cub->ray.step;
	int ceiling = 0;
	while (ceiling < drawStart)
	{
		my_mlx_pixel_put(&cub->img, x, ceiling, cub->list.clclr);
		ceiling++;
	}
	while (y < drawEnd)
	{
		cub->ray.texy = (int)cub->ray.texpos & (cub->current.height - 1);
		cub->ray.texpos += cub->ray.step;
		cub->ray.color = *(unsigned int*)(cub->current.addr + (cub->ray.texy * \
		cub->current.line_length + cub->ray.texx * \
		(cub->current.bits_per_pixel / 8)));
		my_mlx_pixel_put(&cub->img, x, y, cub->ray.color);
		y++;
	}
	int floor = drawEnd + 1;
	while (floor < cub->list.height)
	{
		my_mlx_pixel_put(&cub->img, x, floor, cub->list.flclr);
		floor++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char		*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ray_casting(t_cub *cub)
{
	int x;
	x = 0;

	cub->img.img = mlx_new_image(cub->mlx, cub->list.width, cub->list.height);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel, &cub->img.line_length, &cub->img.endian);
	cub->sprcast.zbuffer = (double *)malloc(sizeof(double) * cub->list.width);
	if (!(cub->sprcast.zbuffer))																	/// ошибка
		return (519539);
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
	if (!cub->list.save)
		mlx_put_image_to_window(cub->mlx, cub->win, cub->img.img, 0, 0);
	else
		screenshot(cub);
	mlx_destroy_image(cub->mlx, cub->img.img);
	return (0);
}

int	read_keys(t_cub *cub)
{	int angle;

	angle = 1;
	if (cub->key.up || cub->key.down)
	{
		if (cub->key.down == 1)
			angle *= -1;
		if(cub->map[(int)(cub->ray.playerY + cub->ray.dirY * g_mspeed * angle)][(int)(cub->ray.playerX)] != '1')
			cub->ray.playerY += cub->ray.dirY * g_mspeed * angle;
		if(cub->map[(int)(cub->ray.playerY)][(int)(cub->ray.playerX + cub->ray.dirX * g_mspeed * angle)] != '1')
			cub->ray.playerX += cub->ray.dirX * g_mspeed * angle;
	}
	if (cub->key.right || cub->key.left)
	{
		if (cub->key.left)
			angle *= -1;
		double oldDirX = cub->ray.dirX;
		cub->ray.dirX = cub->ray.dirX * cos(g_rspeed * angle) - cub->ray.dirY * sin(g_rspeed * angle);
		cub->ray.dirY = oldDirX * sin(g_rspeed * angle) + cub->ray.dirY * cos(g_rspeed * angle);
		double oldPlaneX = cub->ray.planeX;
		cub->ray.planeX = cub->ray.planeX * cos(g_rspeed * angle) - cub->ray.planeY * sin(g_rspeed * angle);
		cub->ray.planeY = oldPlaneX * sin(g_rspeed * angle) + cub->ray.planeY * cos(g_rspeed * angle);
	}
	if (cub->key.stepr || cub->key.stepl)
	{
		if (cub->key.stepl)
			angle *= -1;
		if(cub->map[(int)(cub->ray.playerY + cub->ray.planeY * g_mspeed * angle)][(int)(cub->ray.playerX)] != '1')
			cub->ray.playerY += cub->ray.planeY * g_mspeed * angle;
		if(cub->map[(int)(cub->ray.playerY)][(int)(cub->ray.playerX + cub->ray.planeX * g_mspeed * angle)] != '1')
			cub->ray.playerX += cub->ray.planeX * g_mspeed * angle;
	}
	if (cub->key.exit /*|| или кнопка крестик */)
	{
		exit (0);
		// очистка памяти и всех маллоков с массивами
	}
	ray_casting(cub);
	return (0);
}

void init_txt(t_cub *cub)
{
	cub->north.img = mlx_xpm_file_to_image(cub->mlx, cub->list.no_path,
	&cub->north.width, &cub->north.height);
	cub->south.img = mlx_xpm_file_to_image(cub->mlx, cub->list.so_path,
	&cub->south.width, &cub->south.height);
	cub->east.img = mlx_xpm_file_to_image(cub->mlx, cub->list.ea_path,
	&cub->east.width, &cub->east.height);
	cub->west.img = mlx_xpm_file_to_image(cub->mlx, cub->list.we_path,
	&cub->west.width, &cub->west.height);
	cub->sprite.img = mlx_xpm_file_to_image(cub->mlx, cub->list.s_path,
	&cub->sprite.width, &cub->sprite.height);
	if (cub->north.img == NULL || cub->south.img == NULL
		|| cub->west.img == NULL || cub->east.img == NULL || cub->sprite.img == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	cub->north.addr = mlx_get_data_addr(cub->north.img,
	&cub->north.bits_per_pixel, &cub->north.line_length, &cub->north.endian);
	cub->south.addr = mlx_get_data_addr(cub->south.img,
	&cub->south.bits_per_pixel, &cub->south.line_length, &cub->south.endian);
	cub->east.addr = mlx_get_data_addr(cub->east.img,
	&cub->east.bits_per_pixel, &cub->east.line_length, &cub->east.endian);
	cub->west.addr = mlx_get_data_addr(cub->west.img,
	&cub->west.bits_per_pixel, &cub->west.line_length, &cub->west.endian);
	cub->sprite.addr = mlx_get_data_addr(cub->sprite.img,
	&cub->sprite.bits_per_pixel, &cub->sprite.line_length, &cub->sprite.endian);	
}

void	check_max_res(t_cub *cub)  /// проверка на максимальный размер открываемого окна
{
	int max_height;
	int max_width;

	max_height = 0;
	max_width = 0;
	mlx_get_screen_size(cub->mlx, &max_width, &max_height);
	if (cub->list.width > max_width)
		cub->list.width = max_width;
	if (cub->list.height > max_height)
		cub->list.height = max_height;
}

int	draw(t_cub *cub)
{
	cub->mlx = mlx_init();
	check_max_res(cub);
	if (!cub->list.save)
		cub->win = mlx_new_window(cub->mlx, cub->list.width, cub->list.height, "FKNCB");
	init_txt(cub);
	ray_casting(cub);
	cast_sprites(cub);
	mlx_hook(cub->win, 2, 1L<<0, &key_press, cub);
	mlx_hook(cub->win, 3, 1L<<1, &key_release, cub);
	// mlx_hook(cub->win, 17, 0L, &exit, cub);
	mlx_loop_hook(cub->mlx, &read_keys, cub);
	mlx_do_sync(cub->mlx);
	mlx_loop(cub->mlx);
	return (0);
}
