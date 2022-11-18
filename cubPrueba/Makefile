SRC	=	main.c \
		check_map.c check.c ft_malloc.c helpers_1.c helpers_2.c info_map.c read.c get_next_line.c 

NAME 	= 	cub3d

CC 		= 	gcc
CFLAGS 	= 	-Wall -Wextra -Werror

OBJ		= 	$(SRC:.c=.o)


MLXLINK = -L mlx
MINILIBX = -I mlx
OPENGL = -lmlx -framework OpenGL -framework AppKit


all: $(NAME)

$(NAME): $(OBJ)
		make -C mlx
		$(CC) $(MLXLINK) $(MINILIBX) $(OPENGL) $^ -o $(NAME)

clean:
		make clean -C mlx
		/bin/rm -rf *.o

fclean: clean 
		/bin/rm -f $(NAME)

re: fclean all
.PHONY: all clean fclean re
