/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/28 19:38:41 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_H
# define DRAWING_H

# include "type.h"

void			init_mlx_data(t_world *world);
void			frame_buffer_allocate(t_mlx_data *mlx_data);
void			frame_buffer_apply(t_mlx_data *mlx_data);
void			frame_buffer_destroy(t_mlx_data *mlx_data);
void			my_mlx_pixel_put(t_frame_buffer *frame_buffer,
					int y, int x, int color);
unsigned int	extract_color_from_texture(t_texture *texture, int y, int x);
void			draw_square(t_mlx_data *mlx_data,
					t_vec2i start, t_vec2i end, int color);
void			render_floor(t_mlx_data *mlx_data, int color);
void			render_ceiling(t_mlx_data *mlx_data, int color);
void			render_wall_vertical_line(t_mlx_data *mlx_data,
					int x, int line_height, int color);
t_texture		*get_side_texture(t_world *world, t_dda *dda);
void			calculate_line(t_wall_line *line, t_dda *dda);
void			calculate_texture_position(t_wall_line *line, t_world *world,
					t_dda *dda, t_texture *texture);
void			render_textured_wall_vertical_line(t_world *world,
					t_texture *texture, t_wall_line *line, int window_x);
void			render_minimap(t_world *world);
bool			is_in_minimap(int x, int y, int center, int radius);
void			translucent_my_mlx_pixel_put(t_frame_buffer *frame_buffer, \
								int x, int y, int color);

#endif
