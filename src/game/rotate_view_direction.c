/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_view_direction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 16:52:39 by tokazaki          #+#    #+#             */
/*   Updated: 2023/11/22 01:40:26 by tokazaki         ###   ########.fr       */
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

void	rotate_view_direction(t_world *world, double rotate_dir)
{
	rotate_vector(&world->player.dir, rotate_dir);
	rotate_vector(&world->player.camera_plane, rotate_dir);
}
//ft_dprintf(2, "dir.x:%f dir.y:%f\n",world->player.dir.x, world->player.dir.y);
