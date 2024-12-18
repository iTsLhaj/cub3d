#ifndef TYPES_H
# define TYPES_H

typedef struct s_ray
{
	double	x;
	double	y;
	double	angle;
	double	dir_x;
	double	dir_y;
	double	wall_hit_x;
	double	wall_hit_y;
	int		map_x;
	int		map_y;
	double	wall_dist;
	int		side; // vertical: 0, horizontal: 1
	int		index;
}	t_ray;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	angle_dir;
	int		ud; // up: 1, down: -1, none: 0
	int		lr; // left: 1, right: -1, none: 0
	int		ro; // rotate_left: 1, rotate_right: -1, none: 0
}	t_player;

typedef struct s_map
{
	char	**map;
	int		width;
	int		height;
}	t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	t_player	*player;
	t_map		*map;
	char		*file;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		**f;
	char		**c;
	int			floor_color;
	int			ceiling_color;
}	t_game;

#endif