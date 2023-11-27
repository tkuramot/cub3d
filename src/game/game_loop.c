/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/27 19:16:27 by tokazaki         ###   ########.fr       */
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

#define MINIMAP_PLAYER_POS 110
#define MINIMAP_RADIUS_SIZE 100
#define MINIMAP_PIXEL_SIZE 10
#define MINIMAP_MARGIN 3
#define MINIMAP_WALL_BLOCK_SIZE 5

void	move_forward(t_world *world);
void	move_rightward(t_world *world);
void	move_backward(t_world *world);
void	move_leftward(t_world *world);
void	move_forward_right(t_world *world);
void	move_forward_left(t_world *world);
void	move_backward_right(t_world *world);
void	move_backward_left(t_world *world);
void	rotate_view_direction(t_world *world, double rotate_dir);

void	my_mlx_pixel_put(t_frame_buffer *frame_buffer,
				int x, int y, int color);

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

//色を透過して表示する方法
void translucent_my_mlx_pixel_put(t_frame_buffer *frame_buffer,
                                   int x, int y, int color)
{
    char *dst;
    unsigned int *existing_color;
    int alpha;

    dst = frame_buffer->addr + (y * frame_buffer->line_length + x * (frame_buffer->bits_per_pixel / 8));
    existing_color = (unsigned int *)dst;
    alpha = 200;
	*existing_color = \
		(((*existing_color & 0xFF00FF) * (255 - alpha) + (color & 0xFF00FF) * alpha) / 255) +
		((((*existing_color >> 8) & 0xFF) * (255 - alpha) + ((color >> 8) & 0xFF) * alpha) / 255 << 8) +
		(((*existing_color >> 16) * (255 - alpha) + (color >> 16) * alpha) / 255 << 16);
}

#include <math.h>
//円を表示する方法
void draw_circle(t_world *world, int center, int radius, int color) {
	int	angle;
	int	x;
	int	y;

	angle = 0;
	while (angle < 360)
	{
		double radian = angle * M_PI / 180.0;
		x = center + (int)(radius * cos(radian));
		y = center + (int)(radius * sin(radian));
		my_mlx_pixel_put(&world->mlx_data.frame_buffer, x, y, color);
		angle++;
	}
}

//bool	is_render_mini_map(int x, int y)
//{
//	int	min_height;
//	int	max_height;
//
//	min_height = MINIMAP_PLAYER_POS - MINIMAP_RADIUS_SIZE;
//	max_height = MINIMAP_PLAYER_POS + MINIMAP_RADIUS_SIZE;
//	if (x < min_height || max_height < x)
//		return (false);
//	if (y < min_height || max_height < y)
//		return (false);
//	return (true);
//}

bool	is_render_mini_map(int x, int y, int center, int radius)
{
	int	distance_squared;

	distance_squared = (x - center) * (x - center) \
					   + (y - center) * (y - center);
	if (distance_squared <= radius * radius)
		return (true);
	else
		return (false);
}

//minimapに壁ブロックの描画
void	render_wall_brock(t_world *world, int i, int j)
{
	int k;
	int l;
	int x;
	int y;

	x = MINIMAP_PLAYER_POS - world->player.precise_pos.x * MINIMAP_PIXEL_SIZE;
	y = MINIMAP_PLAYER_POS - world->player.precise_pos.y * MINIMAP_PIXEL_SIZE;

	k = 0;
	while (k < 5)
	{
		l = 0;
		while (l < 5)
		{
			if (is_render_mini_map(i + x + k, j + y + l, MINIMAP_PLAYER_POS, MINIMAP_RADIUS_SIZE) == true)
			{
				my_mlx_pixel_put(&world->mlx_data.frame_buffer, i + k + x, j + l + y, 0xFFFFFF);
			}
			l++;
		}
		k++;
	}
}

//どのに壁があるか確認する
void	render_map(t_world *world)
{
	int	i;
	int	j;

	i = 0;
	while (world->map[i] != NULL)
	{
		j = 0;
		while (world->map[i][j] != '\0')
		{
			if (world->map[i][j] == WALL)
				render_wall_brock(world, j * 10, i * 10);
			j++;
		}
		i++;
	}
}

//#define MINIMAP_PLAYER_POS 100
//#define MINIMAP_RADIUS_SIZE 100
//#define MINIMAP_PIXEL_SIZE 10
//#define MINIMAP_WALL_BLOCK_SIZE 5


//mapのベースを描画する
void	render_map_base(t_world *world)
{
	int	i;
	int	j;

	i = MINIMAP_PLAYER_POS - MINIMAP_RADIUS_SIZE - MINIMAP_MARGIN;
	while (i < MINIMAP_PLAYER_POS + MINIMAP_RADIUS_SIZE + MINIMAP_MARGIN)
	{
		j = MINIMAP_PLAYER_POS - MINIMAP_RADIUS_SIZE - MINIMAP_MARGIN;
		while (j < MINIMAP_PLAYER_POS + MINIMAP_RADIUS_SIZE + MINIMAP_MARGIN)
		{
			if (is_render_mini_map(i, j, MINIMAP_PLAYER_POS, MINIMAP_RADIUS_SIZE) == true)
				translucent_my_mlx_pixel_put(&world->mlx_data.frame_buffer, i, j, 0xfff462);
			else if (is_render_mini_map(i, j, MINIMAP_PLAYER_POS, MINIMAP_RADIUS_SIZE + MINIMAP_MARGIN) == true)
				my_mlx_pixel_put(&world->mlx_data.frame_buffer, i, j, 0xFFFFFF);
			j++;
		}
		i++;
	}
}

//プレイヤーの場所の表示
void	render_player(t_world *world)
{
	int	i;
	int	j;

	i = -6;
	while (i < -1)
	{
		j = -5;
		while (j < 0)
		{
			if (0 < i + MINIMAP_PLAYER_POS && 0 < j + MINIMAP_PLAYER_POS)
			{
				my_mlx_pixel_put(&world->mlx_data.frame_buffer, i + MINIMAP_PLAYER_POS, j + MINIMAP_PLAYER_POS, 0x0);
			}
			j++;
		}
		i++;
	}
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
	render_map_base(world);
	render_map(world);
	render_player(world);

	frame_buffer_apply(&world->mlx_data);
	return (0);
}
