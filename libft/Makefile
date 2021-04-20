NAME = libft.a

FLAGS =	-Wall -Wextra -Werror

LIB_INC = $(addprefix $(INCLUDES), libft.h)

SRC =           ft_memccpy.c \
		ft_memcpy.c \
		ft_bzero.c \
		ft_memset.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_strlen.c \
		ft_memcmp.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_atoi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strmapi.c \
		ft_strtrim.c \
		ft_split.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_itoa.c

OBJ = $(patsubst %.c, %.o, $(SRC))

INCLUDES = ./

all: $(NAME)

$(NAME): $(OBJ) Makefile
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c $(LIB_INC)
	gcc $(FLAGS) -I $(INCLUDES) -c $<

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
