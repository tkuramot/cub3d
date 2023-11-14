/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/14 09:05:40 by tkuramot         ###   ########.fr       */
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

// Unused var
int	game_loop(void *arg)
{
	t_world	*world;
	t_dda	dda;
	int		x;
	double	dist_camera_plane_to_wall;
	int		line_height;

	(void)dist_camera_plane_to_wall;
	world = (t_world *)arg;
	x = 0;
	while (x < WINDOW_WIDTH)
	{
		prepare_dda(world, &dda, x);
		perform_dda(world, &dda);
		dist_camera_plane_to_wall = get_dist_camera_plane_to_wall(&dda);
		line_height = (int)(WINDOW_HEIGHT / dist_camera_plane_to_wall);
		world->mlx_data.frame_buffer.img = mlx_new_image(world->mlx_data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
		world->mlx_data.frame_buffer.addr = mlx_get_data_addr(world->mlx_data.frame_buffer.img, &world->mlx_data.frame_buffer.bits_per_pixel, &world->mlx_data.frame_buffer.line_length, &world->mlx_data.frame_buffer.endian);
		// draw_square(world, (t_vec2i){0, 0}, (t_vec2i){40, 40}, 0X00FF0000);
		render_wall_vertical_line(world, x, line_height, 0X00FF0000);
		mlx_put_image_to_window(world->mlx_data.mlx, world->mlx_data.mlx_win, world->mlx_data.frame_buffer.img, 0, 0);
		x++;
	}
	return (0);
}
