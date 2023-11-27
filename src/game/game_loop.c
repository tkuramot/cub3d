/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/26 11:57:49 by tokazaki         ###   ########.fr       */
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


void translucent_my_mlx_pixel_put(t_frame_buffer *frame_buffer,
                                   int x, int y, int color)
{
    char *dst;

    // 画像データの先頭アドレス + y行目 * 1行あたりのバイト数 + xピクセル目 * ピクセルあたりのバイト数
    dst = frame_buffer->addr + (y * frame_buffer->line_length + x * (frame_buffer->bits_per_pixel / 8));

    // 既存の色
    unsigned int *existing_color = (unsigned int *)dst;

    // 新しい色を既存の色に対して重みづけして混ぜる
    int alpha = 200;  // 重みづけの係数 (0から255の範囲で調整可能)
//    int new_red = (color >> 16) & 0xFF;
//    int new_green = (color >> 8) & 0xFF;
//    int new_blue = color & 0xFF;
//
//    int existing_red = (*existing_color >> 16) & 0xFF;
//    int existing_green = (*existing_color >> 8) & 0xFF;
//    int existing_blue = (*existing_color) & 0xFF;
//
//    // 新しい色を既存の色に対して重みづけして混ぜる
//    int blended_red = (existing_red * (255 - alpha) + new_red * alpha) / 255;
//    int blended_green = (existing_green * (255 - alpha) + new_green * alpha) / 255;
//    int blended_blue = (existing_blue * (255 - alpha) + new_blue * alpha) / 255;
//    // ブレンディングされたRGB成分をセット
//    *existing_color = (blended_red << 16) | (blended_green << 8) | blended_blue | (255 << 24);  // アルファは不透明として設定

	*existing_color = \
		(((*existing_color & 0xFF00FF) * (255 - alpha) + (color & 0xFF00FF) * alpha) / 255) +
		((((*existing_color >> 8) & 0xFF) * (255 - alpha) + ((color >> 8) & 0xFF) * alpha) / 255 << 8) +
		(((*existing_color >> 16) * (255 - alpha) + (color >> 16) * alpha) / 255 << 16);
}

#include <math.h>
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

void	render_wall_brock(t_world *world, int i, int j)
{
	int k;
	int l;
	int x;
	int y;

	x = (world->width - world->player.precise_pos.x) * 10;
	y = (world->height - world->player.precise_pos.y) * 10;

	k = 12;
	while (k < 17)
	{
		l = 12;
		while (l < 17)
		{
			if (0 < i + k + x - 100 && 0 < j + l + y -100)
			{
				my_mlx_pixel_put(&world->mlx_data.frame_buffer, i + k + x - 100, j + l + y - 100, 0xFFFFFF);
			}
			l++;
		}
		k++;
	}
}

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

//void translucent_my_mlx_pixel_put(t_frame_buffer *frame_buffer,
//                                   int x, int y, int color)
//{
//    char *dst;
//
//    // 画像データの先頭アドレス + y行目 * 1行あたりのバイト数 + xピクセル目 * ピクセルあたりのバイト数
//    dst = frame_buffer->addr + (y * frame_buffer->line_length + x * (frame_buffer->bits_per_pixel / 8));
//
//    // 既存の色
//    unsigned int *existing_color = (unsigned int *)dst;
//
//    // 新しい色を既存の色と単純に混ぜ合わせる
//    *existing_color = ((*existing_color + color) / 2);
//}


void	render_map_base(t_world *world)
{
	int	i;
	int	j;
	int x;
	int y;

	x = (world->width - world->player.precise_pos.x) * 10;
	y = (world->height - world->player.precise_pos.y) * 10;

	i = 5;
	while (i < world->width * 10 + 15)
	{
		j = 5;
		while (j < world->height * 10 + 15)
		{
			if (0 < i + x - 100 && 0 < j +  y -100)
			{
				translucent_my_mlx_pixel_put(&world->mlx_data.frame_buffer, i + x - 100, j + y - 100, 0xfff462);
			}
			j++;
		}
		i++;
	}
}

//void	render_player(t_world *world)
//{
//	int i;
//	int j;
//	int x;
//	int y;
//
//	x = world->player.precise_pos.x * 10;
//	y = world->player.precise_pos.y * 10;
//	i = 8;
//	while (i < 12)
//	{	
//		j = 8;
//		while (j < 12)
//		{
//			my_mlx_pixel_put(&world->mlx_data.frame_buffer, x + i, y + j, 0x0);
//			j++;
//		}
//		i++;
//	}
//}

void	render_player(t_world *world)
{
	int	i;
	int	j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			my_mlx_pixel_put(&world->mlx_data.frame_buffer, world->width * 10 - 2 + i + 10 - 100, world->height * 10 - 2 + j + 10 - 100, 0x0);
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
//    draw_circle(world, 100, 90, 0xFFFFFF);
//    draw_circle(world, 100, 91, 0xFFFFFF);
//    draw_circle(world, 100, 92, 0xFFFFFF);
//    draw_circle(world, 100, 95, 0xFFFFFF);
	render_player(world);

	frame_buffer_apply(&world->mlx_data);
	return (0);
}
