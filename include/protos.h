/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protos.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:19:30 by agaougao          #+#    #+#             */
/*   Updated: 2025/03/14 15:50:31 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOS_H
# define PROTOS_H

# include <types.h>

double  normalize_angle(double angle);
void    pixel_put(t_game *game, int x, int y, int color);
int     wall_collision(t_game *game, double new_x, double new_y);

int     init_mlx(t_game *game);
void    init_player(t_game *cube, t_player *player);

int     key_press(int keycode, t_game *game);
int     key_release(int keycode, t_game *game);

void    update_player(t_game *game);

int     touch(t_game *game, double x, double y);
int     inter_check(float angle, float *inter, float *step, char dir);
int     unit_circle(float angle, char axis);

float   get_hinter(t_game *game, float angle);
float   get_vinter(t_game *game, float angle);
void    cast_rays(t_game *game);

void    render_wall(t_game *game, t_ray *ray);

int     convert_color(t_game *cube, int fc);
void    ft_set_data(t_game *cube, int i, int j);
int     count_commas(char *str);
int     ft_check_for_space(char *str);
int     check_arg(int ac, char **av);
int     check_wall_len(char **map);

int     check_map_wall(t_game *cube);
int     check_map(t_game *cube, char **av);
void    get_texture(t_game *game);
int     get_len(char **map);
char    **ft_copy_map_to_rect_map(char **map);
int     get_max_width(char **map);
int     check_first_wall(char **map);
int     get_color(t_game *game, t_ray *ray);

int     ft_end(t_game *game);
void    free_all(char **str);
char    **ft_copy_map_to_rect_map2(char **map);
int     check_color(t_game *cube);
int check_num_colors(char *str);

#endif