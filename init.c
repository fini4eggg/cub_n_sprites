#include "cub3d.h"

void	ft_init(t_cub *cub)
{
	cub->list.clclr = 0;
	cub->list.flclr = 0;
	cub->list.no_path = NULL;
	cub->list.so_path = NULL;
	cub->list.ea_path = NULL;
	cub->list.we_path = NULL;
	cub->list.s_path = NULL;
}

void	init_txt_check(t_cub *cub)
{
	if (cub->north.img == NULL || cub->south.img == NULL
		|| cub->west.img == NULL || cub->east.img == NULL
		|| cub->sprite.img == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
	if (cub->north.addr == NULL || cub->south.addr == NULL
		|| cub->west.addr == NULL || cub->east.addr == NULL
		|| cub->sprite.addr == NULL)
	{
		printf("%s\n", strerror(errno));
		exit(1);
	}
}

void	init_txt_addr(t_cub *cub)
{
	cub->north.addr = mlx_get_data_addr(cub->north.img,
			&cub->north.bits_per_pixel, &cub->north.line_length,
			&cub->north.endian);
	cub->south.addr = mlx_get_data_addr(cub->south.img,
			&cub->south.bits_per_pixel, &cub->south.line_length,
			&cub->south.endian);
	cub->east.addr = mlx_get_data_addr(cub->east.img,
			&cub->east.bits_per_pixel, &cub->east.line_length,
			&cub->east.endian);
	cub->west.addr = mlx_get_data_addr(cub->west.img,
			&cub->west.bits_per_pixel, &cub->west.line_length,
			&cub->west.endian);
	cub->sprite.addr = mlx_get_data_addr(cub->sprite.img,
			&cub->sprite.bits_per_pixel, &cub->sprite.line_length,
			&cub->sprite.endian);
	init_txt_check(cub);
}

void	init_txt(t_cub *cub)
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
	init_txt_addr(cub);
}
