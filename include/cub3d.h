/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaougao <agaougao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 18:18:50 by agaougao          #+#    #+#             */
/*   Updated: 2025/03/19 23:01:56 by agaougao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <ctype.h>
# include <fcntl.h>
# include <get_next_line.h>
# include <libft.h>
# include <math.h>
# include <mlx.h>
# include <stdlib.h>

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