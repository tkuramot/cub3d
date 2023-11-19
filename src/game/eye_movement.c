/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eye_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:52:39 by tokazaki          #+#    #+#             */
/*   Updated: 2023/11/19 20:21:13 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "game.h"
#include "type.h"
#include "utils.h"
#include <stdio.h>
#include <math.h>

void	move_eye_movement(t_world *world, int rotate_direction)
{
	double	rotate_dir;
	double	old_dir_x;
	double	old_plane_x;

	rotate_dir = ROT_SPEED * rotate_direction;
	old_dir_x = world->player.dir.x;
	world->player.dir.x = world->player.dir.x * cos(rotate_dir) \
		- world->player.dir.y * sin(rotate_dir);
	world->player.dir.y = old_dir_x * sin(rotate_dir) \
		+ world->player.dir.y * cos(rotate_dir);
	old_plane_x = world->player.camera_plane.x;
	world->player.camera_plane.x = \
		world->player.camera_plane.x * cos(rotate_dir) \
		- world->player.camera_plane.y * sin(rotate_dir);
	world->player.camera_plane.y = old_plane_x * sin(rotate_dir) \
		+ world->player.camera_plane.y * cos(rotate_dir);
}
//printf("dir.x:%f dir.y:%f\n",world->player.dir.x, world->player.dir.y);
