#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include <libft.h>
# include <get_next_line.h>

# define BONUS

# ifdef BONUS
# define MINIMAP_WIDTH       200
# define MINIMAP_HEIGHT      200
# define MINIMAP_SCALE       0.2
# endif

# define WIN_WIDTH          1280
# define WIN_HEIGHT         960
# define WIN_TITLE          "CUB3D"
# define MOVE_SPEED         2.25
# define ROT_SPEED          0.02
# define M_PI               3.14159265358979323846
# define TILE_SIZE          64
# define FOV_DEG            60
# define FOV_RD             FOV_DEG * (M_PI / 180)
# define COLOR_PRIMARY      0x343131
# define COLOR_SECONDARY    0xA04747
# define COLOR_FLOOR        0x9B7653
# define COLOR_CEILING      0xD9EAFD

# include <types.h>
# include <protos.h>

#endif