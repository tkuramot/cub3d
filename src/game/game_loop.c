/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/20 01:35:05 by tkuramot         ###   ########.fr       */
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

	render_floor(&world->mlx_data, world->floor_color);
	render_ceiling(&world->mlx_data, world->ceiling_color);
	x = 0;
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
	return (0);
}
