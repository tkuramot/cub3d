/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perform_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 00:17:09 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/28 19:44:41 by tkuramot         ###   ########.fr       */
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
			dda->grid_pos.x += dda->next_step_dir.x;
			if (dda->ray_dir.x < 0)
				dda->hit_side = EAST;
			else
				dda->hit_side = WEST;
		}
		else
		{
			dda->ray_len_to_wall_y += dda->ray_len_btw_y_axis;
			dda->grid_pos.y += dda->next_step_dir.y;
			if (dda->ray_dir.y < 0)
				dda->hit_side = SOUTH;
			else
				dda->hit_side = NORTH;
		}
		if (world->map[dda->grid_pos.y][dda->grid_pos.x]
			== WALL)
			dda->did_hit_wall = true;
	}
}

void	calculate_dist_camera_plane_to_wall(t_dda *dda)
{
	if (dda->hit_side == WEST || dda->hit_side == EAST)
		dda->dist_camera_plane_to_wall = dda->ray_len_to_wall_x
			- dda->ray_len_btw_x_axis;
	else
		dda->dist_camera_plane_to_wall = dda->ray_len_to_wall_y
			- dda->ray_len_btw_y_axis;
}
