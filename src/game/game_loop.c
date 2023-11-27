/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/28 01:13:20 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "dda.h"
#include "drawing.h"
#include "libft.h"
#include "mlx.h"
#include "type.h"
#include <stdint.h>
#include <stdio.h>
#include <utils.h>
#include <stdbool.h>

void	move_forward(t_world *world);
void	move_rightward(t_world *world);
void	move_backward(t_world *world);
void	move_leftward(t_world *world);
void	move_forward_right(t_world *world);
void	move_forward_left(t_world *world);
void	move_backward_right(t_world *world);
void	move_backward_left(t_world *world);
void	rotate_view_direction(t_world *world, double rotate_dir);

void	key_handler(t_world *world)
{
	if (world->key_press.is_left_arrow)
		rotate_view_direction(world, LEFT * ROTATE_KEY_SPEED);
	if (world->key_press.is_right_arrow)
		rotate_view_direction(world, RIGHT * ROTATE_KEY_SPEED);
	if (world->key_press.is_w && world->key_press.is_d)
		move_forward_right(world);
	else if (world->key_press.is_w && world->key_press.is_a)
		move_forward_left(world);
	else if (world->key_press.is_s && world->key_press.is_d)
		move_backward_right(world);
	else if (world->key_press.is_s && world->key_press.is_a)
		move_backward_left(world);
	else if (world->key_press.is_w)
		move_forward(world);
	else if (world->key_press.is_a)
		move_leftward(world);
	else if (world->key_press.is_s)
		move_backward(world);
	else if (world->key_press.is_d)
		move_rightward(world);
}

int	game_loop(t_world *world)
{
	t_dda	dda;
	int		x;
	double	dist_camera_plane_to_wall;
	int		line_height;

	key_handler(world);
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
	render_minimap(world);
	frame_buffer_apply(&world->mlx_data);
	return (0);
}
