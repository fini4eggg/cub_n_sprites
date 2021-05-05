#include "cub3d.h"

int	check_intro(t_cub *cub, int argc, char **argv)
{
	int	fd;

	if (argc == 3)
	{
		if ((ft_strncmp("--save", argv[2], ft_strlen("--save")) == 0))
			cub->list.save = 1;
		else
			exit (0);
		fd = open(argv[1], O_RDONLY);
	}
	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		cub->list.save = 0;
	}
	if (argc == 0 || argc > 3)
		ft_exit("Введено некорректное количество параметров");
	if (!argv)
		ft_exit("Введен неверный аргумент");
	cub->sprcast.cnt = 0;
	return (fd);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	t_cub	*cub;
	t_list	*head;

	fd = -1;
	line = NULL;
	head = NULL;
	cub = (t_cub *)ft_calloc(1, sizeof(t_cub));
	if (cub == NULL)
		ft_exit("Ошибка выделения памяти");
	ft_init(cub);
	fd = check_intro(cub, argc, argv);
	while (get_next_line(fd, &line) && fd >= 0)
	{
		check_params_fill(&cub->list);
		cub->sprcast.cnt = 0;
		if (check_params(line, &cub->list))
			printf("Nothing\n");
		else if ((cub->list.params_fillment))
			ft_lstadd_back(&head, ft_lstnew(line));
	}	
	ft_lstadd_back(&head, ft_lstnew(line));
	free(line);
	cub->map = make_map(&head, ft_lstsize(head));
	make_rectangle(cub, cub->map);
	set_player(cub);
	check_validity(cub->map, cub);
	draw(cub);
	close(fd);
	return (0);
}
