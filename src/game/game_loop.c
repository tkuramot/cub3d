/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/17 00:54:52 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "dda.h"
#include "drawing.h"
#include "libft.h"
#include "mlx.h"
#include "type.h"
#include <stdio.h>
#include <utils.h>

int	game_loop(t_world *world)
{
	t_dda	dda;
	int		x;
	double	dist_camera_plane_to_wall;
	int		line_height;

	x = 0;
	frame_buffer_allocate(&world->mlx_data);
	while (x < WINDOW_WIDTH)
	{
		prepare_dda(world, &dda, x);
		perform_dda(world, &dda);
		dist_camera_plane_to_wall = get_dist_camera_plane_to_wall(&dda);
		line_height = (int)(WINDOW_HEIGHT / dist_camera_plane_to_wall);
		render_wall_vertical_line(&world->mlx_data, x, line_height, 0X00FF0000);
		x++;
	}
	frame_buffer_apply(&world->mlx_data);
	frame_buffer_destroy(&world->mlx_data);
	return (0);
}
