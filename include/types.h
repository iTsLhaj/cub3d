/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:18:03 by agaougao          #+#    #+#             */
/*   Updated: 2025/01/23 18:35:46 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_vect2
{
    float       x;
    float       y;
}               t_vect2;

typedef struct s_ray
{
    double      x;
    double      y;
    double      angle;
    double      dir_x;
    double      dir_y;
    double      wall_hit_x;
    double      wall_hit_y;
    int         map_x;
    int         map_y;
    double      wall_dist;
    int         side;
    int         index;
}               t_ray;

typedef struct s_player
{
    double      pos_x;
    double      pos_y;
    double      dir_x;
    double      dir_y;
    double      angle_dir;
    int         ud;
    int         lr;
    int         ro;
}               t_player;

typedef struct s_map
{
    char        **map;
    int         width;
    int         height;
}               t_map;

typedef struct s_distance
{
    size_t      height;
    size_t      width;
}               t_distance;

typedef struct s_img
{
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         size_line;
    int         endian;
    t_distance  distance;
}               t_img;
typedef struct s_game
{
    void        *mlx;
    void        *win;
    void        *img;
    char        *addr;
    t_img       *texture_buffer[4];
    int         bpp;
    int         height;
    int         width;
    int         line_len;
    int         endian;
    t_player    *player;
    t_map       *map;
    char        *file;
    char        *no;
    char        *so;
    char        *we;
    char        *ea;
    char        **f;
    char        **c;
    int         floor_color;
    int         ceiling_color;
    double      w_height;
    t_vect2     hint_points;
    t_vect2     vint_points;
}               t_game;

#endif