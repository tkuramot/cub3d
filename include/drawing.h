/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:11 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/15 13:08:17 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_H
# define DRAWING_H

# include "type.h"

void	init_mlx_data(t_mlx_data *mlx_data);
void	frame_buffer_allocate(t_mlx_data *mlx_data);
void	frame_buffer_apply(t_mlx_data *mlx_data);
void	frame_buffer_destroy(t_mlx_data *mlx_data);
void	draw_square(t_mlx_data *mlx_data,
			t_vec2i start, t_vec2i end, int color);
void	render_wall_vertical_line(t_mlx_data *mlx_data,
			int x, int line_height, int color);

#endif
