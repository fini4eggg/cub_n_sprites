#include "cub3d.h"

void	head(int fd, t_cub *cub, int res, int size)
{
	char	header[54];

	ft_bzero(header, 54);
	header[0] = 0x42;
	header[1] = 0x4D;
	ft_memcpy(&header[2], &size, 4);
	header[10] = 0x36;
	header[14] = 0x28;
	ft_memcpy(&header[18], &res, 4);
	res = -(cub->list.height);
	ft_memcpy(&header[22], &res, 4);
	header[26] = 0x01;
	header[28] = 0x20;
	write(fd, header, 54);
}

void	screenshot(t_cub *cub)
{
	int	fd;
	int	res;
	int	size;

	res = cub->list.width;
	size = 54 + (cub->list.width * cub->list.height) * 4;
	fd = open("screenshot.bmp", O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (fd < 0)
		exit(0);
	head(fd, cub, res, size);
	write(fd, cub->img.addr, (cub->list.width * cub->list.height * 4));
	close(fd);
	exit(0);
}
