#include "libft/libft.h"

t_list	*ft_lstlast(t_list *list)
{
	if (list && list->next)
		return (ft_lstlast(list->next));
	return (list);
}
