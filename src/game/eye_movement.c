/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eye_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:52:39 by tokazaki          #+#    #+#             */
/*   Updated: 2023/11/19 21:56:53 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "game.h"
#include "type.h"
#include <math.h>

static void	rotate_vector(t_vec2d *v, double angle)
{
	double	temp_x;

	temp_x = v->x;
	v->x = v->x * cos(angle) - v->y * sin(angle);
	v->y = temp_x * sin(angle) + v->y * cos(angle);
}

static void	rotate_camera_plane(t_vec2d *camera_plane, double angle)
{
	double	temp_x;

	temp_x = camera_plane->x;
	camera_plane->x = camera_plane->x * cos(angle) \
		- camera_plane->y * sin(angle);
	camera_plane->y = temp_x * sin(angle) + camera_plane->y * cos(angle);
}

void	move_eye_movement(t_world *world, int rotate_direction)
{
	double	rotate_dir;

	rotate_dir = ROTATE_SPEED * rotate_direction;
	rotate_vector(&world->player.dir, rotate_dir);
	rotate_camera_plane(&world->player.camera_plane, rotate_dir);
}
//ft_dprintf(2, "dir.x:%f dir.y:%f\n",world->player.dir.x, world->player.dir.y);
