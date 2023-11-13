/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:48:25 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/13 22:50:10 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "type.h"
#include <stdio.h>

static void	my_mlx_pixel_put(t_frame_buffer *frame_buffer, int x, int y, int color)
{
	char	*dst;

	dst = frame_buffer->addr + (y * frame_buffer->line_length + x * (frame_buffer->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// Top-left is the origin
// start points to top-left of the square and end points to bottom right of it
void	draw_square(t_world *world, t_vec2i start, t_vec2i end, int color)
{
	t_frame_buffer frame_buffer;
	int	x;
	int	y;

	frame_buffer.img = mlx_new_image(world->mlx_data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	frame_buffer.addr = mlx_get_data_addr(frame_buffer.img, &frame_buffer.bits_per_pixel, &frame_buffer.line_length, &frame_buffer.endian);
	y = start.y;
	while (y <= end.y)
	{
		x = start.x;
		while (x <= end.x)
		{
			my_mlx_pixel_put(&frame_buffer, x, y, color);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(world->mlx_data.mlx, world->mlx_data.mlx_win, frame_buffer.img, 0, 0);
}

void	render_wall_vertical_line(t_world *world, int x, int line_height, int color)
{
	int	line_start;
	int	line_end;

	line_start = -line_height / 2 + WINDOW_HEIGHT / 2;
	if (line_start < 0)
		line_start = 0;
	line_end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (line_end >= WINDOW_HEIGHT)
		line_end = WINDOW_HEIGHT - 1;
	draw_square(world, (t_vec2i){x, line_start}, (t_vec2i){x, line_end}, color);
}
