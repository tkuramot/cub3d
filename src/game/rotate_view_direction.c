/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_view_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:52:39 by tokazaki          #+#    #+#             */
/*   Updated: 2023/11/22 02:27:33 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "game.h"
#include "type.h"
#include <math.h>

static void	rotate_vector(t_vec2d *v, double cos_angle, double sin_angle)
{
	double	temp_x;

	temp_x = v->x;
	v->x = v->x * cos_angle - v->y * sin_angle;
	v->y = temp_x * sin_angle + v->y * cos_angle;
}

void	rotate_view_direction(t_world *world, double rotate_dir)
{
	double	cos_angle;
	double	sin_angle;

	cos_angle = cos(rotate_dir);
	sin_angle = sin(rotate_dir);
	rotate_vector(&world->player.dir, cos_angle, sin_angle);
	rotate_vector(&world->player.camera_plane, cos_angle, sin_angle);
}
//ft_dprintf(2, "dir.x:%f dir.y:%f\n",world->player.dir.x, world->player.dir.y);
