#include "cub3d.h"

void	cast_stripe(t_cub *cub, int y, int stripe)
{
	while (y < cub->sprcast.drawEndY)
	{
		cub->sprcast.d = y * 256 - cub->list.height * 128
			+ cub->sprcast.spriteHeight * 128;
		cub->sprcast.texY = ((cub->sprcast.d * cub->sprite.height)
				/ cub->sprcast.spriteHeight) / 256;
		cub->sprcast.color = *(unsigned int *)(cub->sprite.addr + \
		(cub->sprcast.texY * cub->sprite.line_length + cub->sprcast.texX * \
		(cub->sprite.bits_per_pixel / 8)));
		if ((cub->sprcast.color & 0x00FFFFFF) != 0)
			my_mlx_pixel_put(&cub->img, stripe, y, cub->sprcast.color);
		y++;
	}
}

void	stripe(t_cub *cub)
{
	int	stripe;
	int	y;

	stripe = cub->sprcast.drawStartX;
	while (stripe < cub->sprcast.drawEndX)
	{
		cub->sprcast.texX = (int)(256
				* (stripe - (-cub->sprcast.spriteWidth / 2
						+ cub->sprcast.spriteScreenX))
				* cub->sprite.width / cub->sprcast.spriteWidth) / 256;
		if (cub->sprcast.transformY > 0 && stripe > 0
			&& stripe < cub->list.width
			&& cub->sprcast.transformY < cub->sprcast.zbuffer[stripe])
		{
			y = cub->sprcast.drawStartY;
			cast_stripe(cub, y, stripe);
		}
		stripe++;
	}
}
