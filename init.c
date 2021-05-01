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
