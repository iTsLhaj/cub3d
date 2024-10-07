NAME	=	cub3d
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
LMLX	=	-lmlx -lXext -lX11
SOURCES	=	# <source files ...>
OBJECTS	=	$(SOURCES:.c=.o)
INCLUDE	=	-I include/
RM		=	rm -rf



all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(INCLUDE) $(CFLAGS) $^ -o $@ $(LMLX)

%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
