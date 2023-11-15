/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 23:54:03 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/13 00:15:07 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "libft.h"
#include "type.h"
#include "utils.h"

static void	init_ray_len_btw_axis(t_dda *dda)
{
	if (dda->ray_dir.x == 0)
		dda->ray_len_btw_x_axis = INFINITY;
	else
		dda->ray_len_btw_x_axis = double_abs(1 / dda->ray_dir.x);
	if (dda->ray_dir.y == 0)
		dda->ray_len_btw_y_axis = INFINITY;
	else
		dda->ray_len_btw_y_axis = double_abs(1 / dda->ray_dir.y);
}

static void	init_ray_len_to_wall(t_world *world, t_dda *dda)
{
	if (dda->ray_dir.x < 0)
	{
		dda->next_step_dir.x = -1;
		dda->ray_len_to_wall_x = (world->player.precise_pos.x
				- world->player.grid_pos.x) * dda->ray_len_btw_x_axis;
	}
	else
	{
		dda->next_step_dir.x = 1;
		dda->ray_len_to_wall_x = (world->player.grid_pos.x + 1.0
				- world->player.precise_pos.x) * dda->ray_len_btw_x_axis;
	}
	if (dda->ray_dir.y < 0)
	{
		dda->next_step_dir.y = -1;
		dda->ray_len_to_wall_y = (world->player.precise_pos.y
				- world->player.grid_pos.y) * dda->ray_len_btw_y_axis;
	}
	else
	{
		dda->next_step_dir.y = 1;
		dda->ray_len_to_wall_y = (world->player.grid_pos.y + 1.0
				- world->player.precise_pos.y) * dda->ray_len_btw_y_axis;
	}
}

void	prepare_dda(t_world *world, t_dda *dda, int x)
{
	ft_bzero(dda, sizeof(t_dda));
	dda->camera_x = 2 * x / (double)WINDOW_WIDTH - 1;
	dda->ray_dir.x = world->player.dir.x
		+ world->player.camera_plane.x * dda->camera_x;
	dda->ray_dir.y = world->player.dir.y
		+ world->player.camera_plane.y * dda->camera_x;
	world->player.grid_pos.x = (int)world->player.precise_pos.x;
	world->player.grid_pos.y = (int)world->player.precise_pos.y;
	init_ray_len_btw_axis(dda);
	init_ray_len_to_wall(world, dda);
}
