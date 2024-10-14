NAME	=	cub3d
CC		=	cc
# CFLAGS	=	-Wall -Werror -Wextra # -lm -lz
LIBS	=	libs/libft/libft.a	\
			libs/gcollector/gcollector.a
LMLX	=	-lmlx -lXext -lX11
SOURCES	=	libs/get_next_line/get_next_line.c	\
			src/main.c \
			src/utils.c
OBJECTS	=	$(SOURCES:.c=.o)
INCLUDE	=	-I include/
RM		=	rm -rf
MK		=	make -C



all: mklib $(NAME)

mklib:
	$(MK) libs/libft
	$(MK) libs/gcollector

$(NAME): $(OBJECTS)
	$(CC) $(INCLUDE) $(CFLAGS) $^ -o $@ $(LIBS) $(LMLX)

%.o: %.c
	$(CC) $(INCLUDE) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	$(MK) libs/libft clean
	$(MK) libs/gcollector clean

fclean: clean
	$(RM) $(NAME)
	$(MK) libs/libft fclean
	$(MK) libs/gcollector fclean

re: fclean all
