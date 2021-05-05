#include "cub3d.h"

void	draw_floor(t_cub *cub, int drawStart, int drawEnd, int coords[2])
{
	int		ceiling;
	int		floor;

	ceiling = 0;
	while (ceiling < drawStart)
	{
		my_mlx_pixel_put(&cub->img, coords[0], ceiling, cub->list.clclr);
		ceiling++;
	}
	while (coords[1] < drawEnd)
	{
		cub->ray.texy = (int)cub->ray.texpos & (cub->current.height - 1);
		cub->ray.texpos += cub->ray.step;
		cub->ray.color = *(unsigned int *)(cub->current.addr + (cub->ray.texy
					* cub->current.line_length + cub->ray.texx
					* (cub->current.bits_per_pixel / 8)));
		my_mlx_pixel_put(&cub->img, coords[0], coords[1], cub->ray.color);
		coords[1]++;
	}
	floor = drawEnd + 1;
	while (floor < cub->list.height)
	{
		my_mlx_pixel_put(&cub->img, coords[0], floor, cub->list.flclr);
		floor++;
	}
}

void	chose_side(t_cub *cub)
{
	if (cub->ray.side == 0)
		cub->ray.wallx = cub->ray.playerY + \
		cub->ray.perpWallDist * cub->ray.rayDirY;
	else
		cub->ray.wallx = cub->ray.playerX + \
		cub->ray.perpWallDist * cub->ray.rayDirX;
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
	chose_side(cub);
	cub->ray.wallx -= floor(cub->ray.wallx);
	cub->ray.texx = (int)(cub->ray.wallx * (double)(cub->current.width));
	if (cub->ray.side == 0 && cub->ray.rayDirX > 0)
		cub->ray.texx = cub->current.width - cub->ray.texx - 1;
	if (cub->ray.side == 1 && cub->ray.rayDirY < 0)
		cub->ray.texx = cub->current.width - cub->ray.texx - 1;
	cub->ray.step = (double)cub->current.height / lineHeight;
	cub->ray.texpos = (drawStart - cub->list.height / 2 + \
	lineHeight / 2) * cub->ray.step;
	draw_floor(cub, drawStart, drawEnd, (int [2]){x, y});
}
