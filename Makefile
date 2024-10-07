NAME	=	cub3d
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -lm -lz
LIBS	=	lib/libft/libft.a	\
			libs/gcollector/gcollector.a
LMLX	=	-lmlx -lXext -lX11
SOURCES	=	# <source files ...>
OBJECTS	=	$(SOURCES:.c=.o)
INCLUDE	=	-I include/
RM		=	rm -rf
MK		=	make -C



all: mklib $(NAME)

mklib:
	$(MK) lib/libft
	$(MK) lib/gcollector

$(NAME): $(OBJECTS)
	$(CC) $(INCLUDE) $(CFLAGS) $^ -o $@ $(LIBS) $(LMLX)

%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	$(MK) lib/libft clean
	$(MK) lib/gcollector clean

fclean: clean
	$(RM) $(NAME)
	$(MK) lib/libft fclean
	$(MK) lib/gcollector fclean

re: fclean all
