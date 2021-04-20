/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bryella <bryella@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/21 01:57:29 by bryella           #+#    #+#             */
/*   Updated: 2021/03/21 01:58:52 by bryella          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**make_map(t_list **head, int size)
{
	char		**map;
	int			i;
	t_list		*tmp;

	map = ft_calloc(size + 1, sizeof(char *));
	i = -1;
	tmp = *head;
	while (tmp)
	{
		map[++i] = tmp->content;
		tmp = tmp->next;
	}
	i = -1;
	while (map[++i])
		ft_putendl_fd(map[i], 1);
	return (map);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		*line;
	t_list		*head;

	if (argc < 2)
		exit(0);
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	head = NULL;
	while (get_next_line(fd, &line))
		ft_lstadd_back(&head, ft_lstnew(line));
	ft_lstadd_back(&head, ft_lstnew(line));
	make_map(&head, ft_lstsize(head));
}
