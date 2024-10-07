#ifndef CUB3D_H
#define CUB3D_H

# include <libft.h>
# include <get_next_line.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>


typedef struct    s_cub3d
{
	void	*mlx;
	void	*win;
	void	*img;
	char **map;
	char *file;
}	t_cub3d;

#endif
