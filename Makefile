NAME = cub3D
HEADER = cub3d.h
SRCS = cub3d.c\
		get_next_line_utils.c\
		get_next_line.c\
		./funk/ft_lstadd_back.c\
		./funk/ft_lstlast.c\
		./funk/ft_lstnew.c\
		./funk/ft_lstsize.c\
		./funk/ft_putendl_fd.c\
		./map/parser.c\
		./raycast/keys.c\
		./raycast/stripe.c\
		./raycast/draw_line.c\
		./raycast/raycasting.c\
		./raycast/raycasting2.c\
		./raycast/save.c\
		./map/map_validate.c\
		./map/params_check.c\
		./map/path_check.c\
		./map/path_check2.c\
		./map/set_player.c\
		./raycast/sprites.c\
		./raycast/read_keys.c\
		./raycast/init.c\
		./raycast/exit.c
	   

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
run:all
	./cub3D ./map.cub
fclean:		clean
		@$(RM) $(NAME) cub3D.bmp libmlx.dylib
		@echo executable, dylib and bmp removed

re:		fclean all

leaks:
		valgrind --show-leak-kinds=definite --leak-check=full ./$(NAME) ./map.cub

.PHONY:		all clean fclean re
.SILENT:
