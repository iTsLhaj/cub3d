NAME		=	cub3d
CC			=	cc -g
CFLAGS		=	-Wall -Wextra -Werror
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
				src/parser/utils3.c							\
				src/mem_clean.c
OBJ			=	$(SRC:.c=.o)
INC			=	-I include/
# LIBS		=	libs/pre-compiled/libft.a libs/pre-compiled/libncollector.a
LIBFT		=	libs/libft/libft.a
LMLX		=	-lmlx -lXext -lX11 -lm -lz
MAKE		=	make -C


all: libft $(NAME)

libft:
	@$(MAKE) libs/libft

$(NAME): $(OBJ)
	$(CC) $(INC) $^ -o $@ $(CFLAGS) $(LIBFT) $(LMLX)

%.o: %.c
	$(CC) $(INC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) libs/libft clean
	rm -f $(OBJ)

fclean: clean
	@$(MAKE) libs/libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
