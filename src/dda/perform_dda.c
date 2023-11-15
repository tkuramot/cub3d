/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:17:09 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/15 17:15:57 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "type.h"
#include <stdio.h>

void	perform_dda(t_world *world, t_dda *dda)
{
	while (!dda->did_hit_wall)
	{
		if (dda->ray_len_to_wall_x < dda->ray_len_to_wall_y)
		{
			dda->ray_len_to_wall_x += dda->ray_len_btw_x_axis;
			dda->hit_axis = X_AXIS;
			world->player.grid_pos.x += dda->next_step_dir.x;
		}
		else
		{
			dda->ray_len_to_wall_y += dda->ray_len_btw_y_axis;
			dda->hit_axis = Y_AXIS;
			world->player.grid_pos.y += dda->next_step_dir.y;
		}
		if (world->map[world->player.grid_pos.y][world->player.grid_pos.x]
			== WALL)
			dda->did_hit_wall = true;
	}
}

double	get_dist_camera_plane_to_wall(t_dda *dda)
{
	if (dda->hit_axis == X_AXIS)
		return (dda->ray_len_to_wall_x - dda->ray_len_btw_x_axis);
	else
		return (dda->ray_len_to_wall_y - dda->ray_len_btw_y_axis);
}
