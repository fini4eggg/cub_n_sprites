#include "cub3d.h"

int ft_exit(char *str)
{
	if (str)
	{
		write(1, "Error\n", 7);
		write(1, str, ft_strlen(str));
	}
	// clear_cub
	exit (0);
}