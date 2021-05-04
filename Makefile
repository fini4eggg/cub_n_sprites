NAME = cub3D
HEADER = cub3d.h
SRCS = cub3d.c\
		get_next_line_utils.c\
		get_next_line.c\
		ft_lstadd_back.c\
		ft_lstlast.c\
		ft_lstnew.c\
		ft_lstsize.c\
		ft_putendl_fd.c\
		parser.c\
		keys.c\
		stripe.c\
		draw_line.c\
		raycasting.c\
		raycasting2.c\
		save.c\
		map_validate.c\
		params_check.c\
		path_check.c\
		path_check2.c\
		set_player.c\
		sprites.c\
		read_keys.c\
		init.c
	   

OBJS = $(SRCS:.c=.o)

CC = clang

RM = rm -rf

CFLAGS = -g -Wall -Werror -Wextra

MACFLAGS = -framework OpenGL -framework Appkit

all:		$(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c -I./mlx -I./libft $< -o $(<:.c=.o)

$(NAME):	$(OBJS) $(HEADER)
		@make -C libft
		@make -C mlx
		@mv mlx/libmlx.dylib .
		@$(CC) $(CFLAGS) $(MACFLAGS) -o $(NAME) -L. -lmlx -I./mlx/ $(OBJS) ./libft/libft.a
		@echo project compiled

clean:		
		@$(RM) $(OBJS)
		@make clean -C libft
		@make clean -C mlx
		@echo object files removed

fclean:		clean
		@$(RM) $(NAME) cub3D.bmp libmlx.dylib
		@echo executable, dylib and bmp removed

re:		fclean all

leaks:
		valgrind --show-leak-kinds=definite --leak-check=full ./$(NAME) ./map.cub

.PHONY:		all clean fclean re
.SILENT:
