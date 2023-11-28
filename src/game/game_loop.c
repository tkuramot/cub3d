/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/28 14:32:18 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "dda.h"
#include "drawing.h"
#include "libft.h"
#include "mlx.h"
#include "type.h"
#include <math.h>
#include <stdio.h>
#include <utils.h>

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
	t_dda		dda;
	int			window_x;
	t_wall_line	line;

	key_handler(world);
	render_floor(&world->mlx_data, world->floor_color);
	render_ceiling(&world->mlx_data, world->ceiling_color);
	window_x = 0;
	while (window_x < WINDOW_WIDTH)
	{
		prepare_dda(world, &dda, window_x);
		perform_dda(world, &dda);
		calculate_dist_camera_plane_to_wall(&dda);
		calculate_line(&line, &dda);
		calculate_texture_position(&line, world, &dda, get_side_texture(world, &dda));
		render_textured_wall_vertical_line(world, get_side_texture(world, &dda), &line, window_x);
		window_x++;
	}
	frame_buffer_apply(&world->mlx_data);
	return (0);
}
