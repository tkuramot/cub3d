/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/27 00:28:05 by tkuramot         ###   ########.fr       */
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

unsigned int	extract_color_from_texture(t_texture *texture, int y, int x)
{
	char	*dst;

	dst = texture->addr
		+ (y * texture->line_length
			+ x * (texture->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	render_textured_wall_vertical_line(t_world *world, t_dda *dda, t_texture *texture, double dist_camera_plane_to_wall, int window_x)
{
	double	wall_x;

	if (dda->hit_side == WEST || dda->hit_side == EAST)
		wall_x = world->player.precise_pos.y * dist_camera_plane_to_wall;
	else
		wall_x = world->player.precise_pos.x * dist_camera_plane_to_wall;
	wall_x -= floor(wall_x);

	int		texture_x;
	int		texture_y;
	int		window_y;
	double	temp_texture_y;
	double	step;
	int		line_height;
	int		line_start;
	int		line_end;
	unsigned int	color;

	texture_x = (int)(wall_x * texture->width);
	if (dda->hit_side == WEST)
		texture_x = texture->width - texture_x - 1;
	if (dda->hit_side == NORTH)
		texture_x = texture->width - texture_x - 1;
	line_height = (int)(WINDOW_HEIGHT / dist_camera_plane_to_wall);
	line_start = -line_height / 2 + WINDOW_HEIGHT / 2;
	if (line_start < 0)
		line_start = 0;
	line_end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (line_end >= WINDOW_HEIGHT)
		line_end = WINDOW_HEIGHT - 1;
	step = 1.0 * texture->height / line_height;
	window_y = line_start;
	// TODO Zero ?
	temp_texture_y = (int)(line_start - WINDOW_HEIGHT / 2 + line_height / 2) * step;
	while (window_y < line_end)
	{
		texture_y = (int)(temp_texture_y) & (texture->height - 1);
		temp_texture_y += step;
		color = extract_color_from_texture(texture, texture_y, texture_x);
		my_mlx_pixel_put(&world->mlx_data.frame_buffer, window_y, window_x, color);
		window_y++;
	}
}

int	game_loop(t_world *world)
{
	t_dda	dda;
	int		window_x;
	double	dist_camera_plane_to_wall;

	key_handler(world);
	render_floor(&world->mlx_data, world->floor_color);
	render_ceiling(&world->mlx_data, world->ceiling_color);
	window_x = 0;
	while (window_x < WINDOW_WIDTH)
	{
		prepare_dda(world, &dda, window_x);
		perform_dda(world, &dda);
		dist_camera_plane_to_wall = get_dist_camera_plane_to_wall(&dda);
		render_textured_wall_vertical_line(world, &dda, &world->mlx_data.textures[0], dist_camera_plane_to_wall, window_x);
		window_x++;
	}
	frame_buffer_apply(&world->mlx_data);
	return (0);
}
