NAME	=	cub3d
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -lm -lz
LIBFT	=	lib/libft/libft.a
LMLX	=	-lmlx -lXext -lX11
SOURCES	=	# <source files ...>
OBJECTS	=	$(SOURCES:.c=.o)
INCLUDE	=	-I include/
RM		=	rm -rf
MK		=	make -C



all: libft $(NAME)

libft:
	$(MK) lib/libft

$(NAME): $(OBJECTS)
	$(CC) $(INCLUDE) $(CFLAGS) $^ -o $@ $(LIBFT) $(LMLX)

%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	$(MK) lib/libft clean

fclean: clean
	$(RM) $(NAME)
	$(MK) lib/libft fclean

re: fclean all
