/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor_and_ceiling.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkuramot <tkuramot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 14:15:13 by tkuramot          #+#    #+#             */
/*   Updated: 2023/11/28 14:15:15 by tkuramot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawing.h"
#include "type.h"

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
