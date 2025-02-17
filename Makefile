NAME		=	cub3d
CC			=	gcc -g # -Wall -Wextra -Werror
CFLAGS		=	-fsanitize=address # -Wall -Wextra -Werror
SRC			=	src/main.c									\
				libs/get_next_line/get_next_line.c			\
				libs/get_next_line/get_next_line_utils.c	\
				src/parser/utils.c							\
				src/parser/check_map_wall.c					\
				src/parser/check_wall.c						\
				src/parser/checks.c							\
				src/engine/init.c							\
				src/engine/hooks.c							\
				src/engine/movement.c						\
				src/engine/utils.c							\
				src/engine/raycaster/raycaster.c			\
				src/engine/raycaster/inters.c				\
				src/engine/raycaster/utils.c				\
				src/engine/render.c							\
				src/parser/utils.c							\
				src/engine/handle_textures.c				\
				src/parser/utils2.c							\
				src/engine/minimap.c
OBJ			=	$(SRC:.c=.o)
INC			=	-I include/
LIBS		=	libs/pre-compiled/libft.a libs/pre-compiled/libncollector.a
LMLX		=	-lmlx -lXext -lX11 -lm -lz



all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(INC) $^ -o $@ $(CFLAGS) $(LIBS) $(LMLX)

%.o: %.c
	$(CC) $(INC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re