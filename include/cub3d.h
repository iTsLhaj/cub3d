/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:18:50 by agaougao          #+#    #+#             */
/*   Updated: 2025/01/23 18:18:51 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <get_next_line.h>
# include <libft.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>


# define MINIMAP_WIDTH 200
# define MINIMAP_HEIGHT 200
# define MINIMAP_SCALE 0.2


# define WIN_WIDTH 1280
# define WIN_HEIGHT 960
# define WIN_TITLE "CUB3D"
# define MOVE_SPEED 4.6
# define ROT_SPEED 0.05
# define M_PI 3.14159265358979323846
# define TILE_SIZE 64
# define FOV_DEG 60
# define FOV_RD FOV_DEG * (M_PI / 180)
# define COLOR_PRIMARY 0x343131
# define COLOR_SECONDARY 0xA04747
# define COLOR_FLOOR 0x9B7653
# define COLOR_CEILING 0xD9EAFD

# include <protos.h>
# include <types.h>

#endif