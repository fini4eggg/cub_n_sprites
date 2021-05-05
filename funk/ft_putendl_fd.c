#include "libft/libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!fd)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
