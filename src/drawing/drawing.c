/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 01:48:25 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/28 14:17:26 by tkuramot         ###   ########.fr       */
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

unsigned int	extract_color_from_texture(t_texture *texture, int y, int x)
{
	char	*dst;

	dst = texture->addr
		+ (y * texture->line_length
			+ x * (texture->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
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
