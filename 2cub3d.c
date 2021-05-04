// #include "cub3d.h"

// t_cub	init_cub(/*t_cub *cub, */int argc, char **argv, int *fd)
// {
// 	t_cub		*cub;
	
// 	cub = (t_cub *)malloc(sizeof(t_cub));
// 	if (cub == NULL)
// 	{
// 		printf("%s\n", strerror(errno));
// 		exit (1);
// 	}
// 	ft_init(cub);
// 	if (argc == 3)
// 	{
// 		if (!(ft_strncmp("--save", argv[2], ft_strlen(argv[1]))))
// 			cub->list.save = 1;
// 		*fd = open(argv[1], O_RDONLY);
// 	}
// 	if (argc == 2)
// 	{
// 		*fd = open(argv[1], O_RDONLY);
// 		cub->list.save = 0;
// 	}
// 	if (argc == 0 || argc > 3)
// 		exit (0);
// 	if (!argv)
// 		exit (0);
// 	cub->sprcast.cnt = 0;
// }

// int	main(int argc, char **argv)
// {
// 	static int	fd;
// 	char		*line;
// 	// t_cub		*cub;
// 	t_list		*head;

// 	line = NULL;
// 	head = NULL;
// 	// ft_init(cub);
// 	init_cub(/*cub, */argc, argv, &fd);
// 	while (get_next_line(fd, &line))
// 	{
// 		check_params_fill(&cub->list);
// 		cub->sprcast.cnt = 0;
// 		if (check_params(line, &cub->list))
// 			printf("Nothing\n");
// 		else if ((cub->list.params_fillment))
// 			ft_lstadd_back(&head, ft_lstnew(line));
// 	}
// 	ft_lstadd_back(&head, ft_lstnew(line));
// 	cub->map = make_map(&head, ft_lstsize(head));
// 	make_rectangle(cub, cub->map);
// 	set_player(cub);
// 	check_validity(cub->map, cub);
// 	draw(cub);
// 	return (0);
// }
