/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tokazaki <tokazaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 01:04:48 by tokazaki          #+#    #+#             */
/*   Updated: 2023/11/28 13:39:11 by tokazaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constant.h"
#include "type.h"
#include <stdbool.h>

bool	is_in_minimap(int x, int y, int center, int radius)
{
	int	distance_squared;

	if (x < 0 || y < 0)
		return (false);
	distance_squared = (x - center) * (x - center) \
					+ (y - center) * (y - center);
	if (distance_squared <= radius * radius)
		return (true);
	else
		return (false);
}

void	translucent_my_mlx_pixel_put(t_frame_buffer *frame_buffer, \
								int x, int y, int color)
{
	char			*dst;
	unsigned int	*existing_color;
	int				alpha;

	dst = frame_buffer->addr + (y * frame_buffer->line_length + \
								x * (frame_buffer->bits_per_pixel / 8));
	existing_color = (unsigned int *)dst;
	alpha = MINIMAP_TRANSPARENCY;
	*existing_color = \
		(((*existing_color & 0xFF00FF) * (255 - alpha) + \
			(color & 0xFF00FF) * alpha) / 255) + \
		((((*existing_color >> 8) & 0xFF) * (255 - alpha) + \
			((color >> 8) & 0xFF) * alpha) / 255 << 8) + \
		(((*existing_color >> 16) * (255 - alpha) + \
			(color >> 16) * alpha) / 255 << 16);
}
