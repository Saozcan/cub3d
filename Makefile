NAME = cub3D

SRC = $(wildcard *.c)

MAP  = map_parse/map.a

OBJ = $(SRC:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

MLX = -Lmlx -lmlx -framework OpenGL -framework AppKit mlx/libmlx.a

MLX_LINUX = -lXext -lX11 -lm -lz

42-GET_NEXT_LINE = 42-Get_next_line/get_next_line.c 42-Get_next_line/get_next_line_utils.c

Libft = Libft/libft.a

all : $(OBJ)
	@$(CC) $(SRC) libmlx_macos.a -framework OpenGL -framework AppKit -o $(NAME) -fsanitize=address

linux : $(OBJ)
	@$(CC) $(SRC) libmlx.a $(MLX_LINUX) -o $(NAME)


%.o: %.c
	@$(CC) -c $< -o $@

clean :
	@rm -rf *.o

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re deneme testdeneme

norm :
	norminette