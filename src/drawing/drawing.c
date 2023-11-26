/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:48:25 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/27 00:30:50 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "mlx.h"
#include "type.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_frame_buffer *frame_buffer,
				int y, int x, int color)
{
	char	*dst;

	dst = frame_buffer->addr
		+ (y * frame_buffer->line_length
			+ x * (frame_buffer->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

// Top-left is the origin
// start points to top-left of the square and end points to bottom right of it
void	draw_square(t_mlx_data *mlx_data, t_vec2i start, t_vec2i end, int color)
{
	int	x;
	int	y;

	y = start.y;
	while (y <= end.y)
	{
		x = start.x;
		while (x <= end.x)
		{
			my_mlx_pixel_put(&mlx_data->frame_buffer, y, x, color);
			x++;
		}
		y++;
	}
}

void	render_wall_vertical_line(t_mlx_data *mlx_data,
			int x, int line_height, int color)
{
	int	line_start;
	int	line_end;

	line_start = -line_height / 2 + WINDOW_HEIGHT / 2;
	if (line_start < 0)
		line_start = 0;
	line_end = line_height / 2 + WINDOW_HEIGHT / 2;
	if (line_end >= WINDOW_HEIGHT)
		line_end = WINDOW_HEIGHT - 1;
	draw_square(mlx_data,
		(t_vec2i){x, line_start}, (t_vec2i){x, line_end}, color);
}

void	render_floor(t_mlx_data *mlx_data, int color)
{
	draw_square(mlx_data,
		(t_vec2i){0, 0}, (t_vec2i){WINDOW_WIDTH, WINDOW_HEIGHT / 2}, color);
}

void	render_ceiling(t_mlx_data *mlx_data, int color)
{
	draw_square(mlx_data,
		(t_vec2i){0, WINDOW_HEIGHT / 2},
		(t_vec2i){WINDOW_WIDTH, WINDOW_HEIGHT - 1}, color);
}
