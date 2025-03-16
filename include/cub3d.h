/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:18:50 by agaougao          #+#    #+#             */
/*   Updated: 2025/03/15 14:49:34 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <get_next_line.h>
# include <libft.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <ctype.h>

# define MINIMAP_WIDTH 192
# define MINIMAP_HEIGHT 192
# define MINIMAP_SCALE 0.25
# define MINIMAP_WALL_CLR  0x690B22
# define MINIMAP_EMPTY_CLR  0xF7F7F7
# define MINIMAP_PLAYER_CLR 0x0000FF

# define WIN_WIDTH 1280
# define WIN_HEIGHT 960
# define WIN_TITLE "CUB3D"
# define MOVE_SPEED 8.6
# define ROT_SPEED 0.07
# define M_PI 3.14159265358979323846
# define TILE_SIZE 64
# define FOV_DEG 60
# define COLOR_FLOOR 0x9B7653
# define COLOR_CEILING 0xD9EAFD

# include <protos.h>
# include <types.h>

#endif