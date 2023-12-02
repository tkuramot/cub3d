/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:18:10 by tkuramot          #+#    #+#             */
/*   Updated: 2023/12/02 14:11:15 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawing.h"
#include "type.h"
#include <stdlib.h>
#include <math.h>

void	calculate_line(t_wall_line *line, t_dda *dda)
{
	line->line_height = (int)(WINDOW_HEIGHT / dda->dist_camera_plane_to_wall);
	line->line_start = -line->line_height / 2 + WINDOW_HEIGHT / 2;
	if (line->line_start < 0)
		line->line_start = 0;
	line->line_end = line->line_height / 2 + WINDOW_HEIGHT / 2;
	if (line->line_end >= WINDOW_HEIGHT)
		line->line_end = WINDOW_HEIGHT - 1;
}

void	calculate_texture_position(t_wall_line *line, t_world *world,
			t_dda *dda, t_texture *texture)
{
	double	wall_x;

	if (dda->hit_side == WEST || dda->hit_side == EAST)
		wall_x = world->player.precise_pos.y
			+ dda->dist_camera_plane_to_wall * dda->ray_dir.y;
	else
		wall_x = world->player.precise_pos.x
			+ dda->dist_camera_plane_to_wall * dda->ray_dir.x;
	wall_x -= floor(wall_x);
	line->texture_x = (int)(wall_x * (double)texture->width);
	if (dda->hit_side == NORTH || dda->hit_side == EAST)
		line->texture_x = texture->width - line->texture_x - 1;
	line->step = 1.0 * texture->height / line->line_height;
	line->temp_texture_y = (int)(line->line_start - WINDOW_HEIGHT / 2
			+ line->line_height / 2) * line->step;
}

void	render_textured_wall_vertical_line(t_world *world, t_texture *texture,
			t_wall_line *line, int window_x)
{
	int				window_y;
	unsigned int	color;

	window_y = line->line_start;
	while (window_y < line->line_end)
	{
		line->texture_y = (int)fmod(line->temp_texture_y, texture->height - 1);
		line->temp_texture_y += line->step;
		color = extract_color_from_texture(texture,
				line->texture_y, line->texture_x);
		my_mlx_pixel_put(&world->mlx_data.frame_buffer,
			window_x, window_y, color);
		window_y++;
	}
}

t_texture	*get_side_texture(t_world *world, t_dda *dda)
{
	if (dda->hit_side == NORTH)
		return (&world->mlx_data.textures[NORTH]);
	else if (dda->hit_side == SOUTH)
		return (&world->mlx_data.textures[SOUTH]);
	else if (dda->hit_side == WEST)
		return (&world->mlx_data.textures[WEST]);
	else if (dda->hit_side == EAST)
		return (&world->mlx_data.textures[EAST]);
	else
		return (NULL);
}
